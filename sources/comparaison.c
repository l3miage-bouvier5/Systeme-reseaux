#include "../headers/comparaison.h"

// Renvoie vrai si le motclef est contenu dans la phrase
int comparaison(char* motClef, char* Phrase){

    int n = nombreMotClefs(Phrase);

    char** tabMot = malloc(sizeof(char*) * n);

    extraireRequete(tabMot,Phrase);

    // Parcours la phrase et compare chaque mot avec le motclef
    int i = 0;
    while(i < n ){
        if(strcmp(motClef,tabMot[i]) == 0){
            return 1;
        }
        i++;
    }

    return 0;
}


void triAlphabetique(information* tab, int nbLignes){
    int i = 0;
    int j = 0;
    information temp;
    temp.auteur = malloc(sizeof(char) * TAILLE_MAX);
    temp.genre = malloc(sizeof(char) * TAILLE_MAX);
    temp.page = malloc(sizeof(char) * TAILLE_MAX);
    temp.titre = malloc(sizeof(char) * TAILLE_TITRE_MAX);
    temp.reference = malloc(sizeof(char) * TAILLE_MAX);

    for (i = 0; i < nbLignes - 1; i++){
        for (j = i + 1; j < nbLignes; j++){
            if(strcmp(tab[i].auteur, tab[j].auteur) > 0){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}


