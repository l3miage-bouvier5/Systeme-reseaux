#ifndef TYPE_H
#define TYPE_H

#define TAILLE_MAX 20
#define TAILLE_REQUETE_MAX 1000
#define TAILLE_TITRE_MAX 150 

typedef struct info {
    char *reference;
    char *genre;
    char *auteur;
    char *titre;
    char *page;
    char appreciation;
} information;


#endif