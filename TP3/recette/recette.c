#include <stdio.h>

int main(void)
{
    int L[]={9, 5, 12, 15, 7, 42, 13, 10, 1 , 20};
    int prixfinal=0;
    for(int i=0; i<10; i++)
    {
        int quantity;
        scanf("%d",&quantity);
        prixfinal+=L[i]*quantity;
    }
    printf("%i",prixfinal);
}