#include <stdio.h>
#include <stdlib.h>
#include <time.h>//biblioteca para gerar os valores aleatorios
typedef struct no{
    struct no *prox;
    int valor;
}No;
//limpa a lista
void clearList(No **ptl){
    No *pt = *ptl;
    No *ptold;
    while(pt != NULL){
        ptold = pt;
        pt = pt->prox;
        free(ptold);
    }


}
//impress�o da list
void printList(No *ptl){
   if(ptl != NULL){
    printf("[%i]->",ptl->valor);
    printList(ptl->prox);
   }else{
        printf("\n\n");
   }
}
//function para inserir dados na lista
void inserir(No **ptl, int value){
    No *neww = malloc(sizeof(No));
    if(neww == NULL){
        printf("Sem Mem�ria");
        return;
    }else{
        neww->valor = value;
        neww->prox = *ptl;
        *ptl = neww;
    }
}
//ordena lista
void ordena(No **ptl){
    No *pt = *ptl;
    int temp = 0;
    while(pt != NULL){
        No *aux = pt->prox;
        while(aux !=NULL){

            if(pt->valor > aux->valor){
                temp = pt->valor;
                pt->valor = aux->valor;
                aux->valor = temp;
            }
            aux = aux->prox;
        }
        pt = pt->prox;
    }
}

int main()
{
    No *ptlist = NULL;
    //parte que insere os valores na lista
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        inserir(&ptlist,rand() % 100);
    }
    //emprime a lista
    printList(ptlist);
    printf("\n");
    printf("Lista Ordenada\n");
    //ordena a lista
    ordena(&ptlist);
    printList(ptlist);
    printf("\n");
    //limpa a lista ou seja desaloca
    clearList(&ptlist);
    return 0;
}
