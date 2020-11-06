#include<stdio.h>
#include<math.h>

int main(void)
{
    int n;
    scanf("%i",&n);
    if (n==0)
    {
        printf("1");
        return(0);
    }
    for( int j=0; j<sqrt(n);j++)
    {
        if (n==(j*j)+1)
        {
            printf("PARFAIT\n");
            return(0);
        }
    }
    for (int i=n+1;i<(n*n);i++)
    {
        for (int p=0;p<sqrt(i);p++)
        {
            if(i==(p*p)+1)
            {
                printf("%i\n",i);
                return(0); 
            }
        }
    }
}