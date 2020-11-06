## List

Le fichier `list.h` contient déjà plusieurs déclaration de fonction permettant de créer et de manipuler des structures de type `List`.
Ces fonctions sont implémentées dans le fichier `list.c`

* Vous devez ajoutez dans ces fichiers les fonctions suivantes:
  * `void * list_last(List *l)`: qui retourne la valeur du dernier élément, ou NULL si la liste est vide.
  * `void * list_get(List *l, size_t i)`: retourne la valeur à la ième position dans la liste, ou NULL si la liste est l'indice n'est pas correct.
  * `size_t list_size(List *l)`: retourne la taille de la liste.
  * `void list_free(List *l)`: vide et libère toutes les zones mémoires allouées pour la liste.
* Vous devez écrire un fichier `Makefile` permettant de compiler le fichier `tests.c` (qui utilise les fonctions déclarée dans `list.h`). Il devra contenir une règle `tests:` et une règle `clean:` permettant de supprimer les fichiers temporaires de compilation.
