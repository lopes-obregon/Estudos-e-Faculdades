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
                    return buscaArvore(x, &(*pt), &f);
                }
            }else{
                if((*pt)->dir == NULL){
                    //não encontrado a direita
                    *f = 3;
                }else{
                    *pt = (*pt)->dir;
                    return buscaArvore(x, &(*pt), &f);

                }
            }
        }
    }

}
//insere na Arvore
void insertArvore(int x, No_ab **pt, unsigned int f){
    No_ab *aux = *pt;//variavel para armazenar a raiz da arvore
    buscaArvore(x, pt, &f);
    if(f == 1){
            //já existe na arvore o valor
        printf("Inserção inválida!\n");
    }else{
        //aloca memoria
        No_ab *neww = malloc(sizeof(No_ab));
        neww->value = x;
        neww->dir = neww->esq = NULL;
        if(f == 0 ){
            //arvore vazia
             *pt = neww;
        }else{
            if( f == 2 ){
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
