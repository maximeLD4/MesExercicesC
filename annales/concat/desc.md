# Concaténation de chaines.

Le but de l'exercice est d'écrire une fonction `concat`, déclarée dans un fichier d'entête `concat.h`
et implémenté dans un fichier `concat.c`, qui prend en arguments deux chaines de caractères
et qui alloue et retourne **une nouvelle chaine de caractères** qui est la concaténation des deux chaines passé en arguments.

Par exemple, si la fonction concat est appelée avec les chaines "str1" et "str2", elle doit retourner
une nouvelle chaine "str1str2". Celui qui appelle la fonction concat est
responsable de la libération de l'espace mémoire qui a été allouée à cette chaine.

Le fichier `tests.c` implémente un programme qui permet de tester votre fonction.

**Vous devez ecrire le Makefile** permettant de compiler ce programme (avec une règle clean)

**Attention :** pour que les tests fonctionne, le fichier d'entête doit inclure
le fichier d'entête `tps_unit_test.h`.
