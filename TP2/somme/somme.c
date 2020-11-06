#include<stdio.h>

int main(void)
{
    long n;
    scanf("%li",&n);
    long compteur=0;
    for (long i=0;i<=n;i++)
    {
        compteur+=i;
    }
    printf("%li\n", compteur);
}