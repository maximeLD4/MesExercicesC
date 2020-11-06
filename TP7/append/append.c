#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "append.h"

int append(int ** tab, size_t *size, int value)
{
    int * newtab;
    newtab=realloc((*tab),((*size)+1)*sizeof(int));
    if((newtab)!=NULL)
    {
        *tab=newtab;
        (*tab)[*size]=value;
        (*size)++;
        return 1;
    }
    return 0;
}
