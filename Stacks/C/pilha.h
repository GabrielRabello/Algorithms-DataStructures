#ifndef PILHA_H
#define PILHA_H 1

#define TRUE 1
#define FALSE 0

typedef struct node_item {
    int value;
} Item;

typedef struct node {
    struct node_item item;
    struct node *next;
} Node;

typedef struct stack_header {
    struct node *top;
    int size;
} Stack;

// Cria pilha vazia
Stack *new_stack();

// Cria um novo nodo
Node *new_node(const Item item);

// Verifica se a pilha está vazia
int isEmpty(const Stack *const stack);

// Adiciona elemento para o fim da stack. Define a stack caso já não esteja.
void stack_push(Stack *stack, const Item item);

// Remove o último elemento da pilha
Item stack_pop(Stack *const stack);

// Verifica se a pilha está ordenada de forma ascendente ou descendente.
int stack_is_ordered(const Stack *const stack);

// Copia src para dest
int stack_copy(Stack *const dest, const Stack *const src);

// Inverte os elementos de src e copia para dest
int revert_and_copy(Stack *const dest, const Stack *const src);

// Exibe todos os valores da pilha
void stack_print_all(const Stack *const stack);

int stack_size(const Stack *const stack);

// Limpa toda a memória alocada para a pilha e anula seu ponteiro.
void stack_destroy(Stack **stack);

// Limpa o terminal
void clrscr();

#endif