#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 10


struct list_t {
    void ** elements;
    size_t available;
    size_t count;
};
typedef struct list_t list_t;



list_t *list_create(void)
{
    list_t *l = malloc(sizeof(list_t));
    if(l == NULL)
    {
        return NULL;
    }
    l->count = 0;
    l->available = INITIAL_SIZE;
    l->elements = calloc(INITIAL_SIZE, sizeof(void*));
    if(l->elements == NULL)
    {
        return NULL;
    }
    return l;
}

int list_append(list_t *l, void * el){
    if(l->count == l->available)
    {
        size_t new_size = l->available*2;
        void ** new_array = realloc(
            l->elements, 
            new_size * sizeof(void*)
        );
        if(new_array == NULL)
        {
            return 0;
        }
        l->elements = new_array;
        l->available = new_size;
    }
    l->elements[l->count] = el;
    l->count++;
    return 1;
}


int list_insert(list_t * l, int idx, void * el)
{
    if(l->count == l->available)
    {
        size_t new_size = l->available*2;
        void ** new_array = realloc(
            l->elements, 
            new_size * sizeof(void*)
        );
        if(new_array == NULL)
        {
            return 0;
        }
        l->elements = new_array;
        l->available = new_size;
    }
    int i=(l->count);
    while(i>idx)
    {
        l->elements[i]=l->elements[i-1];
        i--;
    }
    l->elements[idx]=el;
    return 1;
}

void main(void)
{
    struct list_t {
        void ** elements;
        size_t available;
        size_t count;
    };

    list_t* l = list_create();
    int a=1;
    int b=2;
    int c=3;
    int d=4;
    list_append(l, &a);
    list_append(l, &b);
    list_append(l, &c);
    list_insert(l, 1, &d);
    printf("%i \n", *(int* )(l->elements[2]));
}