#include "arvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>
//busca na arvore
void buscaArvore(int x, No_ab **pt, unsigned int *f){
    if(*pt == NULL){
            //a arvore é vazia
        *f = 0;
    }else{
        if(x == (*pt)->value){
            //encontrou o valor
            *f = 1;


        }else{
            if(x < (*pt)->value){
                if((*pt)->esq == NULL){
                    //não encontrado do lado esquerdo
                    *f = 2;
                }else{
                    *pt = (*pt)->esq;
                    return buscaArvore(x, &(*pt), &(*f));
                }
            }else{
                if((*pt)->dir == NULL){
                    //não encontrado a direita
                    *f = 3;
                }else{
                    *pt = (*pt)->dir;
                    return buscaArvore(x, &(*pt), &(*f));

                }
            }
        }
    }

}
//insere na Arvore
void insertArvore(int x, No_ab **pt, unsigned int *f){
    No_ab *aux = *pt;//variavel para armazenar a raiz da arvore
    buscaArvore(x, pt, f);
    if(*f == 1){
            //já existe na arvore o valor
        printf("Inserção inválida!\n");
    }else{
        //aloca memoria
        No_ab *neww = malloc(sizeof(No_ab));
        neww->value = x;
        neww->dir = neww->esq = NULL;
        if(*f == 0 ){
            //arvore vazia
             *pt = neww;
        }else{
            if( *f == 2 ){
                //não encontrado da esquerda
                (*pt)->esq = neww;

            }else{
                //não encontrado na direita;
                (*pt)->dir = neww;
            }
            *pt = aux;
        }
    }

}
//procedimento que imprime a arvore em pre ordem
void printArvorePre(No_ab *pt){
    if(pt == NULL){
        return;
    }else{
        printf("%i ", pt->value);
        printArvorePre(pt->esq);
        printArvorePre(pt->dir);
    }

}
//função que busca o anterior
void searchAntTree(No_ab **pt, No_ab **ant, unsigned int *f, int value){
    if(*pt == NULL){
        //arvore vazia ou folha
        return;
    }else{
        if(value == (*pt)->value){
            //então achou o valor
            *f = 1;
        }else{
            if(value < (*pt)->value){
                *ant = *pt;
                *pt = (*pt)->esq;
                return searchAntTree(&(*pt), &(*ant), &(*f), value);
            }else{
                *ant = *pt;
                *pt = (*pt)->dir;
                return searchAntTree(&(*pt), &(*ant), &(*f), value);
            }

        }
    }

}
//função que deleta a arvore
void removeTree(No_ab **pt, int x, unsigned int *f){
    //variavel para guardar a raiz
    No_ab *temp = *pt;
    No_ab *aux = *pt;
    searchAntTree(pt,&aux, f, x);
    if(*f  == 1){
        //caso 1: valor a ser removido é uma folha
        if(((*pt)->esq  && (*pt)->dir) == NULL){
            if(aux->dir == (*pt)){
                aux->dir = NULL;
                free(*pt);
            }else{
                if(aux->esq == (*pt)){
                    aux->esq = NULL;
                    free(*pt);
                }
            }
        }else{
            //caso 2: tem apenas um filho
            if((*pt)->esq == NULL ) {
                //substitui pelo filho a direita
                aux->dir = (*pt)->dir;
                free(*pt);
            }else{
                //caso 2.1: tem apenas um filho
                if((*pt)->dir == NULL){
                    aux->esq = (*pt)->esq;
                    free(*pt);
                }
            }
        }
    }
    *pt = temp;
}
