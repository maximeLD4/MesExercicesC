#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc==1)
    {
        char text[50000];
        fgets(text,50000,stdin);
        int n;
        scanf("%i",&n);

        if(n<0)
        {
            int i=strlen(text)-1;
            while (i!=-1)
            {
                for(int j=0; j<-n;j++)
                {
                    printf("%c",text[i]);
                }
                i--;
            }
            printf("\n");
        }
        else
        {
            int i=0;
            while (text[i]!='\n')
            {
                for(int j=0; j<n;j++)
                {
                    printf("%c",text[i]);
                }
                i++;
            }
            printf("\n");
        }
    }
    else
    {
        int n2=atoi(argv[argc-1]);
        if(n2<0)
        {
            int i2=strlen(argv[1])-1;
            while (i2!=-1)
            {   
                for(int j2=0; j2<(-n2);j2++)
                {
                    printf("%c",argv[1][i2]);
                }
                i2--;
            }
            printf("\n"); 
        }
        else
        {       
            int i2=0;
            while (argv[1][i2]!='\0')
            {   
                for(int j2=0; j2<n2;j2++)
                {
                    printf("%c",argv[1][i2]);
                }
                i2++;
            }
            printf("\n");
        }
    }
}