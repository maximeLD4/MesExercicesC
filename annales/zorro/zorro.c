#include <stdio.h>




int main(void)
{
    int n;
    scanf("%i",&n);
    if (n<2)
    {
        printf("IMPOSSIBLE") ;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            printf("_");
        }
        printf("\n");
        for(int j=0;j<n-1;j++)
        {
            for(int k=0;k<n-j-1;k++)
            {
                printf(" ");
            }
            printf("/\n");
        }
        printf("/");
        for (int p=0;p<n-1;p++)
        {
            printf("_");
        }
        printf("\n");
    }
}