#include "arvoreAvl.h"
//caso 2
//rotação esquerda e depla direita
void caso2(Avl **pt, unsigned short *h){
    Avl *ptu = (*pt)->dir;
    if(ptu->bal == 1){
        (*pt)->dir = ptu->esq;
        (*pt)->bal = 0;
        ptu->esq = *pt;
        *pt = ptu;
    }else{
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
    *h = 0;
}



//caso 1
//rotação direita ou dubla direita
void caso1(Avl **pt, unsigned short *h){
    Avl *ptu = (*pt)->esq;
    if(ptu->bal == -1){
       (*pt)->esq  = ptu->dir;
        ptu->dir  = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }else{
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
        *h = 0;
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
    *pt = neww;
}
//procedimento que insere na arvore avl
//obs: 0-falso 1-verdadeiro
void insertAvl(int x, Avl **pt, unsigned short *h){
    if (*pt == NULL){
        inicioNo(&(*pt), x);
        *h  = 1;
    }else{
        if( x == (*pt)->chave){
            //pare
            printf("Valor já existe");
        }
        if(x < (*pt)->chave){
            insertAvl(x, &(*pt)->esq, &h);
            if(*h == 1){
                switch ((*pt)->bal){
                    case 1:
                        (*pt)->bal = 0, h = 0;
                        break;
                    case 0:
                        (*pt)->bal = -1;
                        break;
                    case -1:
                        //caso1
                        caso1(&(*pt), &h);
                        break;
                }
            }
        }else{
            insertAvl(x, &(*pt)->dir, &h);
            if(h == 1){
                 switch ((*pt)->bal){
                    case 1:
                        (*pt)->bal = 0, *h = 0;
                        break;
                    case 0:
                        (*pt)->bal = -1;
                        break;
                    case -1:
                        //caso2
                        caso2(&(*pt), &h);
                        break;
                }
            }
        }
    }

}
