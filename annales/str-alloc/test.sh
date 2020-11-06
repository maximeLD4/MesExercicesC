#!/bin/sh

TARGET=tests



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
NOTE=0

annoncer "Compilation"
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror -Wno-implicit-fallthrough >> $LOG 2>&1 || fail
coloredEcho "OK" green

NOTE=30

#
# Test "entrée/sortie"
#
annoncer "Execution"
#stdbuf -o0 

annoncer "Test 0"
valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET 0 2>> $LOG || fail
coloredEcho "OK" green
NOTE=40


annoncer "Test 1"
valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET 1 2>> $LOG || fail
coloredEcho "OK" green
NOTE=50

annoncer "Test 2"
valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET 2 2>> $LOG || fail
coloredEcho "OK" green
NOTE=60

annoncer "Test 3"
valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET 3 2>> $LOG || fail
coloredEcho "OK" green
NOTE=70

annoncer "Test 4"
valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET 4 2>> $LOG || fail
coloredEcho "OK" green
NOTE=80

annoncer "Test 5"
valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET 5 2>> $LOG || fail
coloredEcho "OK" green
NOTE=100

success
