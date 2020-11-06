#include<stdio.h>
#include <string.h>

int main(void){
    char text[10];
    fgets(text,10,stdin);
    int k;
    int n=strlen(text);
    int compteur=0;
    for (k=0; k<n; k++){
        if(text[k]=='A'){
            compteur+=1;
        }
    }
    printf("%i \n",compteur);
    return(0);
}

