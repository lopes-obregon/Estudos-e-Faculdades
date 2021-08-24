#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lista.h"
#include "arvoreAvl.h"
/*typedef struct no_ab{
    int value;
    struct no_ab *dir, *esq;
}No_ab;*/

typedef struct s_no{
    int32_t value:30;
    int32_t reservado:2;
    struct s_no *esq, *dir;


}No_ab;
//tipo de dado definido como No_ab para fins de estudo, para não me confudir

//procedimento que faz a busca na arvore
void buscaArvore(int x, Avl **pt, unsigned int *f);
//f deve vir da busca realizada na arvore
void insertArvore(int x, No_ab **pt, unsigned int *f);
//imprime a arvore em pré ordem
void printArvorePre(Avl **pt, arqNo **ptCabeca, FILE *fp);
//remove a arvore
void removeTree(Avl **pt, int x, unsigned int *f);
//pesquisa na arvore com o anterior
void searchAntTree(Avl **pt, Avl **ant, unsigned int *f, int value);
//acha sucessor
void sucessor(Avl **pt, No_ab **ant, int x);
//função que limpa a ARVORE
void clearTree(Avl **pt);
//procedimento leitura em pré-ordem apartir de um arquivo
void leituraPreOrdemArquivo(Avl**ptArvore, Avl **ptRaiz, FILE *fp);
//procedimento que imprime a arvore no terminal
void printTerminal(Avl *ptArvore);
#endif // ARVOREBINARIA_H_INCLUDED
