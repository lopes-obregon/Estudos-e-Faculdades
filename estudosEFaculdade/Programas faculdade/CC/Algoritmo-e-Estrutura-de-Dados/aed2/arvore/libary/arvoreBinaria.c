#include "arvoreBinaria.h"
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
//procedimento leitura em pré-ordem apartir de um arquivo
void leituraPreOrdemArquivo(No_ab **ptArvore, arqNo conteudo){
    //quando 0- tem alguem na esquerda ou direita quando 1-não tem ninguem;
    No_ab *aux = *ptArvore; //variavel para segurar a raiz
    No_ab *neww = malloc(sizeof(No_ab));
    neww->value = conteudo.chave;
    if(*ptArvore == NULL){
        //siginifica  que o conteúdo se refere a raiz
        neww->dir = neww->esq = NULL;
        //aux = neww;//recebe o valor da raiz;
        //0 para vazio, 1-para esquerdo, 2- para direito
        if(conteudo.esq == 0){
            neww->reservado = 1;
        }else{
            if(conteudo.dir == 0){
                neww->reservado = 2;
            }else{
                if((conteudo.esq && conteudo.dir) == 1){
                    neww->reservado = 0;
                }
            }
        }
        aux = neww;
    }else{
        if((*ptArvore)->esq != NULL){
            leituraPreOrdemArquivo(&(*ptArvore), conteudo);
        }else{
            if((*ptArvore)->dir != NULL){
                leituraPreOrdemArquivo(&(*ptArvore), conteudo);
            }
        }
        if((conteudo.esq && conteudo.dir) == 1){
            neww->esq = neww->dir = NULL;
            if((*ptArvore)->reservado == 1){
                //filho esquerdo de ptArvore
                (*ptArvore)->esq = neww;
            }else{
                if((*ptArvore)->reservado == 2){
                    //fiçho direito de ptArvore
                    (*ptArvore)->dir = neww;
                }
            }
        }else{
            if(conteudo.esq == 0){
                (*ptArvore)->esq = neww;
            }else{
                if(conteudo.dir == 0){
                    (*ptArvore)->dir = neww;
                }else{
                    if(conteudo.esq == 1){
                        neww->esq = NULL;
                    }else{
                        if(conteudo.dir == 1){
                            neww->dir = NULL;
                        }
                    }
                }
            }
        }
        *ptArvore = neww;
    }
    *ptArvore = aux;
}
//procedimento que imprime a arvore em pre ordem
void printArvorePre(No_ab **pt, arqNo **ptCabeca, FILE *fp){
    //variavel  para armazenar verdadeuiro ou falso 0-verdadeiro 1-para falso
    uint32_t esq;
    uint32_t dir;
    esq = dir = 1;
    if(*pt == NULL){
        return;
    }else{
        if((*pt)->esq != NULL){
            esq = 0;
        }else{
            if((*pt)->dir != NULL){
                dir = 0;
            }

        }


    }


    reservaMemoria(&ptCabeca, (*pt)->value, esq, dir);
    escreveNoArquivo(&ptCabeca, fp);
    printArvorePre(&(*pt)->esq, ptCabeca, fp);
    printArvorePre(&(*pt)->dir, ptCabeca, fp);
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
//acha sucessor
void sucessor(No_ab **pt, No_ab **ant, int x){
    if(pt == NULL){
        return;
    }else{
        if(x < (*pt)->value){
            *ant = *pt;
            *pt = (*pt)->esq;
            return sucessor(&(*pt), &(*ant), x+1);
        }else{
            if(x > (*pt)->value){
                *ant = *pt;
                *pt = (*pt)->dir;
                return sucessor(&(*pt), &(*ant), x+1);
            }else{
                if(x == (*pt)->value){
                    //achei o sucessor
                    return;
                }
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
        if(((*pt)->dir == NULL) && ((*pt)->esq) == NULL){
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
                if(aux->esq == *pt){
                    aux->esq = NULL;
                }
                free(*pt);
            }else{
                //caso 2.1: tem apenas um filho
                if((*pt)->dir == NULL){
                    aux->esq = (*pt)->esq;
                    if(aux->dir == (*pt)){
                        aux->dir = NULL;
                    }
                    free(*pt);

                }else{
                    //caso 3: tem filhos ambos os lados
                    if(((*pt)->esq != NULL) && ((*pt)->dir != NULL)){
                            /*
                            *encontrar o sucessor filho que está a direita
                            *Caso 3
                            */
                            if(x+1 == (*pt)->dir->value){
                                No_ab *aux2 = aux;//anterior a aux
                                aux = *pt;
                                *pt  = (*pt)->dir;
                                if((*pt)->esq == NULL){
                                    (*pt)->esq = aux->esq;
                                    if(aux2->dir == aux){
                                        aux2->dir = *pt;
                                    }else{
                                        if(aux2->esq == aux){
                                            aux2->esq = *pt;
                                        }
                                    }
                                    free(aux);
                                }

                            }else{
                            //caso 3.1
                                No_ab *aux2 = aux;
                                //sucessor maior
                                aux = *pt;
                                *pt = (*pt)->dir;
                                if(((*pt)->dir) == NULL && ((*pt)->esq) == NULL){
                                    //já achei o sucessor
                                    if(aux2->dir == aux){
                                        aux2->dir = *pt;
                                    }else{
                                        if(aux2->esq == aux){
                                            aux2->esq = *pt;
                                        }
                                    }
                                    if(aux->esq != NULL){
                                        (*pt)->esq = aux->esq;
                                    }else{
                                        if(aux->dir != NULL){
                                            (*pt)->dir = aux->dir;
                                        }
                                    }
                                    free(aux);
                                }else{
                                    //me garante o sucessor
                                    sucessor(pt, &aux, x+1);
                                    if(((*pt)->dir) == NULL && ((*pt)->esq) == NULL){
                                        //se trata de uma folha
                                        (*pt)->esq = aux2->esq;
                                        (*pt)->dir = aux2->dir;
                                        if(aux->dir == *pt){
                                            aux->dir = NULL;
                                        }else{
                                            if(aux->esq == *pt){
                                                aux->esq = NULL;
                                            }
                                        }
                                        free(aux2);
                                    }

                                }

                            }

                    }
                }
            }
        }
    }
    *pt = temp;
}
//função que limpa a ARVORE
void clearTree(No_ab **pt){
   //quando chega em folha ou nulo ele retorna nada
   if(*pt == NULL){
        return;
   }
   clearTree(&(*pt)->esq);
   clearTree(&(*pt)->dir);
   //remove o elemento conforme for chamanado mas na volta ou seja recursivamente;
   free(*pt);
   *pt = NULL;
}
