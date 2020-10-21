#include "arvoreAvl.h"
//caso 2
//rotação esquerda e depla direita
void caso2(Avl **pt){
    Avl *ptu = (*pt)->dir;
    //rotação esquerda
    if(ptu->bal == 1){
        (*pt)->dir = ptu->esq;
        (*pt)->bal = 0;
        ptu->esq = *pt;
        *pt = ptu;
    }else{
        //rotação dupla esquerda
        Avl *ptv = (*pt)->esq;
        ptu->esq = ptv->dir;
        (*pt)->dir = ptv->esq;
        ptv->dir = ptu;
        ptv->esq = *pt;
        if(ptv->bal == 1){
            (*pt)->bal -1;
        }else{
            (*pt)->bal = 0;
        }
        if(ptv->bal == -1){
            ptu->chave = 1;
        }else{
            ptu->bal = 0;
        }
        *pt = ptv;
    }
    (*pt)->bal = 0;
}



//caso 1
//rotação direita ou dubla direita
void caso1(Avl **pt){
    Avl *ptu = (*pt)->esq;
    //rotação direita
    if(ptu->bal == -1){
       (*pt)->esq  = ptu->dir;
        ptu->dir  = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }else{
        //rotação dupla direita
        if(ptu->dir != NULL){
            Avl *ptv = ptu->dir;
            ptu->dir = ptv->esq;
            (*pt)->esq = ptv->dir;
            ptv->esq = ptu;
            ptv->dir = *pt;
            if(ptv->bal == -1){
                (*pt)->bal  = 1;
            }else{
               (*pt)->bal = 0;
            }
            if(ptv->bal == 1){
                ptu->bal = -1;
            }else{
                ptu->bal = 0;
            }
            *pt = ptv;
            (*pt)->bal = 0;
        }
        }

}
//procedimento que inicia o nó
void inicioNo(Avl **pt, int x){
    //ocupar
    //aloca espaço na memória
    Avl *neww = malloc(sizeof(Avl));
    //esq e direito recebe lambda
    neww->esq = NULL;
    neww->dir = NULL;
    //balanço recebe zero
    neww->bal = 0;
    neww->chave = x;
    //pt aponta para o novo nó
    neww->bal = 0;
    *pt = neww;
}
//procedimento que insere na arvore avl
//obs: 0-falso 1-verdadeiro
void insertAvl(int x, Avl **pt){
    if (*pt == NULL){
        inicioNo(&(*pt), x);
    }else{
        if( x == (*pt)->chave){
            //pare
            printf("Valor já existe");
        }else{
             if(x < (*pt)->chave){
                insertAvl(x, &(*pt)->esq);
                switch ((*pt)->bal){
                    case 1:
                        (*pt)->bal = 0;
                        break;
                    case 0:
                        (*pt)->bal =  -1;
                        break;
                    default:
                        caso1(&(*pt));
                }

            }else{
                insertAvl(x, &(*pt)->dir);
                switch ((*pt)->bal){
                    case -1:
                        (*pt)->bal = 0;
                        break;
                    case 0:
                        (*pt)->bal =  1;
                        break;
                    default:
                        caso2(&(*pt));
                }
            }
        }

    }

}
//alutra esquerda avl;
//verifica a arvore
void verificaAvl(Avl **pt){
    if(*pt == NULL){
        return;
    }
    verificaAvl(&(*pt)->esq);
    if((*pt)->bal == -1){
        caso1(&(*pt));
    }else{
        if((*pt)->bal == 1){
            caso2(&(*pt));
        }
    }
    verificaAvl(&(*pt)->dir);

}
