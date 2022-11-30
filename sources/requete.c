#include"../headers/requete.h"



//Renvoie le nombre de mots d'une chaine de cractère
int nombreMotClefs(char* motsClefs){
    char c;
    int i = 0;
    int res = 1;
    while((c = motsClefs[i]) != '\0'){
        if(c == ' '){
            res++;
        }
        i++;
    }
    return res;
}    



//Met les mots de la châine de cractère dans un tableau 
void extraireRequete(char** tab,char* motsClefs){
    char c;
    int i = 0;
    int j = 0;
    int idexMotsClefs = 0;
    tab[i] = malloc(sizeof(char) * TAILLE_MAX);
    while((c = motsClefs[idexMotsClefs]) != '\0'){
        if(c == ' '){
            tab[i][j] = '\0';
            i++;
            tab[i] = malloc(sizeof(char) * TAILLE_MAX);
            j = 0;
        }else{
            tab[i][j] = motsClefs[idexMotsClefs];
            j++;
        }
        idexMotsClefs++;   
    }
    tab[i][j] = '\0';
}











