#!/bin/sh

TARGET=palindrome

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


#
# Compilation du programme.
#

annoncer "Compilation"
rm -f $TARGET
gcc $TARGET.c -o $TARGET -Wall -Wextra -Werror >> $LOG 2>&1 || fail
coloredEcho "OK" green



#
# Test "entrée/sortie"
#
for dir in $(find ./test-* -maxdepth 1 -type d -printf "%f\n"); do
  annoncer "Test entrée/sortie : $dir"
  test_fichiers_entree_sortie $dir/in $dir/out test_diff
done


annoncer "Test bonus"

OUT=$(./$TARGET "aba")
if [ "$OUT" != "OUI" ]
then
  echo "$OUT" >> $LOG
  fail
fi
coloredEcho "OK" green

exit 0
