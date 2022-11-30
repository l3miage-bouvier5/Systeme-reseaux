#ifndef FUNCTION_H
#define FUNCTION_H

#include "comparaison.h"
#include "type.h"
#include "requete.h"

int nb_lignes(char *fichier);

void requete1(char** motsClef, information* lignes, char* affichage, char* nomFichier);
void requete2(char** motsClef, information* lignes, char* affichage, char* fichier);


#endif