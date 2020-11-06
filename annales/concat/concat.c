#include "concat.h"
#include "tps_unit_test.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * concat(char * chaine1,char * chaine2)
{
    int n=strlen(chaine1);
    int m=strlen(chaine2);
    char * str=malloc((n+m+1)*sizeof(char));
    if (str==NULL)
    {
        return NULL;
    }
    int i=0;
    while (chaine1[i]!='\0')
    {
        str[i]=chaine1[i];
        i++;
    }
    int j=0;
    while (chaine2[j]!='\0')
    {
        str[j+i]=chaine2[j];
        j++;
    }
    str[j+i]='\0';

    return str;
}