#include "lista.h"
//concatena as string
void strConcatenar(char *str, char *str2){
    int tamanhoStr = strlen(str);
    for(int j = 0; j < strlen(str2); j++){
        str[tamanhoStr+j] = str2[j];
        if(j+1 == strlen(str2) && strlen(str2) > 1 ){
            str[strlen(str2)+1] = '\0';
        }else{
            str[tamanhoStr+1] = '\0';

        }
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
