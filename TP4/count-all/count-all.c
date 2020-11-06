#include<stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        return(42);
    }
    else{
        int const1;
        int const2=strlen(argv[argc-1]);
        int Liste[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(const1=0; const1<const2;const1++){
            int indx=argv[1][const1];
            if(64<indx && indx<91){
                Liste[indx-65]=Liste[indx-65]+1;
            }
            else if(96<indx && indx<123){
                Liste[indx-97]=Liste[indx-97]+1;
            }
        }
    for(int const3=0;const3<26;const3++){
        printf("%c:%i\n", const3+97,Liste[const3]);
    }
    }
}
