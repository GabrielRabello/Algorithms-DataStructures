typedef struct node_item {
    int value;
} Item;

typedef struct node {
    struct node_item item;
    struct node *next;
} Node;

typedef struct list_header {
    struct node *first;
    struct node *last;
    int size;
} List;

// Cria lista vazia
List *make_list();

int isEmpty(const List *list);

// Adiciona elemento para o início da lista
void list_push_front(List *list, Item item);

// Adiciona elemento para o fim da lista
void list_push_back(List *list, Item item);

// Adiciona elemento em uma posição arbitrária da lista, indexada em 0.
int list_insert_at(List *list, Item item, unsigned int pos);

// Remove o primeiro elemento da lista
int list_shift(List *list);

// Remove o último elemento da lista
int list_pop(List *list);

// Remove elemento em uma posição arbitrária da lista, indexada em 0.
int list_remove_at(List *list, unsigned int pos);

// Verifica se a lista está ordenada de forma ascendente ou descendente.
int list_is_ordered(const List *list);

// Exibe todos os valores da lista
void list_print_all(const List *list);

//Limpa toda a memória alocada para a lista.
void destroy_list(List *list);
