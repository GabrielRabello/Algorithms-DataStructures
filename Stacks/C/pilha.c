#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Stack *new_stack() 
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;  
    stack->size = 0;
    return stack;
}

Node *new_node(const Item item) 
{
    Node *node = malloc(sizeof(Node));
    node->item = item;
    node->next = NULL;
    return node;
}

int isEmpty(const Stack *const stack) 
{
    return !stack->top;
}

void stack_push(Stack *stack, const Item item)
{
    if(stack == NULL) stack = new_stack();
    Node *node = new_node(item);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

Item stack_pop(Stack *const stack)
{
    if(!stack || isEmpty(stack)) {
        fprintf(stderr, "Erro stack_pop(): Pilha vazia ou nula.\n");
        exit(EXIT_FAILURE);
    }
    // Guarda o item a remover
    Node *top = stack->top;
    Item to_remove = top->item;
    // Atualiza o topo da pilha
    stack->top = top->next;
    // Remove o antigo topo
    free(top);
    stack->size--;

    return to_remove;
}

int stack_is_ordered(const Stack *const stack)
{
    if(stack == NULL) return FALSE;
    if(isEmpty(stack)) return TRUE;
    int is_ordered_asc = TRUE;
    int is_ordered_desc = TRUE;
    for(Node *node = stack->top; node->next != NULL; node = node->next) {
        is_ordered_asc = (node->item.value <= node->next->item.value);
        is_ordered_desc = (node->item.value >= node->next->item.value);
        if( !(is_ordered_asc || is_ordered_desc) )
            return FALSE;
    }
    return TRUE;
}

int stack_copy(Stack *const dest, const Stack *const src)
{
    if(src == NULL) return -1;
    if(isEmpty(src)) {
        fprintf(stderr, "Pilha vazia, nada a copiar\n");
        return -1;
    }
    Node *node;
    for(node = src->top; node->next != NULL; node = node->next) {
        stack_push(dest, node->item);
    }
    stack_push(dest, node->item);

    return 0;
}

int revert_and_copy(Stack *const dest, const Stack *const src) 
{    
    stack_copy(dest, src);

    Node *nodes_ptr[src->size];
    Node *node;
    int i = 0;    

    for(node = dest->top; node->next != NULL; node = node->next) {
        // Pega os endereços da stack, 
        nodes_ptr[i++] = node;
    }
    nodes_ptr[i] = node;

    // Troca os elementos de ponta em ponta até o centro.
    for(i = 0; i < dest->size/2; i++) {
        Item item = nodes_ptr[i]->item;        
        nodes_ptr[i]->item = nodes_ptr[dest->size -1 - i]->item;
        nodes_ptr[dest->size -1 - i]->item = item;
    }
    return 0;
}

void stack_print_all(const Stack *const stack)
{   
    if(stack == NULL) {
        fprintf(stderr, "Erro stack_print_all(): Pilha NULL\n");
        return;
    }
    if(isEmpty(stack)) {
        puts("Pilha vazia");
        return;
    }
    int k = 0;
    Node *node;

    for(node = stack->top; node->next != NULL; node = node->next, k++) {
        if(k == 0)
            printf("Valor do nodo %d (topo): %d\n", k, node->item.value);
        else printf("Valor do nodo %d: %d\n", k, node->item.value);
    }
    printf("Valor do nodo %d: %d\n", k, node->item.value);
}

int stack_size(const Stack *const stack)
{
    if(stack == NULL) {
        fprintf(stderr, "Pilha é NULL\n");
        return -1;
    }
    return stack->size;
}

void stack_destroy(Stack **stack)
{
    if(*stack == NULL) return;
    Node *curr;
    Node *node = (*stack)->top;

    if(node != NULL) { // Quando a pilha não é vazia
        while(node->next != NULL) {
            curr = node;
            node = node->next;
            free(curr);
        }
        // Libera o último restante (É o único removido para n = 1)
        free(node);
    }    
    // Libera o cabeçalho da pilha
    free(*stack);
    // anula ponteiro da pilha. Para proteger contra acesso/escrita inválida de memória.
    *stack = NULL;
}

void clrscr()
{
    system("cls||clear");
}