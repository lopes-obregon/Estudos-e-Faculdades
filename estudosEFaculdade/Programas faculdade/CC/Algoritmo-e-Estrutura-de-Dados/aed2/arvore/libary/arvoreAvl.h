#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//estrutura da arvore avl
typedef struct s_noo{
    int32_t chave:28;
    int32_t bal:2;
    int32_t reservado:2; //sem uso
    struct s_no *esq;
    struct s_no *dir;

}Avl;

typedef struct s_arq_noo{
    int32_t chave:28;
    int32_t bal:2;
    uint32_t esq:1;
    uint32_t dir:1;
}ArqNo;
//insere em uma arvore avl
void insertAvl(int x, Avl **pt, unsigned short h);
//procedimento que inicia o nó
void inicioNo(Avl **pt, int x);
//caso 1
//rotação direita ou dubla direita
void caso1(Avl *pt, unsigned short h);
//rotação esquerda e depla direita
void caso2(Avl *pt, unsigned short h);

#endif // ARVOREAVL_H_INCLUDED
