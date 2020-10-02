#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct s_arq_no{
    int32_t chave:30;
    uint32_t esq:1;
    uint32_t dir:1;

}arqNo;
//função que aloca o nó na memoria
void reservaMemoria(arqNo **pt, int32_t chave, uint32_t esq, uint32_t dir);
//concatena as string
void addBin(char *str);
//função que escreve no arquivo
void escreveNoArquivo(arqNo **pt, FILE *fp);
#endif // LISTA_H_INCLUDED
