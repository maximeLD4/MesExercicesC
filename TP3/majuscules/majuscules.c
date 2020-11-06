#include<stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n=strlen(argv[2]);
    for (int i=1;i<argc; i++)
    {
        int n=strlen(argv[i]);
        for (int j=0;j<n;j++)
        {
            int c=argv[i][j];
            if (c>=97 && c<=122)
            {
                printf("%c",c-32);
            }
            else
            {
                printf("%c",argv[i][j]);
            }
            
        }
        printf("\n");
    }
}
