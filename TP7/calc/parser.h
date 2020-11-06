#define PARSE_OK 1
#define PARSE_ERROR_FORMAT 2
#define PARSE_ERROR_OPERATION 3

int parse(const char * line, double *a, double *b, char *op);
















/*
calc: calc.o tests.o parsher.h calc-io.h
	gcc -o calc calc.o tests.o

calc.o: calc.c
	gcc -o calc.o -c calc.c -W -Wall 

parsher: parsher.o tests.o parsher.h calc-io.h
	gcc -o calc parsher.o tests.o

parsher.o: parsher.c
	gcc -o parsher.o -c parsher.c -W -Wall 

tests.o: tests.c parser.h calc-io.h
*/