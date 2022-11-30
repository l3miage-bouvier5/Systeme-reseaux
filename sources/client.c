
// Demande ensuite les mots cles pour le traite
#include "../headers/client.h"



void client(int noPort){
    // Definition du socket port
    printf("La je créer la socket\n");
    int port = socket(AF_INET, SOCK_STREAM, 0);
    if(port == -1){
        perror("Erreur creation du port...");
        exit(1);
    }
    printf("Socket depuis client: %d\n", port);

    // Definition des variables hote (=> infos hote) et soc (=> infos communication)
    struct hostent* hote = (struct hostent*)malloc(sizeof(struct hostent));
    struct sockaddr_in* soc = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));
    hote = gethostbyname("f203-05");
    
    char* h_addr;
    h_addr = hote->h_addr_list[0];
    
    
    
    soc->sin_family = AF_INET;
    memcpy(&soc->sin_addr.s_addr, h_addr, sizeof(int));
    soc->sin_port = htons(noPort);


    const struct sockaddr* socConv = (const struct sockaddr*) soc;

    // Etablissement de la connection
    int co = connect(port, socConv, sizeof(struct sockaddr));
    printf("Port du serveur pour parler : %d\n", soc->sin_port);
    if(co == -1){
        perror("Erreur de connection");
        exit(1);
    }

    // Si il n'y a pas d'erreur:
    // On demande le type de requete a effectuer
    int numRequete;
    demandeNumero(&numRequete);
    if(write(port, &numRequete, sizeof(int)) == -1 ){
        perror("Probleme avec write");
        exit(-1);
    }

    // Accuse de reception de la reponse a la demande
    int bienRecu;
    read(port, &bienRecu, sizeof(int));
    if(bienRecu != 1){
        fprintf(stderr, "Probleme de reception du premier message ");
        exit(-1);
    }

    // Maintenant, on demande les mots cles de la requete a l'utilisateur
    char requeteComplete[TAILLE_REQUETE_MAX];
    demandeRequete1(requeteComplete);
    printf("%s\n",requeteComplete);

    // La reponse a la demande est envoyee au serveur
    if(write(port, requeteComplete, strlen(requeteComplete)) == -1){
        perror("Erreur de write client");
        exit(-1);   
    }

    // Accuse de reception de la reponse a la demande
    printf("La je me bloque sur le read\n");
    char messageADisplay[TAILLE_REQUETE_MAX];
    read(port, messageADisplay, TAILLE_REQUETE_MAX);
    printf("Lecture: %s\n", messageADisplay);
   
}

// Demande a l'utilisateur quel type de requete il souhaite effectuer
void demandeNumero(int *numRequete){
    printf("---------------------------------------------\n");
    printf("               MENU SELECTION\n");
    printf("---------------------------------------------\n\n");
    printf("Quel type de requete voulez vous faire ? ");
    scanf("%d", numRequete);
}

// Demande ensuite les mots cles pour le traitement de la requete
// Le traitement est effectue par le serveur
void demandeRequete1(char* requeteComplete){
    printf("---------------------------------------------\n\n");
    printf("Entrez la référence que vous voulez : ");
    scanf("%s", requeteComplete);
    printf("%ld\n",strlen(requeteComplete));

    for (int i = 0 ; i < strlen(requeteComplete); i++){
        if(requeteComplete[i] == '\n'){
            requeteComplete[i] = '\0';
        }
    }
}

