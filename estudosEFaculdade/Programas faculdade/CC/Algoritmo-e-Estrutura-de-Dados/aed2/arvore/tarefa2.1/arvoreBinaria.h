#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
typedef struct no_ab{
    int value;
    struct no_ab *dir, *esq;
}No_ab;
//procedimento que faz a busca na arvore
int  buscaArvore(int x, No_ab *pt, int f);
//f deve vir da busca realizada na arvore
No_ab *insertArvore(int x, No_ab *pt, int f);
//imprime a arvore em pré ordem
void printArvorePre(No_ab *pt);
#endif // ARVOREBINARIA_H_INCLUDED
