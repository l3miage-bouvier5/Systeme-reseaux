#ifndef PARSING_DOCUMENT_H
#define PARSING_DOCUMENT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "requete.h"

#include "type.h"

#define TAILLE_MAX 20

#define TAILLE_REQUETE_MAX 1000


void extraire_info(char *fichier, information tableau_info[]);
void decoupePhraseHashtag(char** tab, char* phrase);
int nb_lignes(char *fichier);



#endif