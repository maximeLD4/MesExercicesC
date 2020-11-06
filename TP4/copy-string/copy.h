#include<stdio.h>

void copy(char *ch1, char **ch2){
 /*   int n=sizeof(ch1);
    int *ch2=malloc(n);
    for(int i=0;i<n;i++){
        (*ch2)[i]=ch1[i];
    }
*/
strcpy(ch2, ch1);

}