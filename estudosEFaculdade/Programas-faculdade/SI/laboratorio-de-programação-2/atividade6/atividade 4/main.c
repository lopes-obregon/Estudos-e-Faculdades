//implementação de fila simples
#include<stdio.h>
#include<stdlib.h>
#define MAXFILA 6
typedef struct 
{
    int itens[MAXFILA];
    int inicio, final;
}fila_t;
//protótipos
//inicializa a fila
void inicializar(fila_t *fila);
//insere um elemento na fila
void enqueue(fila_t *fila, int element);
//remove da fila
int dequeue(fila_t *fila);
//mostra o primeiro elemento da fila sem remover
int primeiro(fila_t *fila);
//retorna o ultimo da fila
int ultimo(fila_t *fila);
//retorna o indicie do inicio da fila
int indicieInicio(fila_t *fila);
//retorna o indicie ultimo da fila
int indicieFinal(fila_t *fila);
//main
int main(int argc, char const *argv[])
{
    fila_t *fila;
    fila = (fila_t *) malloc(sizeof(fila_t));
    inicializar(fila);
    enqueue(fila, 33);
    printf("elemento da  primeira fila(%d) elemento do ultimo da fila(%d) indicie inicio(%d) e indicie final(%d)\n", primeiro(fila),
    ultimo(fila), indicieInicio(fila), indicieFinal(fila));
    enqueue(fila, 7);
    printf("elemento da  primeira fila(%d) elemento do ultimo da fila(%d) indicie inicio(%d) e indicie final(%d)\n", primeiro(fila),
    ultimo(fila), indicieInicio(fila), indicieFinal(fila));
    enqueue(fila, 11);
    printf("elemento da  primeira fila(%d) elemento do ultimo da fila(%d) indicie inicio(%d) e indicie final(%d)\n", primeiro(fila),
    ultimo(fila), indicieInicio(fila), indicieFinal(fila));
    dequeue(fila);
    printf("elemento da  primeira fila(%d) elemento do ultimo da fila(%d) indicie inicio(%d) e indicie final(%d)\n", primeiro(fila),
    ultimo(fila), indicieInicio(fila), indicieFinal(fila));
    dequeue(fila);
    printf("elemento da  primeira fila(%d) elemento do ultimo da fila(%d) indicie inicio(%d) e indicie final(%d)\n", primeiro(fila),
    ultimo(fila), indicieInicio(fila), indicieFinal(fila));
    enqueue(fila, 2);
    printf("elemento da  primeira fila(%d) elemento do ultimo da fila(%d) indicie inicio(%d) e indicie final(%d)\n", primeiro(fila),
    ultimo(fila), indicieInicio(fila), indicieFinal(fila));
    free(fila);
    return 0;
}
void inicializar(fila_t *fila){
    fila->inicio = -1;
    fila->final = 0;
}
void enqueue(fila_t *fila, int element){
    //adiciona o elemento na fila
    fila->itens[fila->final]  = element;
    //verifica se é a primeira inserção
    if(fila->inicio == -1){
        fila->inicio = 0;
    }
    //incrementa no final da fila
    fila->final +=1;
    //verifica se  a fila está cheia
    if(fila->final == MAXFILA)
    //circular
        fila->final = 0;
}
int esta_vazio(fila_t *fila){
    return fila->inicio == fila->final;
}
int dequeue(fila_t *fila){
    int value;
    if(esta_vazio(fila)){
        //fila vazia
        printf("\nUnderflow!\n");
        return -1;
    }
    //retira o elemento do nicio
    value = fila->itens[fila->inicio];
    //incrementa o inicio
    fila->inicio +=1;
    //verifica se antingiu o limite
    if(fila->inicio == MAXFILA){
        fila->inicio = 0;
    }

} 

int primeiro(fila_t *fila){
    if(esta_vazio(fila)){
        printf("\nUnderflow\n");
        return -1;
    }
    return fila->itens[fila->inicio];
}
int ultimo(fila_t *fila){
    int i;
    //ultimo eh o anterior ao indicie final
    i = fila->final - 1;
    //se final vale 0 então i é atribuido -1
    if( i == -1)
        //anterior a 0 é maxfila -1;
        i = MAXFILA - 1;
    return fila->itens[i];
}
int indicieInicio(fila_t *fila){
    return fila->inicio;
}
int indicieFinal(fila_t *fila){
    return fila->final;
}