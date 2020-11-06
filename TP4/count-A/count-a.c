#include<stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        return(42);
    }
    else{
        int n=strlen(argv[argc-1]);
        int k;
        int compteur=0;
        for (k=0; k<=n; k++){
            
            if(argv[1][k]=='A'){
                compteur+=1;
        }
    }
    printf("%i \n",compteur);
    }
return(0);
}


/*


int main(void){
    int compteur=0;
    char c='c';
    while(c!='\n'){
        c=getchar();
        if (c=='A'){
            compteur+=1;
        }
    }
printf("%i \n",compteur);
return (compteur);
}
*/