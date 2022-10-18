#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

List *make_list() 
{
    List *list = malloc(sizeof(List));
    list->first = NULL;  
    list->last = list->first;
    list->size = 0;
    return list;
}

int isEmpty(const List *list) 
{
    return (list->first == NULL);
}

void list_push_front(List *list, Item item) 
{
    Node *new_node = malloc(sizeof(Node));
    
    new_node->item = item;
    // O próx link do novo nodo aponta para o atual 1º elemento (tornando-o o 2º elemento).
    new_node->next = list->first;
    // O 1º elemento agora é o novo nodo.
    list->first = new_node;
    list->size++;

    // Atualiza o a posição do último elemento
    Node *i;
    for(i = list->first; i->next != NULL; i = i->next);
    list->last = i;
}

void list_push_back(List *list, Item item)
{
    if(list->first == NULL) {
        list_push_front(list, item);
        return;
    }
    Node *new_node = malloc(sizeof(Node));
    Node *prev;

    new_node->item = item;
    new_node->next = NULL;
    // Salva o ponteiro do "novo" penúltimo elemento
    prev = list->last;
    // Atualiza o último elemento
    list->last = new_node;
    // O penúltimo elemento agora linka para o último
    prev->next = list->last;
    list->size++;
}

int list_shift(List *list)
{
    if(isEmpty(list))
        return -1;
    Node *tmp;
    tmp = list->first;
    list->first = tmp->next;
    free(tmp);
    list->size--;
    return 0;
}

int list_pop(List *list)
{
    if(isEmpty(list))
        return -1;
    Node *prev;

    for(Node *i = list->first; i->next != NULL; i = i->next) {
        // Pega o penúltimo elemento
        prev = i;
    }

    free(prev->next);
    prev->next = NULL;
    // Atualiza o último elemento
    list->last = prev;
    list->size--;
    return 0;
}

int list_insert_at(List *list, Item item, unsigned int pos)
{
    if(pos >= list->size) {
        fprintf(stderr, "Erro insercao: Indice incompativel com o tamanho da lista\n");
        return -1;
    }
    if(pos == 0) {
        list_push_front(list, item);
        return 0;
    }
    Node *new_node = malloc(sizeof(Node));
    Node *tmp;
    new_node->item = item;
    Node *prev;
    Node *i = list->first;
    int j = 0;
    // Percorre toda lista até chegar no ponto de inserção, salvando o ponteiro do nodo anterior ao ponto de inserção.
    // Aqui i->next nunca será NULL de início pq pos é menor que o tamanho da lista.
    do {
        prev = i;
        i = i->next;
        j++;
    } while(j != pos && i->next != NULL);

    // Link do Nodo que virá depois do novo
    tmp = prev->next;
    // Atualiza o nodo anterior para linkar para o novo nodo
    prev->next = new_node;
    // O novo nodo linka para o nodo que ele substituiu
    new_node->next = tmp;

    // Para atualizar a referência da última posição
    while(i->next != NULL) {
        i = i->next;
    }
    list->last = i;
    list->size++;

    return 0;
}

int list_remove_at(List *list, unsigned int pos)
{
    if(pos >= list->size) {
        fprintf(stderr, "Erro remocao: Indice incompativel com o tamanho da lista\n");
        return -1;
    }
    if(pos == 0) {
        list_shift(list);
        return 0;
    }
    if(pos == list->size - 1) {
        list_pop(list);
        return 0;
    }

    Node *prev;
    Node *i = list->first;
    Node *to_remove;
    int j = 0;
    // Percorre toda lista até chegar no ponto de remoção, salvando o ponteiro do nodo anterior ao ponto de remoção.
    // Aqui i->next nunca será NULL de início pq pos é menor que o tamanho da lista.
    do {
        prev = i;
        i = i->next;
        j++;
    } while(j != pos && i->next != NULL);

    // Nodo anterior ao ponto de remoção linka ao nodo posterior ao ponto de remoção
    prev->next = i->next;
    // Guarda referência do nodo a remover.
    to_remove = i;

    // Para atualizar a referência da última posição
    while(i->next != NULL) {
        i = i->next;
    }
    list->last = i;
    list->size--;

    free(to_remove);
    return 0;
}

int list_is_ordered(const List *list)
{
    int is_ordered_asc = 1;
    int is_ordered_desc = 1;
    for(Node *node = list->first; node->next != NULL; node = node->next) {
        is_ordered_asc = (node->item.value <= node->next->item.value);
        is_ordered_desc = (node->item.value >= node->next->item.value);
        if( !(is_ordered_asc || is_ordered_desc) )
            return 0;
    }
    return 1;
}

void list_print_all(const List *list)
{   
    int k = 0;
    for(Node *i = list->first; i->next != NULL; i = i->next) {
        printf("Valor do nodo %d: %d\n", k++, i->item.value);
    }
    printf("Valor do nodo %d: %d\n", k++, list->last->item.value);
}

void destroy_list(List *list)
{
    Node *node;
    node = list->first;
    // Libera memória alocada de cada nodo
    do {
        Node *curr = node;
        node = node->next;
        free(curr);
    } while(node->next != NULL);
    // Libera o último.
    free(node);
    // Libera o cabeçalho da lista
    free(list);
}

