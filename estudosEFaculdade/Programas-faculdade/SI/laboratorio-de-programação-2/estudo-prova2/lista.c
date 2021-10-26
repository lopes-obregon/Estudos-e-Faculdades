#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int value;
    struct list_t *next;
}list_t;

typedef struct{
    struct list_t *head;
}head_t;
//protótipos
void printList(head_t *list);
list_t  *inserir(head_t *list, int element);
void clearList(head_t *list);
void buscar(head_t *list, int  element);
//main
int main(int argc, char const *argv[])
{
    head_t *head_list;
    head_list = (head_t *) malloc(sizeof(head_t));
    head_list->head = NULL;
    head_list->head = inserir(head_list, 4);
    head_list->head = inserir(head_list, 14);
    head_list->head = inserir(head_list, 44);
    head_list->head = inserir(head_list, 6);
    head_list->head = inserir(head_list, 18);
    head_list->head = inserir(head_list, 20);
    head_list->head = inserir(head_list, 34);

    printList(head_list);
    buscar(head_list, 44);
    buscar(head_list, 100);
    clearList(head_list);
    if(head_list->head == NULL)
        free(head_list);
    return 0;
}

//insere na lista
list_t  *inserir(head_t *list, int element){
    list_t *new_list;
    new_list = (list_t *) malloc(sizeof(list_t));
    new_list->next = NULL;
    new_list->value = element;
    new_list->next = list->head;
    list->head = new_list;
    return new_list;

}
//imprime a lista;
void printList(head_t *list){
    list_t *aux = list->head;
    while(aux != NULL){
        printf("%d ->", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

//limpa a lista

void clearList(head_t *list){
    list_t *aux = list->head;
    list_t *dead_elemet;
    while(aux != NULL){
        dead_elemet = aux;
        aux = aux->next;
        free(dead_elemet);
    }
    //chegou no fim da lista
    list->head = aux;
    printf("\n");
    puts("Lista vazia");
}

//buscar elemento
void buscar(head_t *list, int  element){
    list_t *aux;
    aux = list->head;
    while(aux != NULL && aux->value != element ){
        aux = aux->next;
    }
    if(aux == NULL){
        puts("Elemento não encontrado");
    }else{
        puts("Elemento encontrado");
    }
}