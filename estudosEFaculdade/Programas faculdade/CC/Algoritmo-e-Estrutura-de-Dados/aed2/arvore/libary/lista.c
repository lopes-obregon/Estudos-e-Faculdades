#include "lista.h"
//concatena as string
void addBin(char *str){
    int tamanhoStr = strlen(str);
    char bin[4] = ".bin";
    for(int j = 0; j < strlen(bin); j++){
        str[tamanhoStr+j] = bin[j];
    }
}
//função que aloca o nó na memoria
void reservaMemoria(arqNo **pt, int32_t chave, uint32_t esq, uint32_t dir){
    arqNo *neww = malloc(sizeof(arqNo));
    //caso o ponteiro esteja apontado para lugar nem um aloca na memória o espaço referente ao endereço procurado
    if(*pt == NULL){
        neww->chave = chave;
        neww->esq = esq;
        neww->dir = dir;
        *pt = neww;

    }
}
//função que escreve no arquivo
void escreveNoArquivo(arqNo **pt, FILE *fp){
    fwrite(*pt, sizeof(arqNo), 1, fp);
    free(*pt);
    *pt = NULL;

}
