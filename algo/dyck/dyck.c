#include<stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        return(2);
    }
    int n=strlen(argv[argc-1]);
    int k;
    int compteur=0;
    for (k=0; k<n; k++){
        if(argv[1][k]=='('){
            compteur+=1;
        }
        if(argv[1][k]==')'){
            compteur-=1;
        }
    }
    if (!compteur){
        return(0);
    }
    else{
        return(1);
    }
    return(0);
}
