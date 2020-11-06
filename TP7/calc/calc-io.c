#include <stdlib.h>
#include <stdio.h> 
#include <math.h>
void printResult(double a, double b, char op)
{
    double somme;
    double p=pow(a,b);
    switch(op)
    {
        case('+'):
            printf("%lf %c %lf = %lf\n",a,op,b,a+b);
            break;
        case('-'):
            printf("%lf %c %lf = %lf\n",a,op,b,a-b);
            break;
        case('*'):
            printf("%lf %c %lf = %lf\n",a,op,b,a*b);
            break;
        case('/'):
            printf("%lf %c %lf = %lf\n",a,op,b,a/b);
            break;
        case('^'):
            printf("%lf %c %lf = %lf\n",a,op,b,p);
            break;
    }        
}