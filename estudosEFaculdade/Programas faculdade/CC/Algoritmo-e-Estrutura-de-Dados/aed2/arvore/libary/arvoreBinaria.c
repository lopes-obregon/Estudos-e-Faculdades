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
//procedimento que aloca o nó para a arvore
void devolveChave( arqNo conteudo, FILE *file, No_ab **pt){
    //fazendo a leitura do proximo nó
    //que é filho do nó atual
    No_ab *neww = malloc(sizeof(No_ab));
    neww->dir = neww->esq = NULL;
    if(fread(&conteudo, sizeof(arqNo), 1, file)){
       neww->value = conteudo.chave;
       *pt = neww;

    }


}
//pré ordem

//procedimento leitura em pré-ordem apartir de um arquivo
void leituraPreOrdemArquivo(No_ab **ptArvore, No_ab **ptRaiz, FILE *fp){
    //aloca nó para receber o conteudo do arquivo
    arqNo *conteudo = malloc(sizeof(arqNo));
    //lendo os dados do arquivo
    if(fread(conteudo, sizeof(arqNo), 1, fp) == 0){
        //se chegou no final do arquivo libera a memoria alocada, e retorna recursivamente
        free(conteudo);
        return;

    }
     //aloca a estrutura do tipo No_ab
    No_ab *neww = malloc(sizeof(No_ab));
    neww->dir = neww->esq = NULL;
    //se não tem raiz então o ponteiro da raiz aponta para o novo nó
    //novo nó recebe a chave do conteudo do arquivo
    neww->value = conteudo->chave;
    if(*ptRaiz == NULL){
        *ptRaiz = neww;
    }
    *ptArvore = neww;
    /*
    *procedimento pre()
    *    visita;;
    *    se pt^.esq != lambda pre(pt^.esq)
    *    se pt^.dir != lambda pre(pt^.dir)
    *se ptRaiz != lambda então pre(ptRaiz)

*/

    //ponteiro esquerdo
    //se tem filho a esquerdo chama a função novamente para alocar esse filho
    if(conteudo->esq != 0){
        leituraPreOrdemArquivo(&(*ptArvore)->esq, ptRaiz, fp);
    }
    //ponteido da direita
    if(conteudo->dir != 0){
        leituraPreOrdemArquivo(&(*ptArvore)->dir, ptRaiz, fp);
    }else{
        //se direito for lambda então desaloca conteudo
        free(conteudo);
    }
}
//procedimento que imprime a arvore em pre ordem
void printArvorePre(No_ab **pt, arqNo **ptCabeca, FILE *fp){
    //variavel  para armazenar verdadeuiro ou falso 1-verdadeiro 0-para falso
    uint32_t esq;
    uint32_t dir;
    esq = dir = 0;
    if(*pt == NULL){
        return;
    }else{
        if(((*pt)->esq && (*pt)->dir) != NULL){
            esq = dir = 1;
        }else{
            if((*pt)->esq != NULL){
                esq = 1;
            }else{
                if((*pt)->dir != NULL){
                    dir = 1;
                }

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
//função que deleta o item da arvore
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


