#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int value;
    struct no *prox;

}No;

//insere valor no no
void insertNo(int x, No ** ptl){
    No *neww = malloc(sizeof(No));
    neww->value = x;
    if(*ptl == NULL){
        neww->prox = NULL;
        *ptl = neww;
    }else{
            neww->prox = *ptl;
            *ptl = neww;

    }


}
//função que finaliza a lista
void clearList(No **ptl){
    No *pt = *ptl;
    No *ptOld;
    while(pt != NULL){
        ptOld = pt;
        pt = pt->prox;
        free(ptOld);
    }
    printf("Lista vazia");
    printf("\n\n");
}
//imprime a lista
void printList(No *ptl){
 if(ptl != NULL){
    //printf("[%i]->",ptl->valor);
    //printList(ptl->prox);
    printf("[%i]->", ptl->value);
    printList(ptl->prox);
 }else{
    printf("\n\n");

 }
}
//função de busca
/*
struct no*   busca(int x, No *ptl){

    if(ptl->value == x){
        return ptl->value;
    }
    if(ptl->prox != NULL){
        return busca(x, ptl->prox);
    }
    return NULL;

}*/
//função de busca
struct no*   busca(int x, No *ptl){
    No *ant = ptl;
    No *ptr = ptl->prox;
    ptl = NULL;
    while(ptr != NULL){
        if(ptr->value != x){
            ant = ptr;
            ptr = ptr->prox;

        }else{
            if(ptr->value == x){
                ptl = ptr;
                ptr = NULL;
            }
        }
    }

    return ptl->value;

}
//remoção da lista
/*struct no* removeList(int x, No **ptl){
    No *pt = *ptl;
    if(pt != NULL){
        if(busca(x, pt) == x){
            return pt->value;
            free(pt);
        }

    }
}*/
//remoção
struct no* removeList(int x, No *ptl){
    No *ant = ptl;
    int valueBack = 0;
    No *ptr = ptl->prox;
    ptl = NULL;
    //busca
    while(ptr != NULL){
        if(ptr->value != x){
            ant = ptr;
            ptr = ptr->prox;

        }else{
            if(ptr->value == x){
                //remove
                ant->prox = ptr->prox;
                valueBack = ptr->value;
                printf("Valor removido: %d\n", valueBack);
                free(ptr);
                ptr = NULL;

            }
        }
    }

};
int main()
{
    No *ptLista = NULL;//lista vazia
    printf("Lista vazia ->");
    printList(ptLista);
    printf("\n");
    insertNo(3, &ptLista);
    insertNo(30, &ptLista);
    insertNo(50, &ptLista);
    printList(ptLista);
    printf("valor buscado: %i\n", busca(30,ptLista));
    //printf("valor removido: %i\n", removeList(30,&ptLista));
    removeList(30, ptLista);
    printList(ptLista);
    clearList(&ptLista);
    return 0;
}
