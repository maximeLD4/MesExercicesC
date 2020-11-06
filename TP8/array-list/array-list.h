#include <stdlib.h>
#include <stdio.h>
#include "tps_unit_test.h"


struct list_t;
typedef struct list_t list_t;


/**
 * crée une liste vide. 
 * Retourne NULL en cas de problème.
 */
list_t *list_create(void);

/**
 * en cas de problème, retourne 0
 * si tout se passe bien, retourne 1
 */
int list_append(list_t *l, void * el);

/**
 * retourne le (idx+1)-ieme élément.
 * En cas de dépassement, le comportement est indéfini
 * (très probablement une segfault)
 */
void* list_get(list_t *l, int idx);

/**
 * libère la liste et les éléments 
 * (ils doivent donc avoir été alloué dynamiquement)
 */
void list_free(list_t *l);

int list_size(list_t *l);

int list_set(list_t *l,int idx,void * el);

int list_prepend(list_t *l, void * el);

void * list_last(list_t * l);

void * list_first(list_t * l);

void * listpoplast(list_t * l);

void * listpopfirst(list_t * l);

int list_insert(list_t * l, int idx, void * el);

void * list_take(list_t * l, int idx);



