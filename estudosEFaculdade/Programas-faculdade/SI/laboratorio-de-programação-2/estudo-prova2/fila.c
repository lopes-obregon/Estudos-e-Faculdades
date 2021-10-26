#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10
typedef struct{
    int v[TAMANHO];
    int inicio;
    int final;
}fila_t;
//protótipos
void inserirFila(fila_t *fila, int elemento);
int estaVazia(fila_t fila);
int removerDaFIla(fila_t *fila);
void printFila(fila_t fila);
int main(int argc, char const *argv[])
{   
    fila_t fila;
    fila.final = 0;
    fila.inicio = 0;
    /* code */
    inserirFila(&fila, 18);
    inserirFila(&fila, 48);
    printFila(fila);
    removerDaFIla(&fila);
    inserirFila(&fila, 59);
    printFila(fila);
    removerDaFIla(&fila);
    removerDaFIla(&fila);
    removerDaFIla(&fila);
    return 0;
}
//insere na fila
void inserirFila(fila_t *fila, int elemento){
    //se a fila está cheia
    if(fila->final == TAMANHO){
        puts("Overflow");
    }else{
        //adiciona no final da fila
        fila->v[fila->final] = elemento;
        fila->final += 1;
    }
}

//retorna se a fila está vazia
int estaVazia(fila_t fila){
    printf("inicio:%d final:%d\n", fila.inicio, fila.final);
    return fila.inicio == fila.final;
}

//remove um elemento da fila
int removerDaFIla(fila_t *fila){
    int aux;
    if(estaVazia(*fila)){
        puts("Underflow!");
    }else{
        aux = fila->v[fila->inicio];
        fila->inicio++;
        return aux;
    }
}

//imprimir fila
void printFila(fila_t fila){
    int i;
    for(i = fila.inicio; i < fila.final; i++){
        printf("%d ->", fila.v[i]);
    }
    printf("\n");
}