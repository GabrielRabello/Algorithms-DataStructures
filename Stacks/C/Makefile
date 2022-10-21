main: main.o pilha.o
	gcc -fsanitize=address -static-libasan main.o pilha.o -o main

main.o: main.c pilha.o pilha.h
	gcc -g -Wall -fsanitize=address -c main.c

pilha.o: pilha.c pilha.h
	gcc -g -Wall -fsanitize=address -c pilha.c