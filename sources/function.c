#include "../headers/function.h"

// requete 1:
/*soumettre une référence et obtenir l'affichage des informations associées au livre
concerné : nom de l'auteur, titre du livre, et genre. On affichera également le message
"Moins de 300 pages" ou "Plus de 300 pages" selon le nombre de pages du livre.
Mais attention aussi à ce que le client soit en mesure de délivrer à l'utilisateur un
message clair dans le cas où la référence demandée n'existe pas (quel choix efficace
ferez-vous pour ce qui sera renvoyé au client ?). */






void requete1(char** motsClef, information* lignes, char* affichage, char* nomFichier){
    // entree reference
    information info;


   
    char* ref = motsClef[0];
    
   
    int n = nb_lignes(nomFichier);  
    // sortie affichage: nom auteur, titre livre, genre,  Moins/Plus de 300 pages
    int i = 0; 
    

    while (i < n && !comparaison(ref, lignes[i].reference)){
        i++;
    }
    
    if (i < n){
        info = lignes[i];
        strcat(strcpy(affichage, "Auteur : ") ,lignes[i].auteur);
        strcat(affichage,"\nTitre : ");
        strcat(affichage, lignes[i].titre);

        strcat(affichage, "\nGenre : ");
        strcat(affichage, lignes[i].genre);
        if (strtol(info.page,NULL,10) >= 300){
            strcat(affichage,"\nPlus");
        }else{
            strcat(affichage,"\nMoins");
        }
        strcat(affichage," de 300 pages\n");
    }else{
        strcpy(affichage, "Référence inconnue dans notre bibliotheque, désolé le sang\n");
    }
}


/*

void requete3(char* motsClef, information* tableau_info, char* affichage){

    //ligne informations
    information info;

    //on regarde si la taille de motsClef est égale à deux.
    if(nombreMotClefs(motsClef) != 2){
        perror("Erreur nb. arguments requete3");
        exit(-1);
    }

    //on cherche la ou les lignes de tableau_info où le nom de l'auteur figure et on les conserve.
    int n = nb_lignes("bibliotheque.txt");
    information* correspondance_auteur;
    int index_correspondance = 0;

    for(int i=0; i<n; i++){
        info = tableau_info[i];

        if(comparaison(motsClef[0], info.auteur) == 1){
            correspondance_auteur[index_correspondance] = info;
            index_correspondance++;
        }
    }    

    //si on obtient des lignes, on regarde celle ou le genre littéraire est le bon.
    information* correspondance_genre;
    int index_cor_final = 0;

    for(int j=0; j<=index_correspondance; j++){
        if(comparaison(motsClef[1], correspondance_auteur[j].genre) == 1){
            correspondance_genre[index_cor_final] = correspondance_auteur[j];
            index_cor_final++;
        }
    }
    
    //affichage des informations recherchées
    for(int k=0; k<=index_cor_final; k++){
        strcat(strcpy(affichage, "Référence: "), correspondance_genre[k].auteur);
        strcat(affichage, strcat("\nTitre: ", correspondance_genre[k].titre));
    }
}

void requete2(char** motsClef, information* lignes, char* affichage, char* fichier){
    // entree : 1 ou des mots cles

    int n = nb_lignes(fichier);
    information tabInfo[n];

    affichage = "";
    int index = 0;
    

    // Ajout des lignes dans tabInfo selon les mots clefs
    for(int j = 0; j < n; j++){
            
        int ajout = 0;
        int i = 0;
            
         while (i < nombreMotClefs(motsClef) && ajout != 1){
                
            if(comparaison(motsClef[i],lignes[j].titre)){
                ajout = 1;
                tabInfo[index] = lignes[j];
                index++;
            }
            i++;
        }        
            
    }

    

    for(int i =0; i < index; i++){
        affichage = strcat("Référence : ",tabInfo[index].reference);
        strcat(affichage,strcat("\nAuteur : ",tabInfo[index].auteur));
        strcat(affichage,strcat("\nTitre : ",tabInfo[index].titre));
        strcat(affichage,strcat("\nGenre : ",tabInfo[index].genre)); 
    }

}*/

/*

void requete4(char** motsClef, information* lignes, char* nomFichier){
    int i = 0;

    while(i < nb_lignes(nomFichier)){

        if(comparaison(motsClef,lignes[i].auteur)){

        }

        i++;
    }
}*/


