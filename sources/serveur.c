
#include "../headers/serveur.h"
#include "../headers/requete.h"
#include "../headers/function.h"
#include "../headers/type.h"
#include "../headers/parsingDocument.h"


void endChild()
// Attend la mort des fils pour éviter tout processus
{
    wait(NULL);
}

void serveur(int noPort)
{
    // Crée le socket d'écoute
    int socketEcoute;
    if ((socketEcoute = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr, "Erreur de socket\n");
        exit(-1);
    }
    int option = 1;

    // Permet de réutiliser une adresse ayant déjà été utilisée à l'exécution précedente
    setsockopt(socketEcoute, SOL_SOCKET, SO_REUSEADDR, &option,sizeof(option));

    // Initialisation du port s (socket Client pour la communication)
    struct sockaddr_in *s = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
    s->sin_family = AF_INET;
    s->sin_addr.s_addr = htonl(INADDR_ANY);
    s->sin_port = htons(noPort);
    // Peut etre initialiser s.sin_zero

    // On cast le pointeur s en passant de sockaddr_in à sockaddr
    const struct sockaddr *sConverti = (const struct sockaddr *) s;


    // Attachement de la socket avec bind pour dire au processus que c'est cette socket qu'il utilisera
    if (bind(socketEcoute, sConverti, sizeof(const struct sockaddr)) == -1)
    {       
        perror("Erreur de bind");
        exit(-1);
    }

    // On met la socket sur ecoute
    if (listen(socketEcoute, 10) == -1)
    {
        fprintf(stderr, "Erreur de listen\n");
        exit(-1);
    }

    // Boucle infinie pour les fils

    int nbLigne = nb_lignes("bibliotheque.txt");
            
    information tab[nbLigne];
    
    
    extraire_info("bibliotheque.txt", tab);

    
    while (1)
    {
        printf("La rentre dans la boucle \n");

         // ALED LEO JE COMPREND PAS
        socklen_t len = sizeof(sConverti);
        struct sockaddr_in *socketClientConverti = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
        struct sockaddr *infoClient = (struct sockaddr *)socketClientConverti;

        int socketClient;
        printf("la je me bloque sur accept\n");

        if ((socketClient = accept(socketEcoute, infoClient, &len)) == -1)
        {
            /* 
                -------------------WARNING--------------------
                !!!!!!!!!!!!! ACCEPT EST BLOQUANT !!!!!!!!!!!!
            */
            perror("Erreur accept");
            exit(-1);
        }
        
        // Si il y a acceptation de la communication, on crée le fils
        
        switch(fork())
        {
        case -1:
            fprintf(stderr, "Erreur fork");
            exit(-1);


        /*  
            (1) On ferme le socket qu'on utilise pas aka la socket d'écoute
            (2) On se bloque sur un read en attendant la requete du client
                On récupère le message et on renvoie ce qu'il faut
        */
        case 0:
            close(socketEcoute); // (1)

            int numRequete;
            read(socketClient, &numRequete, sizeof(int)); // (2)
            printf("%d\n", numRequete);

            // Envoi accuse de reception vers le client
            int bienRecu = 1;    
            if(write(socketClient, &bienRecu, sizeof(int)) == -1){
                perror("Probleme avec write");
                exit(-1);
            }

            char messageRecu[TAILLE_REQUETE_MAX];
            printf("La je me bloque sur le read\n");
            read(socketClient, messageRecu, TAILLE_REQUETE_MAX); // (2)

            printf("Le message reçu est : %s\n", messageRecu);


            int n = nombreMotClefs(messageRecu);
            char** motsClefs = malloc(sizeof(char*) * n);
            extraireRequete(motsClefs, messageRecu);
        
            
            messageRecu[3] = '\0';
            char messageAEnvoyer[TAILLE_REQUETE_MAX];

            requete1(motsClefs, tab, messageAEnvoyer, "bibliotheque.txt");

            printf("%s\n", messageAEnvoyer);

            if(write(socketClient, messageAEnvoyer, strlen(messageAEnvoyer)) == -1){
                perror("Probleme avec write");
                exit(-1);
            }
            exit(0);

        default:
            close(socketClient);
            struct sigaction signalChild;

            //endChild: gestionnaire des signaux (voir description dans la fonction)
            signalChild.sa_handler = endChild;
            //flag SA_RESTART: empeche l'arrêt de accept() lorsque le gestionnaire s'execute 
            signalChild.sa_flags = SA_RESTART;

            sigaction(SIGCHLD, &signalChild, NULL);
        }
    }
}
