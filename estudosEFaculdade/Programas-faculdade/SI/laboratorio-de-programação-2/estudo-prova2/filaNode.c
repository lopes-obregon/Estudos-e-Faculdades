#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10
typedef struct{
    int elemento;
    struct node_t *prox;
    struct node_t *ant;
    int tamanho;
}node_t;

typedef struct{
    node_t *inicio;
    node_t *final;
}fila_t;
//protótipos
void inserirFila(fila_t *fila, int elemento);
int estaVazia(fila_t *fila);
node_t *removerDaFIla(fila_t *fila);
void printFila(fila_t *fila);
void init(fila_t *fila);
int main(int argc, char const *argv[])
{   
    fila_t *fila;
    fila = (fila_t*) malloc(sizeof(fila_t));
    
    /* code */
    inserirFila(&fila, 18);
    inserirFila(&fila, 48);
    printFila(&fila);
   free(removerDaFIla(&fila));
    return 0;
}
//inicia a fila
void init(fila_t *fila){
    fila->inicio = NULL;
    fila->final = NULL;
} 
//insere na fila
void inserirFila(fila_t *fila, int elemento){
    //se a fila está cheia
    node_t *new_element;
    if(fila->final->tamanho ==  TAMANHO){
        puts("Overflow");
    }else{
      
        new_element = (node_t*)malloc(sizeof(node_t));
        new_element->elemento = elemento;
        new_element->prox = NULL;
        new_element->ant = NULL;
        if((fila->inicio == NULL) && (fila->final == NULL)){
            fila->inicio = new_element;
            fila->final = new_element;
            fila->final->tamanho = 1;
        }else{
            new_element->prox = fila->final;
            fila->final->ant = new_element;
            fila->final = new_element;

            fila->final->tamanho ++;
        }
    }
}

//retorna se a fila está vazia
int estaVazia(fila_t *fila){
   
    return fila->inicio == fila->final;
}

//remove um elemento da fila
node_t  *removerDaFIla(fila_t *fila){
    node_t *aux;
    if(estaVazia(fila)){
        puts("Underflow!");
    }else{
        aux = fila->inicio;
        fila->inicio = fila->inicio->ant;
        fila->inicio->tamanho--;
        return aux;
    }
}

//imprimir fila
void printFila(fila_t *fila){
   node_t *aux;
   aux = fila->inicio;
   while (aux != NULL)
   {
       printf("%d ->", aux->elemento);
       aux = aux->ant;
   }
   
}

//limpa memoria
void limpaMemoria(fila_t *fila){
    node_t *aux;
    node_t *dead_node;
    aux = fila->inicio;
    while (aux != NULL)
    {
        /* code */
        dead_node = aux;
        aux = aux->ant;
        free(dead_node);
    }
    
}