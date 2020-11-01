#include "arvoreAvl.h"
//caso 2
//rotação esquerda e depla direita
void caso2(Avl **pt, bool *h){
    Avl *ptu = (*pt)->esq;
    //rotação simples direita
    if(ptu->bal == 1){
        (*pt)->esq = ptu->dir;
        ptu->dir = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }else{
        //rotação dupla direita
        Avl *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = *pt;
        if(ptv->bal == 1){
            (*pt)->bal = -1;
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
    *h = false;
}



//caso 1
//rotação direita ou dubla direita
void caso1(Avl **pt, bool *h){
    Avl *ptu = (*pt)->dir;
    //rotação direita
    if(ptu->bal == -1){
       (*pt)->dir  = ptu->esq;
        ptu->esq  = *pt;
        (*pt)->bal = 0;
        *pt = ptu;
    }else{
        //rotação dupla direita
            Avl *ptv = ptu->esq;
            ptu->esq = ptv->dir;
            ptv->dir = ptu;
            (*pt)->dir = ptv->esq;
            ptv->esq = *pt;
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

        }
    (*pt)->bal = 0;


    *h = false;

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
void insertAvl(int x, Avl **pt, bool *h){
    if (*pt == NULL){
        inicioNo(&(*pt), x);
        *h = true;
    }else{
        if( x == (*pt)->chave){
            //pare
            printf("Valor já existe");
        }else{
             if(x < (*pt)->chave){
                insertAvl(x, &(*pt)->esq, h);
                if(*h){
                    switch ((*pt)->bal){
                    case -1:
                        (*pt)->bal = 0;
                        break;
                    case 0:
                        (*pt)->bal =  1;
                        break;
                    default:
                        caso2(&(*pt), h);
                    }
                }

            }else{
                insertAvl(x, &(*pt)->dir, h);
               if(*h){
                    switch ((*pt)->bal){
                        case 1:
                            (*pt)->bal = 0;
                            break;
                        case 0:
                            (*pt)->bal =  -1;
                            break;
                        default:
                            caso1(&(*pt), h);
                    }
               }
            }
        }

    }

}
//  caso 1 remove
caso1Remove(Avl **pt, bool *h){
    Avl *ptu = (*pt)->dir;
    if(ptu->bal >= 0){
        //rotação esquerda
        (*pt)->dir = ptu->esq;
        ptu->esq = (*pt);
         if (ptu->bal == 0) {
            ptu->bal = -1;
            *h = false;
        } else {
            ptu->bal = 0;
            (*pt)->bal = 0;
        }
        (*pt) = ptu;
    }else{
        //rotação dupla esquerda
        Avl *ptv = ptu->esq;
        ptu->esq = ptv->dir;
        ptv->dir = ptu;
        (*pt)->dir = ptv->esq;
        ptv->esq = *pt;
        if(ptv->bal == 1){
            (*pt)->bal = 0;
        }else{
            (*pt)->bal = 0;
        }
        if(ptv->bal == -1){
            ptu->bal = 1;
        }
        (*pt) = ptv;
        ptv->bal = 0;
    }
}
//caso 2 rotação dupla direita
void caso2Remove(Avl **pt, bool *h){
    Avl *ptu = (*pt)->esq;
    //rotação simples esquerda
    if(ptu->bal <= 0){
        (*pt)->esq = ptu->dir;
        ptu->dir = (*pt);
        if(ptu->bal == 0){
            ptu->bal = 1;
            *h = false;
        }else{
            ptu->bal = 0;
            (*pt)->bal = 0;
        }
        (*pt) = ptu;
    }else{
        //rotação dupla esquerda
        Avl *ptv = ptu->dir;
        ptu->dir = ptv->esq;
        ptv->esq = ptu;
        (*pt)->esq = ptv->dir;
        ptv->dir = *pt;
        if(ptv->bal == -1){
            (*pt)->bal = 1;
        }else{
            (*pt)->bal = 0;
        }
        if(ptv->bal == 1){
            ptu->bal = -1;
        }else{
            ptu->bal = 0;
        }
        (*pt) = ptv;
        ptv->bal = 0;
    }
}
//sucessor
void sucessorAvl(Avl **pt, Avl **ptSucessor, bool *h, int x, Avl **ant, Avl **antSucessor){
    if((*ptSucessor)->esq == NULL){
        //achou o sucessor
        /*pt = *ptSucessor;
        *ptSucessor = (*ptSucessor)->dir;
        *h = true;*/
        //se sucessor folha então recebe os filhos de pt
        if(((*ptSucessor)->esq && (*ptSucessor)->dir) == NULL){
            if((*pt)->esq != *ptSucessor){
                (*ptSucessor)->esq = (*pt)->esq;
            }else{
                if((*pt)->dir == *ptSucessor){
                    (*ptSucessor)->dir = (*pt)->dir;
                }
            }
            (*antSucessor)->esq = NULL;
        }
        if(x < (*ant)->chave){
            //então sucessor pertence ao lado esquerdo
            (*ant)->esq = *ptSucessor;
        }else{
            //pertence ao lado direito
            (*ant)->dir = *ptSucessor;
        }
        *pt = *ptSucessor;
        *h = true;
    }else{
        sucessorAvl(&(*pt), &(*ptSucessor)->esq, h, x, &(*ant), &(*ptSucessor));
        if(*h == true){
            switch((*ptSucessor)->bal){
                case -1:
                    (*ptSucessor)->bal = 0;
                    break;
                case 0:
                    (*ptSucessor)->bal = 1;
                    *h = false;
                    break;
                default:
                    caso1Remove(&(*ptSucessor), h); //rebalanço
                    break;
            }
        }
    }

}
// remoção da arvore Avl
void removeAvl(int x, Avl **pt, Avl **ant,  bool *h){
    //se o elemento for igual a chave da onde aponta então remova
    if(x == (*pt)->chave){
        //caso o valor a ser removido seja uma folha
        if(((((*pt)->esq) && ((*pt)->dir) ) == NULL)){
            //se x < ant  o valor a ser removido é da esquerda senão ele pertence a direita
            if(x < (*ant)->chave){
                (*ant)->esq = NULL;
            }else{
                //x pertence a direita
                (*ant)->dir = NULL;
            }
             //remoção aconteceu
            *h = true;
            free(*pt);
        }else{
            //caso onde tem apenas um filho esquerdo
            if((*pt)->dir == NULL){
                 //reutilizando variavel anterior
                *ant = (*pt)->esq;
                //remoção aconteceu
                *h = true;
                free(*pt);
            }else{
                //tem apenas filho direito
                if((*pt)->esq == NULL){
                    *ant = (*pt)->dir;
                     //remoção aconteceu
                    *h = true;
                    free(*pt);
                }else{
                    // o nó a ser removido tem dois filhos
                    Avl *aux = (*pt);
                    Avl *ptAntSucessor = *pt;
                    sucessorAvl(&(*pt), &aux->dir, h, x, &(*ant), &ptAntSucessor);
                    if(*h == true){
                        switch((*pt)->bal){
                            case 1:
                                (*pt)->bal = 0;
                                break;
                            case 0:
                                (*pt)->bal = -1;
                                *h = false;
                                break;
                            default:
                                //rebalanciamento
                                caso2Remove(&(*pt), h);
                                break;
                        }
                    }
                     //remoção aconteceu
                    *h = true;
                    free(aux);
                }
            }
        }


    }else{
        //x menor que a chave
        if(x < (*pt)->chave){
            if((*pt)->esq != NULL){
                removeAvl(x, &(*pt)->esq, &(*pt), h);
                  if(*h == true){
                        switch ((*pt)->bal){
                        case -1:
                            (*pt)->bal = 0;
                            break;
                        case 0:
                            (*pt)->bal =  1;
                            *h = false;
                            break;
                        default:
                            caso2Remove(&(*pt), h);
                        }
                    }
            }
        }else{
            //valor é maior que a chave
            if((*pt)->dir != NULL){
                removeAvl(x, &(*pt)->dir, &(*pt), h);
                if(*h == true){
                    switch ((*pt)->bal){
                        case 1:
                            (*pt)->bal = 0;
                            break;
                        case 0:
                            (*pt)->bal =  -1;
                            *h = false;
                            break;
                        default://caso -1
                            caso1Remove(&(*pt), h);
                        }
                   }
            }
        }

    }

}
