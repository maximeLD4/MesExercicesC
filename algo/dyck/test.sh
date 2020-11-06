#!/bin/sh

TARGET=dyck

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
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror >> $LOG 2>&1 || fail
coloredEcho "OK" green


annoncer "Test 1"
./$TARGET "()" >> $LOG 2>&1
if [ $? -ne 0 ]
then
  echo 'wrong exit code' >> $LOG
  fail
fi
coloredEcho "OK" green

annoncer "Test 2"
./$TARGET "(" >> $LOG 2>&1
if [ $? -ne 1 ]
then
  echo 'wrong exit code' >> $LOG
  fail
fi
coloredEcho "OK" green



annoncer "Test 3"
./$TARGET "((()())" >> $LOG 2>&1
if [ $? -ne 1 ]
then
  echo 'wrong exit code' >> $LOG
  fail
fi
coloredEcho "OK" green



annoncer "Test 4"
./$TARGET "(sdfb(aaf(a)sdf(fgd) fdgsdf )sdfsgfd )" >> $LOG 2>&1
if [ $? -ne 0 ]
then
  echo 'wrong exit code' >> $LOG
  fail
fi
coloredEcho "OK" green

annoncer "Test 5"
./$TARGET >> $LOG 2>&1
if [ $? -ne 2 ]
then
  echo 'wrong exit code' >> $LOG
  fail
fi
coloredEcho "OK" green

annoncer "Test 6"
./$TARGET "()" "()" >> $LOG 2>&1
if [ $? -ne 2 ]
then
  echo 'wrong exit code' >> $LOG
  fail
fi
coloredEcho "OK" green

annoncer "Test 7"
./$TARGET "
((((((((((((((((((((((((((((((((((((((((((((((((((
))))))))))))))))))))))))))))))))))))))))))))))))))
" >> $LOG 2>&1
if [ $? -ne 0 ]
then
  echo 'wrong exit code' >> $LOG
  fail
fi
coloredEcho "OK" green



exit 0
