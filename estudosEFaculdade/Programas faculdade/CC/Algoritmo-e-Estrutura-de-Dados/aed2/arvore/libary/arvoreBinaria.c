#include "arvoreBinaria.h"
//busca na arvore
void buscaArvore(int x, Avl **pt, unsigned int *f){
    if(*pt == NULL){
            //a arvore é vazia
        *f = 0;
    }else{
        if(x == (*pt)->chave){
            //encontrou o valor
            *f = 1;


        }else{
            if(x < (*pt)->chave){
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
//pré ordem

//procedimento leitura em pré-ordem apartir de um arquivo
void leituraPreOrdemArquivo(No_ab **ptArvore, No_ab **ptRaiz, FILE *fp){
    //aloca nó para receber o conteudo do arquivo
    arqNo conteudo;
    //lendo os dados do arquivo
    if(fread(&conteudo, sizeof(arqNo), 1, fp)){
        //aloca a estrutura do tipo No_ab
        No_ab *neww = malloc(sizeof(No_ab));
        neww->dir = neww->esq = NULL;
        //se não tem raiz então o ponteiro da raiz aponta para o novo nó
        //novo nó recebe a chave do conteudo do arquivo
        neww->value = conteudo.chave;
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
        if(conteudo.esq != 0){
            leituraPreOrdemArquivo(&(*ptArvore)->esq, ptRaiz, fp);
        }
        //ponteido da direita
        if(conteudo.dir != 0){
            leituraPreOrdemArquivo(&(*ptArvore)->dir, ptRaiz, fp);
        }

    }else{
            return;

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
void searchAntTree(Avl **pt, Avl **ant, unsigned int *f, int value){
    if(*pt == NULL){
        //arvore vazia ou folha
        return;
    }else{
        if(value == (*pt)->chave){
            //então achou o valor
            *f = 1;
        }else{
            if(value < (*pt)->chave){
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
void sucessor(Avl **pt, No_ab **ant, int x){
   //se pt^.esq == lambda achei meu sucessor pq é o maior menor da arvore
   if((*pt)->esq == NULL){
        return;
   }else{
        //se x < pt^.valor então pesquiso o proximo menor que pt
        if(x < (*pt)->chave){
            *ant = *pt;
            *pt= (*pt)->esq;
            sucessor(&(*pt), &(*ant), x);
        }

   }

}
//função que deleta o item da arvore
void removeTree(Avl **pt, int x, unsigned int *f){
    //variavel para guardar a raiz
    Avl *temp= *pt;//varialvel para devolver a raiz
    Avl *ant = *pt;//variavel para armazenar o anterior do qual vai ser removido
    Avl *pts = *pt; //ponteiro que recebe o sucessor
    Avl *aux = *pt ;//variavel para armazenar o anterior do sucessor
    //função que busca o elemento a ser removido
    if(*pt == NULL){
        printf("Arvore vazia imposivel remover\n");
        return;
    }
    searchAntTree(pt,&ant, f, x);
    //se f = 1 então achou o valor a ser removido
    if(*f  == 1){
        //se o valor a ser removido simplesmente for folha simplesmente o remove
        if(((*pt)->esq == NULL) && ((*pt)->dir == NULL)){
            if((*pt)->chave < ant->chave){
                //filho esquerdo do anterior
                ant->esq = NULL;
                free(*pt);
            }else{
                ant->dir = NULL;
                free(*pt);
            }
        }else{
            if(((*pt)->esq == NULL) && ((*pt)->dir != NULL)){
                //tem apenas filho direito
                 if((*pt)->chave < ant->chave){
                    ant->esq = (*pt)->dir;
                    free(*pt);
                 }else{
                    ant->dir = (*pt)->dir;
                    free(*pt);
                 }

            }else{
                if(((*pt)->esq != NULL) && ((*pt)->dir == NULL)){
                    //tem apenas filho esquerdo
                    if((*pt)->chave < ant->chave){
                        ant->esq = (*pt)->esq;
                        free(*pt);
                    }else{
                        ant->dir = (*pt)->esq;
                        free(*pt);
                    }
                }else{
                    //tem filhos ambos os lados
                    pts = (*pt)->dir;
                    sucessor(&pts, &aux, x);
                    if((*pt)->chave < ant->chave){
                        //lado esquerdo do anterior caso tenha
                        //caso o sucessor seja uma folha
                        if((pts->esq == NULL) && (pts->dir == NULL)){
                            ant->esq = pts;
                            if(pts != (*pt)->dir){
                                pts->esq = (*pt)->esq;
                                pts->dir = (*pt)->dir;
                            }else{
                                pts->esq = (*pt)->esq;
                            }
                            //anterior do pts que sempre sai o sucessor da esquerda então o anterior do pts seu filho esquerdo recebe lambda
                            //se aux == a raiz valor igual da raiz
                            if(aux->chave != temp->chave){
                                aux->esq = NULL;
                            }

                           /* //se o enderço do esquerdo for o mesmo endereço do ponteiro sucessor (pts) então esquerdo recebe lambda
                            if(pts->esq == pts){
                                pts->esq = NULL;
                            }else{
                                //caso o direito seja igual recebe lambda
                                if(pts->dir == pts){
                                    pts->dir = NULL;
                                }
                            }*/
                            //anterior do pts que sempre sai o sucessor da esquerda então o anterior do pts seu filho esquerdo recebe lambda
                            free(*pt);
                        }else{
                            //tem apenas filho direito
                            if((pts->esq == NULL) && (pts->dir != NULL)){
                                ant->esq = pts;
                                //correção
                                if(aux != temp){
                                    pts->esq = (*pt)->esq;
                                    //se o endereço do filho esquerdo de aux igual a pts(filho de aux)
                                    if(aux->esq == pts){
                                        aux->esq = pts->dir;
                                        pts->dir = aux;
                                    }else{
                                        aux->esq = NULL;
                                    }
                                    //ajustaNo(&pts, &aux);
                                }else{
                                    pts->esq = (*pt)->esq;
                                }

                                free(*pt);
                            }else{
                                //tem apenas filho esquerdo
                                if((pts->esq != NULL) && (pts->dir == NULL)){
                                    ant->esq = pts;
                                    if(aux != temp){
                                        pts->dir = (*pt)->dir;
                                        //se o endereço do filho esquerdo de aux igual a pts(filho de aux)
                                        if(aux->dir == pts){
                                            aux->dir = pts->dir;
                                            pts->esq = aux;
                                        }else{
                                            aux->esq = NULL;
                                        }
                                        //ajustaNo(&pts, &aux);
                                    }else{
                                        pts->dir = (*pt)->dir;
                                    }
                                    free(*pt);
                                }
                            }
                        }
                    }else{
                        //lado direito da arvore
                        //caso o sucessor seja uma folha
                        if((pts->esq == NULL) && (pts->dir == NULL)){
                            ant->dir = pts;
                            if(pts != (*pt)->dir){
                                pts->esq = (*pt)->esq;
                                pts->dir = (*pt)->dir;
                            }else{
                                pts->esq = (*pt)->esq;
                            }

                            //anterior do pts que sempre sai o sucessor da esquerda então o anterior do pts seu filho esquerdo recebe lambda
                            //se aux == a raiz valor igual da raiz
                            if(aux->chave != temp->chave){
                                aux->esq = NULL;
                            }

                            free(*pt);
                        }else{
                            //tem apenas filho direito
                            if((pts->esq == NULL) && (pts->dir != NULL)){
                                ant->dir = pts;
                                //correção
                                if(aux != temp){
                                    pts->esq = (*pt)->esq;
                                    //ajustaNo(&pts, &aux);
                                        //se o endereço do filho esquerdo de aux igual a pts(filho de aux)
                                        if(aux->esq == pts){
                                            aux->esq = pts->dir;
                                            pts->dir = aux;
                                            }else{
                                                aux->esq = NULL;
                                            }
                                }else{
                                    pts->esq = (*pt)->esq;
                                }

                                free(*pt);
                            }else{
                                //tem apenas filho esquerdo
                                if((pts->esq != NULL) && (pts->dir == NULL)){
                                    ant->dir = pts;
                                    if(aux != temp){
                                        //ajustaNo(&pts, &aux);
                                         if(aux != temp){
                                            pts->dir = (*pt)->dir;
                                            //se o endereço do filho esquerdo de aux igual a pts(filho de aux)
                                            if(aux->dir == pts){
                                                aux->dir = pts->esq;
                                                pts->dir = aux;
                                            }else{
                                                aux->esq = NULL;
                                            }
                                        }
                                    }else{
                                        //anterior é a raiz
                                        pts->dir = (*pt)->dir;
                                    }

                                    free(*pt);
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("Valor Removido com Sucesso!\n");
    }else{
    //caso não tenha achado o valor a ser removido na arvore escreva a mensagem
    printf("Valor não encontrado na arvore!\n");
}

    *pt = temp;
}
//função que limpa a ARVORE
void clearTree(Avl **pt){
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
//procedimento que imprime a arvore no terminal
void printTerminal(No_ab *ptArvore){
    if(ptArvore == NULL)
        return;
    printf("[%i] ", ptArvore->value);
    printTerminal(ptArvore->esq);
    printTerminal(ptArvore->dir);

}

