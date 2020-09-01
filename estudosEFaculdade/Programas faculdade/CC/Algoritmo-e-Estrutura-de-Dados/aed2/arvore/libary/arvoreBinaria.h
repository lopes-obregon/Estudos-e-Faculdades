#ifndef ARVOREBINARIA_H_INCLUDED
#define ARVOREBINARIA_H_INCLUDED
typedef struct no_ab{
    int value;
    struct no_ab *dir, *esq;
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
#endif // ARVOREBINARIA_H_INCLUDED
