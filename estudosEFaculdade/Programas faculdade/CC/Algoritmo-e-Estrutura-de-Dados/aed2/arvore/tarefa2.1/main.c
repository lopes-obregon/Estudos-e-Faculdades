/*programa que chama as funções da arvore*/
#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"
typedef struct raizArvore{
    struct No_ab *raiz;
}RaizArvore;
int main()
{
    RaizArvore *ptRaiz = malloc(sizeof(RaizArvore));
    ptRaiz->raiz = NULL;
    int f;
    ptRaiz->raiz = insertArvore(4, ptRaiz->raiz, f);
    insertArvore(3, ptRaiz->raiz, f);
    insertArvore(2, ptRaiz->raiz, f);
    insertArvore(5, ptRaiz->raiz, f);
    insertArvore(10, ptRaiz->raiz, f);
    printArvorePre(ptRaiz->raiz);
    return 0;
}
