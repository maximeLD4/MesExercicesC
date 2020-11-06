#include <stdlib.h>
#include <stdio.h>

typedef struct list_node_t {
    int element;
    struct list_node_t *next;
} list_node_t;

typedef struct {
    list_node_t *begin;
    int size;
} list_t;

/**
 * crée une liste vide. 
 * Retourne NULL en cas de problème.
 */

list_t *list_create(void) {
    list_t *l = malloc(sizeof(list_t));
    if (l == NULL) {
        return NULL;
    }
    l->size = 0;
    l->begin = NULL;
    return l;
}

/**
 * en cas de problème, retourne 0
 * si tout se passe bien, retourne 1
 */

void list_append(list_t *l, int el) 
{
    list_node_t *new_end = malloc(sizeof(list_node_t));
    
    new_end->element = el;
    new_end->next = NULL;
    l->size++;
    if (l->begin == NULL) 
    {
        l->begin = new_end;
    } 
    else 
    {
        list_node_t *end = l->begin;
        int i = 1;
        while (end->next != NULL) 
        {
            end = end->next;
            i++;
        }
        end->next = new_end;
    }
}

/**
 * retourne le (idx+1)-ieme élément.
 * En cas de dépassement, le comportement est indéfini
 * (très probablement une segfault)
 */

int list_get(list_t *l, int index) {
    list_node_t *itr = l->begin;
    for (int i = 0; i < index; i++) {
        itr = itr->next;
    }
    return itr->element;
}

void node_free(list_node_t *e)
{
    if(e->next != NULL)
    {
        node_free(e->next);
    }
    free(e);
}

void list_free(list_t *l) 
{
    if(l->begin != NULL)
    {
        node_free(l->begin);
    }
    free(l);
}

int list_size(list_t *l) 
{
    return l->size;
}

void list_prepend(list_t *l, int el) {
    list_node_t *first = malloc(sizeof(list_node_t));
    first->element = el;
    first->next = l->begin;
    l->begin = first;
    l->size++;
}