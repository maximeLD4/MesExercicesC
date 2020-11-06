#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include"parser.h"

int parse(const char * line, double *a, double *b, char *op)
{
    int nb_val_lues=sscanf(line,"%lf %c %lf", a,op,b);
    if (nb_val_lues != 3) 
    {
        return PARSE_ERROR_FORMAT; 
    }
    switch(*op)
    {
        case('+'):
            return PARSE_OK;
        case('-'):
            return PARSE_OK;
        case('*'):
            return PARSE_OK;
        case('/'):
            return PARSE_OK;
        case('^'):
            return PARSE_OK;
        default:
            return PARSE_ERROR_OPERATION;
    }       
}