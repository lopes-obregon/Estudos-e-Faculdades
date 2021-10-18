//programa que empilha e desempilha esta vazia e topo
#include<stdio.h>
#include<stdlib.h>
#define MAXPILHA 10
typedef struct{
    int itens[MAXPILHA];
    int topo;
}pilha_t;
//protótipos
//inicializa a pilha
void inicializar(pilha_t *pilha);
//empilha
void push(pilha_t *pilha, int x);
//verifica o tamanho da pilnha
int tamanhoPilha(pilha_t *pilha);
//remove elemento da pilha
int pop(pilha_t *pilha);
//retorna o index do topo 
int esta_vazia(pilha_t *pilha);
//retorna o elemento do topo
int topo(pilha_t *pilha);
int main(int argc, char const *argv[])
{
    pilha_t *pilha;
    int i, x;
    pilha = (pilha_t *) malloc(sizeof(pilha_t));
    inicializar(pilha);
    push(pilha, 33);
    printf("elemento da pilha %d\n",  topo(pilha));
    printf("valor do indicie do topo %d\n", esta_vazia(pilha));
    push(pilha, 7);
    printf("elemento da pilha %d\n",  topo(pilha));
    printf("valor do indicie do topo %d\n", esta_vazia(pilha));
    push(pilha, 11);
    printf("elemento da pilha %d\n",  topo(pilha));
    printf("valor do indicie do topo %d\n", esta_vazia(pilha));
    pop(pilha);
    printf("elemento da pilha %d\n",  topo(pilha));
    printf("valor do indicie do topo %d\n", esta_vazia(pilha));
    pop(pilha);
    printf("elemento da pilha %d\n",  topo(pilha));
    printf("valor do indicie do topo %d\n", esta_vazia(pilha));
    push(pilha, 2);
    printf("elemento da pilha %d\n",  topo(pilha));
    printf("valor do indicie do topo %d\n", esta_vazia(pilha));
    free(pilha);
    /* code */
    return 0;
}
void inicializar(pilha_t *pilha){
    pilha->topo = -1;
}
void push(pilha_t *pilha, int x){
    if(tamanhoPilha(pilha) == MAXPILHA){
        printf("\nOverflow!\n");
    }else{
        pilha->topo += 1;
        pilha->itens[pilha->topo] = x;

    }
}
int tamanhoPilha(pilha_t *pilha){
    return pilha->topo+1;
}
int pop(pilha_t *pilha){
    int x;
    if(esta_vazia(pilha) == -1){
        printf("\nUnderflow!\n");
    }else{
        x = pilha->itens[pilha->topo];
        //remove elemento do topo
        pilha->topo -= 1;
        //retorna a copia do topo
        return x;
    }
}
int esta_vazia(pilha_t *pilha){
    return pilha->topo;
}
int topo(pilha_t *pilha){
    if(esta_vazia(pilha) == -1){
        printf("\nUnderflow\n");
    }else{
        return pilha->itens[pilha->topo];
    }
}
