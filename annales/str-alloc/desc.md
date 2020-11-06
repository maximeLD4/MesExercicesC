## Suppression de lettre

Déclarer *dans le fichier d'entête `str-alloc.h`* une structure nommée `student_t` qui contient un attribut de
type `char *` nommé `first_name` et un attribut de type `char *` nommé `last_name`.
Dans le même fichier, écrire une fonction `strAlloc` qui prend un pointeur vers structure `student_t`
et un `unsigned long long` `n` et initialise les attribut `first_name` et `last_name` de cette structure en leur allouant dynamiquement
de la mémoire pour `n` caractères chacun, et en initialisant tous les caractères à 0.

*Si tout se passe bien vous ne vous occuperez pas de libérer la mémoire*
(vous pouvez voir dans le fichier `tests.c` que je la fonction appelante s'occupe de cela).

Par contre si une allocation échoue, vous ferez bien attention à mettre les deux pointeurs (les attributs `first_name` et `last_name`)
à `NULL` et à libérer ce que vous avez déjà alloué.


Le fichier `tests.c` est un programme qui test automatiquement votre fonction.
Vous pouvez aussi créer votre propre programme dans un autre fichier afin de tester votre fonction.
Pour cela, vous pouvez inclure le fichier `str-alloc.h`.
Exemple de programme de test :

```C
#include "str-alloc.h"

int main(void)
{
  // appel vers la fonction strAlloc(...).
}

```

### Exemples

Un pointeur `s` et le nombre 100 sont envoyé à votre fonction, après l'appel de votre
fonction l'attribut `name` de `s` pointe vers un tableau de caractères dynamiquement alloué de taille 100
