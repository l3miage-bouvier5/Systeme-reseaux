#include "../headers/parsingDocument.h"



void extraire_info(char *fichier, information tableau_info[])
{
    // Declaration du fichier a parser 
    FILE *f;

    // Recuperation du nombre de lignes du fichier
    int n = nb_lignes(fichier);


    tableau_info[0].auteur = "Balzac";

    // Ouvre le fichier en mode lecture
    if ((f = fopen(fichier, "r")) == NULL)
    {
        perror("Ouverture fichier");
        exit(-1);
    }
    // Allocation memoire pour une ligne de taille max predefinie
    char *ligne = malloc(sizeof(char) * TAILLE_REQUETE_MAX);
    
    
    // Pour chaque ligne...
    for(int indexLigne = 0; indexLigne < n; indexLigne++)
    {   
        // ...on obtient son contenu
        fgets(ligne, TAILLE_REQUETE_MAX, f);

        // ce qui nous donne une chaîne de caracteres
        char** tab = malloc(sizeof(char*)*6);

        // decomposee par cette fonction dont le fonctionnement
        // est indique plus bas
        decoupePhraseHashtag(tab, ligne);
        
        // Allocation espace memoire d'un champs pour chaque information d'une ligne
        tableau_info[indexLigne].reference = malloc(sizeof(char) * TAILLE_MAX);
        tableau_info[indexLigne].auteur = malloc(sizeof(char) * TAILLE_MAX);
        tableau_info[indexLigne].titre = malloc(sizeof(char) * TAILLE_TITRE_MAX);
        tableau_info[indexLigne].genre = malloc(sizeof(char) * TAILLE_MAX);
        tableau_info[indexLigne].page = malloc(sizeof(char) * TAILLE_MAX);

        // Remplissage d'une structure 
        strcpy(tableau_info[indexLigne].reference, tab[0]);
        strcpy(tableau_info[indexLigne].auteur, tab[1]);
        strcpy(tableau_info[indexLigne].titre, tab[2]);
        strcpy(tableau_info[indexLigne].genre, tab[3]);
        strcpy(tableau_info[indexLigne].page, tab[4]);

        // Une fois la structure remplie, elle est ajoutee au tableau
        // repertoriant chaque ligne d'information de bibliotheque.txt
        tableau_info[indexLigne].appreciation = tab[5][0];

        /*
            Ce tableau nous sert pour le traitement des requetes,
            notamment pour les comparaisons des mots cles avec les elements
            des lignes de bibliotheques.txt qui sont dans un format
            structure facilement exploitable.
        */
    }
    
    
  
    fclose(f);
}

/*
    Compte le nombre de lignes du fichier donnée par en parametres.
    ATTENTION : ne fonctionne pas si le fichier est vide : ça renvoie 1
*/
int nb_lignes(char *fichier)
{
    FILE *f;
    f = fopen(fichier, "r");
    if (f == NULL)
    {
        return 0;
    }
    char c, c2;
    int n = 0;
    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n')
        {
            n++;
        }
        c2 = c;
    }
    if (c2 != '\n')
    {
        if (n != 0)
            n++;
    }

    fclose(f);
    return n;
}

/*
    Decoupe chaque ligne du fichier bibliotheque.txt en utilisant le separateur '#'.
    Chaque ligne est transformee en une structure de type information, contenant 6 champs,
    un pour chaque information (auteur, titre...).
*/
void decoupePhraseHashtag(char** tab, char* phrase){
    char c;
    int i = 0;
    int j = 0;
    int idexMotsClefs = 0;
    tab[i] = malloc(sizeof(char) * TAILLE_TITRE_MAX);
    while((c = phrase[idexMotsClefs]) != '\0'){
        if(c == '#'){
            i++;
            tab[i] = malloc(sizeof(char) * TAILLE_TITRE_MAX);
            j = 0;
        }else{
            tab[i][j] = phrase[idexMotsClefs];
            j++;
        }
        idexMotsClefs++;   
    }
}
