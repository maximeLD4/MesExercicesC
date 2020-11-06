#include <stdlib.h>
#include<stdio.h>

int main(void)
{
    int *nbr=malloc(sizeof(int));
    int *min=malloc(sizeof(int));
    int *max=malloc(sizeof(int));
    int *test=malloc(sizeof(int));
    scanf("%i",nbr);
    scanf("%i",min);
    scanf("%i",max);
    for (int i=0; i<*nbr; i++)
    {
        scanf("%i",test);
        if (*test<*min || *test>*max)
        {  
            printf("Alerte !!\n");
            free(test);
            free(max);
            free(min);
            free(nbr);
            return 0;
        }
        else
        {
            printf("Rien à signaler\n");
        }
    }
    free(test);
    free(max);
    free(min);
    free(nbr);
    return 0;
}
