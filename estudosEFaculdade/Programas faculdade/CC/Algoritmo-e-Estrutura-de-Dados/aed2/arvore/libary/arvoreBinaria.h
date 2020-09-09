#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*typedef struct no_ab{
    int value;
    struct no_ab *dir, *esq;
}No_ab;*/

typedef struct s_no{
    int32_t value:30;
    int32_t reservado:2;
    struct s_no *esq, *dir;


}No_ab;

//procedimento que faz a busca na arvore
void buscaArvore(int x, No_ab **pt, unsigned int *f);
//f deve vir da busca realizada na arvore
void insertArvore(int x, No_ab **pt, unsigned int *f);
//imprime a arvore em pré ordem
void printArvorePre(No_ab *pt);
//remove a arvore
void removeTree(No_ab **pt, int x, unsigned int *f);
//pesquisa na arvore com o anterior
void searchAntTree(No_ab **pt, No_ab **ant, unsigned int *f, int value);
//acha sucessor
void sucessor(No_ab **pt, No_ab **ant, int x);
//função que limpa a ARVORE
void clearTree(No_ab **pt);
#endif // ARVOREBINARIA_H_INCLUDED
