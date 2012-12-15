all: main main2

main: main1.o add.o
	gcc main1.o add.o -o main -Wall -ansi
	
main2: main.o f1.o f2.o
	gcc main.o f1.o f2.o -o main2 -Wall -ansi

main1.o: main1.c add.h
	gcc main1.c -o main1.o -c -Wall -ansi

add.o: add.c add.h
	gcc add.c -o add.o -c -Wall -ansi
	
main.o: main.c labhead.h
	gcc main.c -o main.o -c -Wall -ansi
	
f1.o: f1.c labhead.h
	gcc f1.c -o f1.o -c -Wall -ansi
	
f2.o: f2.c labhead.h
	gcc f2.c -o f2.o -c -Wall -ansi

clean:
	rm *.o
	rm main
	rm main2