#include <stdlib.h>

#include "array-list.h"

#define INITIAL_SIZE 10

struct list_t {
    void ** elements;
    size_t available;
    size_t count;
};



/**
 * crée une liste vide. 
 * Retourne NULL en cas de problème.
 */
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
        free(l);
        return NULL;
    }
    return l;
}

int list_ensure_grow(list_t *l) {
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
    return 1;
}

/**
 * en cas de problème, retourne 0
 * si tout se passe bien, retourne 1
 */
int list_append(list_t *l, void * el){
    if (!list_ensure_grow(l))
    {
        return 0;
    }
    l->elements[l->count] = el;
    l->count++;
    return 1;
}

/**
 * retourne le (idx+1)-ieme élément.
 * En cas de dépassement, le comportement est indéfini
 * (très probablement une segfault)
 */
void* list_get(list_t *l, int idx){
    return l->elements[idx];
}

/**
 * libère la liste et les éléments 
 * (ils doivent donc avoir été alloué dynamiquement)
 */
void list_free(list_t *l)
{
    for (int i = 0; i < l->count; i++)
    {
        free(l->elements[i]);
    }
    free(l->elements);
    free(l);
}

int list_size(list_t *l) {
    return l->count;
}

int list_set(list_t *l, int idx, void *el) {
    if (idx >= 0 && idx < l->count)
    {
        free(l->elements[idx]);
        l->elements[idx] = el;
        return 1;
    }
    return 0;
}

int list_prepend(list_t *l, void *el) {
    if (!list_ensure_grow(l))
    {
        return 0;
    }
    for (int i = l->count; i > 0; i--)
    {
        l->elements[i] = l->elements[i-1];
    }
    l->elements[0] = el;
    l->count++;
    return 1;
}

void* list_last(list_t *l) {
    return l->elements[l->count - 1];
}

void* list_first(list_t *l) {
    return l->elements[0];
}

void* listpopfirst(list_t *l) {
    void *first = l->elements[0];
    l->count--;
    for (int i = 0; i < l->count; i++)
    {
        l->elements[i] = l->elements[i+1];
    }
    return first;
}

void* listpoplast(list_t *l) {
    return l->elements[--l->count];
}

int list_insert(list_t *l, int idx, void *el) {
    if(!list_ensure_grow(l))
    {
        return 0;
    }
    for (int i = l->count; i > idx; i--)
    {
        l->elements[i] = l->elements[i-1];
    }
    l->elements[idx] = el;
    l->count++;
    return 1;
}

void* list_take(list_t *l, int idx) {
    void *el = l->elements[idx];
    l->count--;
    for (int i = idx; i < l->count; i++)
    {
        l->elements[i] = l->elements[i+1];
    }
    return el;
}

void list_print(list_t *l) {
    printf("[");
    if (l->count > 0) {
        printf("%p", l->elements[0]);
        for (int i = 1; i < l->count; i++)
        {
            printf(", %p", l->elements[i]);
        }
    }
    printf("]\n");
}