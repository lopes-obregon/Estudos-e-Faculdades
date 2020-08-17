/*programa que chama as funções da arvore*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvoreBinaria.h"
typedef struct raizArvore{
    struct No_ab *raiz;
}RaizArvore;
int main()
{
    RaizArvore *ptRaiz = malloc(sizeof(RaizArvore));
    ptRaiz->raiz = NULL;
    int f;
    int valor;
    srand(time(NULL));
    valor = rand()%100;
    ptRaiz->raiz = insertArvore(valor, ptRaiz->raiz, f);
    for(int i = 0; i < 100 -1; i++){
        valor = rand()%100;
        insertArvore(valor, ptRaiz->raiz, f);
    }
    /*insertArvore(4, ptRaiz->raiz, f);
    insertArvore(3, ptRaiz->raiz, f);
    insertArvore(5, ptRaiz->raiz, f);
    insertArvore(25, ptRaiz->raiz, f);
    insertArvore(24, ptRaiz->raiz, f);
    insertArvore(26, ptRaiz->raiz, f);*/
    printArvorePre(ptRaiz->raiz);
    return 0;
}
