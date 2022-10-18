main: main.o lista.o
	gcc -fsanitize=address -static-libasan main.o lista.o -o main

main.o: main.c lista.o lista.h
	gcc -g -Wall -fsanitize=address -c main.c

lista.o: lista.c lista.h
	gcc -g -Wall -fsanitize=address -c lista.c