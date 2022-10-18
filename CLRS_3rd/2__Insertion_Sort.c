#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#define TAM 50

int main(void) {
    int array[TAM] = {0};

    srand(time(0));

    puts("Array original: ");
    for(int i = 0; i < TAM; i++) {
        array[i] = rand() % 100;
        printf("%d, ", array[i]);
    }
    puts("");

    // Insertion Sort
    for(int j = 2; j <= TAM; j++) 
    {
        int key = array[j];
        // Insere array[j] na sequencia ordenada A[1..j-1]

        // Exemplo: [3, 2, 4]
        int i = j - 1;
        while(i >= 0 && array[i] > key) 
        {
            array[i+1] = array[i];
            i--;
        } 
        array[i+1] = key;
    }

    puts("Array Ordenado: ");
    for(int i = 0; i < TAM; i++) {
        printf("%d, ", array[i]);
    }
}