main: main.o add.o
	gcc main.o add.o -o main -Wall -ansi

main.o: main.c add.h
	gcc main.c -o main.o -c -Wall -ansi

add.o: add.c add.h
	gcc add.c -o add.o -c -Wall -ansi