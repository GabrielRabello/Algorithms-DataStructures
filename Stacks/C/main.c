#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(void) 
{
    int ch;
    Item item;
    Stack *stack = new_stack();

    do {
        printf("Escolha uma Opcao:\n----------------------------\n");
        puts("1. Inserir elemento na pilha");
        puts("2. Remover elemento da pilha");
        puts("3. Exibir todos os elementos");
        puts("4. Exibir tamanho da pilha");
        puts("5. Limpar pilha");
        puts("6. Encerrar");
        
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                clrscr();
                puts("Valor a inserir: ");
                scanf("%d", &item.value);
                stack_push(stack, item);
                break;
            case 2:
                clrscr();
                Item rem = stack_pop(stack);
                printf("Sucesso!\nValor removido: %d\n", rem.value);
                break;
            case 3:
                clrscr();
                stack_print_all(stack);
                break;
            case 4:
                clrscr();
                int size = stack_size(stack);
                if(size != -1)
                    printf("Tamanho da pilha: %d\n", stack->size);
                break;
            case 5:
                clrscr();
                stack_destroy(&stack);
                puts("Pilha limpada com sucesso");
                break;
            default:
                break;
        }
    } while (ch != 6);



    // Stack *stack2 = new_stack();    
    // Item item;

    // item.value = 5;
    // stack_push(stack, item);
    // stack_pop(stack);

    // // destroy_stack(&stack);
    // item.value = 10;
    // stack_push(stack, item);
    // item.value = 15;
    // stack_push(stack, item);
    // destroy_stack(&stack);
    // isEmpty(stack);

    // item.value = 20;
    // stack_push(stack, item);
    // item.value = 50;
    // stack_push(stack, item);
    // // stack_copy(stack2, stack);

    // // int is_ordered = stack_is_ordered(stack);
    // // if(is_ordered) {
    // //     puts("Pilha ordenada");
    // // } else {
    // //     puts("Pilha nao-ordenada");
    // // }
    // // revert_and_copy(stack2, stack);

    // stack_print_all(stack);    

    // printf("Tamanho da pilha: %d\n", stack->size);   

    // Item x = stack_pop(stack);
    // printf("Valor removido: %d\n\n", x.value);
    // stack_print_all(stack);    

    // destroy_stack(stack2);

    return 0;
}
