test: shell.o main.o
	gcc -o test shell.o main.o

shell.o: shell.c header.h
	gcc -c shell.c

main.o: main.c header.h
	gcc -c main.c
	
run: test
	./test

clean:
	rm *.o
	rm *~
