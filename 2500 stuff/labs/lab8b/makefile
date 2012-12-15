main2: main.o f1.o f2.o
	gcc main.o f1.o f2.o -o main2 -Wall -ansi

main.o: main.c labhead.h
	gcc main.c -o main.o -c -Wall -ansi
	
f1.o: f1.c labhead.h
	gcc f1.c -o f1.o -c -Wall -ansi
	
f2.o: f2.c labhead.h
	gcc f2.c -o f2.o -c -Wall -ansi