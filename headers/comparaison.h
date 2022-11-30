#ifndef COMPARAISON_H
#define COMPARAISON_H


#include"../headers/requete.h"
#include "type.h"

//renvoie vrai si le motclef est contenu dans la phrase
int comparaison(char* motClef, char* Phrase);

void triAlphabetique(information* tab, int nbLignes);

#endif