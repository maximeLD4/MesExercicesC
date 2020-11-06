tests: tests.o array-list.o
	gcc -o tests tests.o array-list.o

array-list: array-list.o
	gcc -o array-list array-list.o 


array-list.o: array-list.c
	gcc -o array-list.o -c array-list.c 

tests.o: tests.c 
	gcc -o tests.o -c tests.c

clean:
	rm -rf *.o
	rm -f array-list
	rm -f tests
