#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    long  n;
    scanf("%ld",&n);
    long  lan=n*(n+1)/2;
    long  L[lan];
    long  k=0;
    for(long  i=0; i<n; i++)
    {
        for(long  j=0;j<i+1;j++)
        {
            scanf("%ld",&L[k]);
            if (L[k]!=' ')
            {
                k++;
            }
            else if(L[k]==' ')
            {
                j--;
            }
            else if(L[k]=='\n')
            {
                j=i+1;
            }
        }
    }
    for (long  j=n;j>1;j--)
    {
        for(long  i=(j*(j+1)/2)-j-(j-1);i<(j*(j+1)/2)-j;i++)
        {
            if (L[i+j-1]+L[i]>L[i+j]+L[i])
            {
                 L[i]+=L[i+j-1];
            }
            else
            {
                 L[i]+=L[i+j];
            }
        }
    }
    printf("%ld \n",L[0]);
}