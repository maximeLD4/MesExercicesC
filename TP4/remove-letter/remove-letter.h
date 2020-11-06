#include <stdio.h>
#include <string.h>

void removeLetter(char *texte, char lettre){ 
    int i=0;
    int k=0;
    while(texte[i]!='\0'){
        if (texte[i]!= lettre){
            texte[k]=texte[i];
            k+=1;
        }
        i+=1;
    }
    texte[k]='\0';
}

/*
CORRECTION 

void removeLetter(char *texte, char lettre){
    char *writer = texte;
    while (*texte != '\0'){
        if (*texte != lettre){
            writer++;
        }
        texte++;
        *writer = *texte;
    }
}
*/