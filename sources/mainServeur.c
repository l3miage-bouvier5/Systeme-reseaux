#include "../headers/serveur.h"
#include "../headers/comparaison.h"
#include "../headers/parsingDocument.h"
#include "../headers/type.h"
#include "../headers/function.h"
#include "../headers/requete.h"


int main(int argc, char** argv){
    
    int nbLignes = nb_lignes("bibliotheque.txt");
    information tabInfo[nbLignes];

    extraire_info("bibliotheque.txt", tabInfo);

    triAlphabetique(tabInfo, nbLignes);

    return 0;
}