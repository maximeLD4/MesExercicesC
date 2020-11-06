#!/bin/sh

TARGET=repeat






#
# Ce placer dans le répertoire courant
#
TESTDIR="$(cd "$(dirname "$0}")" && pwd)"
cd "$TESTDIR"

#
# Conserver une trace de toutes les actions
#
LOG="test.log"
rm -f "$LOG"
touch "$LOG"

#
# Importer les fonctions communes à tous les tests
#
. ./fonctions.sh




test_sortie ()
{
  EXITCODE=$?
  ATTENDU=$1
  FONCTION_TEST=$2

  echo "\n#### Execution (tronqué à 80 caractères)" >> $LOG
  # conserve la sorte dans le log
  cat $SORTIE | cut -c -80 >> $LOG
  echo "\n==> exitcode: $EXITCODE" >> $LOG

  # si le programme quitte avec un code d'erreur, c'est la fin
  if [ $EXITCODE -ne 0 ]
  then
    fail
  else
    # sinon on vérifie qu'il retourne bien ce qui été attendu

    echo "\n#### Comparaison" >> $LOG

    # teste la sortie avec l'attendu en utilisant la
    # fonction de teste fournie (grep ou diff ou diff_end)
    $FONCTION_TEST "$SORTIE" "$ATTENDU" >> $LOG

    if [ $? -ne 0 ]
    then
      fail
    else
      coloredEcho "OK" green
    fi
  fi
}




#
# Compilation du programme.
#
NOTE=0

annoncer "Compilation"
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror >> $LOG 2>&1 || fail || exit 1
coloredEcho "OK" green

NOTE=25

#
# Test "entrée/sortie"
#
annoncer "Execution"

ADD_NOTE=14
annoncer "Partie 1 - test 0"
test_fichiers_entree_sortie test-0/in test-0/out test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=3
annoncer "Partie 1 - test 1"
test_fichiers_entree_sortie test-1/in test-1/out test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=3
annoncer "Partie 1 - test 2"
test_fichiers_entree_sortie test-2/in test-2/out test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=5
annoncer "Partie 1 - test 3"
test_fichiers_entree_sortie test-3/in test-3/out test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=5
annoncer "Partie 1 - test 4"
test_fichiers_entree_sortie test-4/in test-4/out test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=5
annoncer "Partie 1 - test 5"
test_fichiers_entree_sortie test-5/in test-5/out test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=5
annoncer "Partie 1 - test 6"
test_fichiers_entree_sortie test-6/in test-6/out test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=3
annoncer "Partie 2 - test 0"
./$TARGET "$(head -n 1 test-0/in)" "$(tail -n 1 test-0/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-0/out)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=2
annoncer "Partie 2 - test 1"
./$TARGET "$(head -n 1 test-1/in)" "$(tail -n 1 test-1/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-1/out)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=2
annoncer "Partie 2 - test 2"
./$TARGET "$(head -n 1 test-2/in)" "$(tail -n 1 test-2/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-2/out)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=3
annoncer "Partie 2 - test 3"
./$TARGET "$(head -n 1 test-3/in)" "$(tail -n 1 test-3/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-3/out)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=3
annoncer "Partie 2 - test 4"
./$TARGET "$(head -n 1 test-4/in)" "$(tail -n 1 test-4/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-4/out)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=3
annoncer "Partie 2 - test 5"
./$TARGET "$(head -n 1 test-5/in)" "$(tail -n 1 test-5/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-5/out)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=3
annoncer "Partie 2 - test 6"
./$TARGET "$(head -n 1 test-6/in)" "$(tail -n 1 test-6/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-6/out)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))


ADD_NOTE=6
annoncer "Partie 3 - test 0 reverse"
./$TARGET "$(head -n 1 test-0/in)" "-$(tail -n 1 test-0/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-0/out_reverse)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=5
annoncer "Partie 3 - test 2 reverse"
./$TARGET "$(head -n 1 test-2/in)" "-$(tail -n 1 test-2/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-2/out_reverse)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

ADD_NOTE=5
annoncer "Partie 3 - test 4 reverse"
./$TARGET "$(head -n 1 test-4/in)" "-$(tail -n 1 test-4/in)" 2>&1 > $SORTIE
test_sortie "$(cat test-4/out_reverse)" test_diff_end
NOTE=$(( $NOTE+$ADD_NOTE ))

echo "$NOTE" > note.txt

if [ $NOTE -eq 100 ];
then
  exit 0
fi
exit 1
