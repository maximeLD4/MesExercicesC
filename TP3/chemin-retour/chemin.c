#include<stdio.h>

int main(void)
{
    int n;
    scanf("%i",&n);
    int L[n];
    for (int i=0; i<n; i++)
    {
        int mouv;
        scanf("%i",&mouv);
        L[i]=mouv;
    }
    for (int j=n;j>0;j--)
    {
        int mouv2= L[j-1];
        if (mouv2==3)
        {
            printf("%i\n",L[j-1]);
        }
        else if(mouv2==1 || mouv2==2)
        {
            printf("%i\n", (mouv2%2)+1);
        }
        else if(mouv2==4)
        {
            printf("5\n");
        }
        else if( mouv2==5)
        {
            printf("4\n");
        }
    }
}