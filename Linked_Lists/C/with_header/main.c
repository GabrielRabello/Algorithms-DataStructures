#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) 
{
    List *list;
    Item item;
    list = make_list();

    item.value = 5; 
    list_push_back(list, item);
    item.value = 10;
    list_push_back(list, item);
    item.value = 15;
    list_push_back(list, item);
    list_pop(list);
    // item.value = 20;
    // list_insert_at(list, item, 23);
    // item.value = 50;
    // list_insert_at(list, item, 3);

    int is_ordered= list_is_ordered(list);
    if(is_ordered) {
        puts("Lista ordenada");
    } else {
        puts("Lista nao-ordenada");
    }

    list_print_all(list);    

    printf("Tamanho da lista: %d\n", list->size);
    destroy_list(list);

    return 0;
}