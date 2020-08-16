#include "arvoreBinaria.h"
#include <stdio.h>
#include <stdlib.h>
//busca na arvore
int buscaArvore(int x, No_ab *pt, int f){
    if(pt == NULL){
            //a arvore é vazia
        //f = 0;
        return 0;
    }else{
        if(x == pt->value){
            //encontrou o valor
            //f = 1;
            return 1;

        }else{
            if(x < pt->value){
                if(pt->esq == NULL){
                    //não encontrado do lado esquerdo
                    //f = 2;
                    return 2;
                }else{
                    return buscaArvore(x, pt->esq, f);
                }
            }else{
                if(pt->dir == NULL){
                    //não encontrado a direita
                    //f = 3;
                    return 3;
                }else{
                    return buscaArvore(x, pt->dir, f);

                }
            }
        }
    }

}
//insere na Arvore
No_ab *insertArvore(int x, No_ab *pt, int f){
    f = buscaArvore(x, pt, f);
    int i = 0;//falso para avansar
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
             pt = neww;
        }else{
            //atualiza o ponteiro das arvores
             do{
            if(x < pt->value){
                if(pt->esq != NULL){
                    pt = pt->esq;
                    i = 1;
                }else{
                    i = 0;
                }
            }else{
                if(pt->dir != NULL){
                    pt = pt->dir;
                    i = 1;
                }else{
                    i = 0;
                }
            }

        }while(i != 0);
            if( f == 2 ){
                //não encontrado da esquerda
                pt->esq = neww;

            }else{
                //não encontrado na direita;
                pt->dir = neww;
            }
        }
    }
    return pt;
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
