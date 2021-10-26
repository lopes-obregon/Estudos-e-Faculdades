//encontra e retorne o nó de maior valor de uma lista simples
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int valor;
    struct node_t *prox;
}node_t;

typedef struct{
    struct node_t *head;
}head_t;
//protótipos
void insere(head_t *list, int elemento );
void acertaPonteiro(head_t *list, node_t *novo_elemento);
node_t *buscaNaListaMaior(head_t *list);
void limpaLista(head_t *list);
//main
int main(int argc, char const *argv[])
{
    head_t *list;
    list = (head_t*)(malloc(sizeof(head_t)));
    list->head = NULL;
    insere(list, 45);
    insere(list, 8);
    insere(list, -4);
    printf("Maior elemento %d\n", buscaNaListaMaior(list)->valor);
    limpaLista(list);
    if(list->head == NULL){
        free(list);
    }
    return 0;
}

//insere no na lista
void insere(head_t *list, int elemento ){
    node_t *novo_elemento;
    novo_elemento = (node_t *) malloc(sizeof(node_t));
    novo_elemento->valor = elemento;
    novo_elemento->prox = NULL;
    acertaPonteiro(list, novo_elemento);

}

//acerta os ponteiros
void acertaPonteiro(head_t *list, node_t *novo_elemento){
    novo_elemento->prox = list->head;
    list->head = novo_elemento;
}

//busca elemento e retorna o maior elemento
node_t *buscaNaListaMaior(head_t *list){
    node_t *aux;
    node_t *no_maior;
    int maior = 0;
    aux = list->head;
    maior = aux->valor;
    while (aux != NULL)
    {
        /* code */
        if(aux->valor > maior){
            maior = aux->valor;
            no_maior = aux;
        }
        aux = aux->prox;
    }
    return no_maior;
    
}

//limpa a lista
void limpaLista(head_t *list){
    node_t *aux;
    node_t * no_morto;
    aux = list->head;
    while (aux != NULL)
    {
        /* code */
        no_morto = aux;
        aux = aux->prox;
        free(no_morto);
    }

    list->head = NULL;
    
}