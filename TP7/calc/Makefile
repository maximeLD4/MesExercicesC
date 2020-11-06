tests: tests.o parser.o calc-io.o
	gcc -o tests tests.o parser.o calc-io.o -lm
calc: calc.o parser.o calc-io.o	
	gcc -o calc calc.o parser.o calc-io.o -lm


tests.o: tests.c
	gcc -o tests.o -c tests.c 
calc.o: calc.c
	gcc -o calc.o -c calc.c 


parser.o : parser.c
	gcc -o parser.o -c parser.c
calc-io.o: calc-io.c
	gcc -o calc-io.o -c calc-io.c -lm

clean:
	rm -rf *.o
	rm -f calc
	rm -f tests

