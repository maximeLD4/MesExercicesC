#include "parser.h"
#include "calc-io.h"
#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    char calcul[20];
    fgets(calcul,20,stdin);
    double a, b;
    char op;
    if (parse(calcul, &a, &b, &op)==PARSE_OK)
    {
        printResult(a,b,op);
    }
}