main: main1.o add.o
	gcc main1.o add.o -o main -Wall -ansi

main1.o: main1.c add.h
	gcc main.c -o main1.o -c -Wall -ansi

add.o: add.c add.h
	gcc add.c -o add.o -c -Wall -ansi