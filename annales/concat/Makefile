tests: tests.o concat.o
	gcc -o tests tests.o concat.o

concat.o: concat.c
	gcc -o concat.o -c concat.c

tests.o: tests.c 
	gcc -o tests.o -c tests.c

clean:
	rm -rf *.o
	rm -f concat
	rm -f tests
