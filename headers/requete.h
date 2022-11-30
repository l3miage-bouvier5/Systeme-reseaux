#ifndef REQUETE_H
#define REQUETE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"


//Renvoie le nombre de mots d'une chaine de caractère
int nombreMotClefs(char* motsClefs);

//Met les mots de la châine de cractère dans un tableau 
void extraireRequete(char** tab,char* motsClefs);



#endif