#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[2000]; 
    fgets(text,2000,stdin);
    int n1=strlen(text);
    char * text1="monsieur jack, vous dactylographiez bien mieux que votre ami wolf";
    char alpha[26];
    int n2=strlen(text1);
    for (int i=0;i<n2;i++)
    {
        int v=text[i]-97;
        alpha[v]=text1[i];
    }
    for( int i=0; i<n1;i++)
    {
        int w=text[i]-97;
        if (w>=0 && w<=25)
        {
            printf("%c",alpha[w]);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
