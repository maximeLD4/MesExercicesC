## Langage de Dyck

un mot de Dyck est un mot "bien parenthésé" i.e.,
composé uniquement de parenthèses `(` et `)`
et qui est soit le mot vide, soit la concaténation
de deux mots de Dyck, soit `(m)` ou `m` est un mot de Dyck.
Tous les caractères qui ne sont pas des parenthèses seront ignorés (on considère que `(a) ((b) )` est un mot de Dyck)

Ecrire un programme qui accepte un argument de ligne de commande
et qui retourne 0 si c'est un mot de Dyck et retourne le code d'erreur 1 sinon.

Si aucun argument de ligne de commande n'est donné (ou si deux ou plus sont donnés), votre programme doit quitter
avec le code d'erreur 2 et afficher dans la sortie d'erreur :
`Usage: dyck [word]`

### Exemples
#### Exemple 1
```
$ ./dyck "()(())"
```
votre programme doit retourner 0

#### Exemple 2
```
$ ./dyck "()())"
```
votre programme doit retourner 1

#### Exemple 3
```
$ ./dyck "()(()" "())"
Usage: dyck [word]
```
votre programme doit retourner 2

#### Exemple 4
```
$ ./dyck "()(() ())"
OUI
```
votre programme doit retourner 0