#include <stdlib.h>
#include <stdio.h>
#define TAMANHO_MAXIMO 10
typedef struct 
{
   int elementos[TAMANHO_MAXIMO];
   int topo;
}pilha_t;
//prototipos
void empilhar(pilha_t *pilha, int elemento);
void topo(pilha_t pilha);
int desempilhar(pilha_t *pilha);
//main
int main(int argc, char const *argv[])
{
    /* code */
    pilha_t pilha;
    pilha.topo = -1;
    empilhar(&pilha, 48);
    empilhar(&pilha, 4);
    empilhar(&pilha, 7);
    topo(pilha);
    desempilhar(&pilha);
    topo(pilha);
    desempilhar(&pilha);
    topo(pilha);
    desempilhar(&pilha);
    topo(pilha);
    desempilhar(&pilha);

    return 0;
}

//insere na pilha
void empilhar(pilha_t *pilha, int elemento){
    if(pilha->topo +1 == TAMANHO_MAXIMO){
        //cheia
        puts("Overflow!");
    }else{
        pilha->topo += 1;
        pilha->elementos[pilha->topo] = elemento;

    }
}

//remove elemento da pilha
int desempilhar(pilha_t *pilha){
    int aux;
    if(pilha->topo  == -1){
        puts("Underflow!");
    }else{
        aux = pilha->elementos[pilha->topo];
        pilha->topo --;
    }
    return aux;
}

//mostra o elemento do topo de pilha
void topo(pilha_t pilha){
    printf("%d\n", pilha.elementos[pilha.topo]);
}