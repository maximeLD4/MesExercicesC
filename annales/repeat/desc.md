## Repeat

Vous devez écrire un programme (dans un fichier `repeat.c`) qui permet, à partir d'une
chaine de caractères donnée, affiche une nouvelle chaine de caractères identique
à la première *mais ou chaque caractère est répété un certain nombre de fois*.

Exemple, la chaine `Hello` où chaque caractère est répété 3 fois devient: `HHHeeellllllooo`.

Le script de test est divisé en plusieurs parties, de difficulté croissante.
Chaque partie ajoute de nouvelle fonctionnalités. Lorsque la première partie est implémentée,
les 10 premiers tests doivent passer. Ensuite *faite attention de ne pas casser ce que vous avez
fait lorsque vous implémentez la deuxième partie*, en effet, après avoir implémenter la deuxième partie,
Les tests de 11 à 20 doivent passer, mais les 10 premiers tests doivent encore fonctionner!!


## Première partie.

Pour commencer, on supposera que votre programme doit lire la chaine de caractères originale
dans le terminal. *On pourra supposer qu'elle est de taille inférieure ou égale à 50000.*
Puis votre programme doit lire un entier `n` (compris entre 0 et 1000000).
Ensuite votre programme doit afficher nouvelle chaine ou chaque caractère est répété `n` fois.

#### Exemple 1

Entrée:
``̀`
Hello
3
```

Sortie:

``̀`
HHHeeellllllooo
```

#### Exemple 2

Entrée:
``̀`
Hello
0
```

Sortie:

``̀`

```

#### Exemple 3

Entrée:
``̀`
Lorem ipsum.
2
```

Sortie:

``̀`
LLoorreemm  iippssuumm..
```


## Deuxième partie.

Pour cette partie, vous ferez en sorte que votre programme accepte que la chaine original proviennent
des arguments de ligne de commande. *Si la chaine original et le nombre de répétition sont donnée en arguments
de ligne de commande alors l'entrée standart du terminal sera ignorée*.
Le fonctionnement du programme reste similaire (et les limites donnée sur les tailles aussi).

Pour convertir une chaine de caractère en entier (notamment pour convertir `argv[2]` en entier), on pourra utiliser la fonction `atoi`: `int atoi(const char *nptr);`


#### Exemple 1

Exécution:
``̀`
$ ./repeat Hello 3
HHHeeellllllooo
```

#### Exemple 2

Exécution:
``̀`
$ ./repeat Hello 0
```

#### Exemple 3

Exécution:
``̀`
$ ./repeat "Lorem ipsum." 2
LLoorreemm  iippssuumm..
```

## Troisième partie.

Pour cette partie, on suppose que le nombre de répétition est compris entre -1000000 et 1000000.
Si le nombre de répétition est négatif, en plus d'effectuer les répétitions comme précédemment, la chaine doit être
inversée.

#### Exemple 1

Exécution:
``̀`
$ ./repeat Hello -3
ooolllllleeeHHH
```

#### Exemple 2

Entrée:
``̀`
Lorem ipsum.
-2
```

Sortie:

``̀`
..mmuussppii  mmeerrooLL
```
