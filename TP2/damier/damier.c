#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d",&n);
    for (int k=0;k<n;k++)
    {
        if (k%2==0)
        {
            for (int r=0;r<n;r++)
            {
                if (r%2==0)
                {
                    printf("#");
                }
                else if (r%2==1)
                {
                    printf(".");
                }

            }
        }
        else if (k%2==1)
        {
            for (int r=0;r<n;r++)
            {
                if (r%2==1)
                {
                    printf("#");
                }
                else if (r%2==0)
                {
                    printf(".");
                }
            }
        }
        printf("\n");
    }
}