#include <stdio.h>
#include <stdlib.h>
/**
*    Busca, inser��o e remo��o em lista simplesmente encadeada sem n� cabe�a ordenada;(ok)
*    Busca, inser��o e remo��o em lista circular simplesmente encadeada sem n� cabe�a ordenada;ok
*    Busca, inser��o e remo��o em lista duplamente encadeada com n� cabe�a (sem ordena��o);ok
*    Inser��o e remo��o em fila (FIFO);ok
*    Inser��o e remo��o em pilha (LIFO).ok

*/
//#define TAMANHO 100

//estrutura de dado da lista
typedef struct no{
    int value;
    struct no *prox;

}No;
//estutura de dado lista duplamente encadeada
typedef struct noDup{
    int value;
    struct noDup *prox;
    struct noDup *ant;
}NoDup;
typedef struct noDupC{
    struct noDup *inicio;
    struct noDup *fim;

}NoDupC;
//insere valor no no
void insertNo(int x, No ** ptl){
    No *neww = malloc(sizeof(No));
    neww->value = x;
    No *aux = *ptl;
    if(*ptl == NULL){
        neww->prox = NULL;
        *ptl = neww;
    }else{
            while(aux != NULL){
                if(aux->value > neww->value){
                    x = aux->value;
                    aux->value = neww->value;
                    neww->value = x;

                }
                aux = aux->prox;
            }
            neww->prox = *ptl;
            *ptl = neww;

    }


}
//fun��o que finaliza a lista
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
//fun��o de busca
int busca(int x, No *ptl){
    No *ant = ptl;
    //ponteiro cabe�a do n�
    //No *ptr = ptl->prox;
    No *ptr = ptl;
    ptl = NULL;
    while(ptr != NULL){
            //percurso da lista ou n�
        if(ptr->value > x){
            ant = ptr;
            ptr = ptr->prox;

        }else{
            if(ptr->value == x){
                //ptl recebe o n� onde ptr est� apontando;
                ptl = ptr;
                ptr = NULL;
                printf("Valor encontrado na lista\n");
            }
        }
    }

    return ptl->value;

}

//remo��o
void removeList(int x, No *ptl){

    int valueBack = 0;
    //No *ptr = ptl->prox;//aqui � o n� que aponta para a cabe�a do n�
    No *ant = ptl;
    No *ptr = ptl;
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

}
//opera��oes de lista circular simplesmente encadeada
//insiere na lista
void insertListCircle(int x, No **ptl, No *ptIni){
    No *neww = malloc(sizeof(No));
    neww->value = x;
    No *ultimoNoRegistrado = ptIni;//n� com o endere�o do ultimo n� registrado
    No *aux = ptIni; //endere�o do ultimo n� registrado
    //No *atual = ptIni;
    //lista vazia
    if(*ptl == NULL){
        neww->prox = *ptl;
        *ptl = neww;
    }else{
        neww->prox = *ptl;
        *ptl = neww;
        //significa que o primeiro valor n�o aponta para nada
        if(ultimoNoRegistrado->prox == NULL){
            ultimoNoRegistrado->prox = *ptl;
        }else{
                while(ultimoNoRegistrado != *ptl){
                    ultimoNoRegistrado = ultimoNoRegistrado->prox;
                    if(ultimoNoRegistrado->prox == aux){
                        ultimoNoRegistrado->prox = *ptl;
                        ultimoNoRegistrado = ultimoNoRegistrado->prox;
                    }
                }
            }

        }
    }
//fun��o que ordena a lista simplesmente ciruclar;
void ordena(No *ptl, No *inicio){
    int aux = 0;
    int x = 0;
    No *ptlAux = ptl;
    do{
        aux = ptlAux->value;
        ptl = ptl->prox;
        while(ptl != inicio){
            if(aux > ptl->value){
                //troca
                x = ptl->value;
                ptl->value = aux;
                aux = x;
                ptlAux->value = aux;
            }
            ptl = ptl->prox;
        }
        ptlAux = ptlAux->prox;
        ptl = ptlAux;
    }while(ptlAux != inicio);
}
//imprime a lista cirucular
void printLitCircle(No *ptl){
    No *aux = ptl;
    //imprimir o primeiro
    if(ptl == aux){
        printf("[%i]->", ptl->value);
        ptl = ptl->prox;
    }
   while(ptl != aux){
        printf("[%i]->", ptl->value);
        ptl = ptl->prox;
   }
    printf("\n\n");
}
//limpa a lista circular
void clearListCircle(No **ptl){
   No *aux = *ptl;
   No *pt = *ptl;
   pt = pt->prox;
   while(pt != aux){
    if(pt->prox == aux){
        pt->prox = aux->prox;
        free(aux);
        aux = pt->prox;
        pt = aux->prox;
    }else{
        pt = pt->prox;
    }

   }
   free(aux);

}
//fun��o que busca na lista circular
void searchListCircle(int x, No *ptl){
    int achou = -1;
    No *aux = ptl;
    do{
        if(ptl->value == x){
            //printf("Achou o valor\n");
            achou = 1;
            break;
        }else{
            ptl = ptl->prox;
        }
    }while(ptl != aux);
    if(achou == 1){
        printf("Achou\n");
    }else{
        printf("N�o achou\n");
    }
}
//remove da lista circular
void removeListCircle(int x , No *ptl){
    No * auxPt = ptl;//variavel para armazenar o inicio da lista e indicar que foi feito um ciclo
    No *ant = ptl;//variavel para acerta a lista, que grava o anteriror do n�
    No *rm = ptl;//variavel para armazenar o valor do dado a ser removido
    do{
        if(ptl->value != x){
            ant = ptl;
            ptl = ptl->prox;
        }else{
            rm = ptl;
            if(ptl->prox == auxPt){
                ant->prox = ptl->prox;
                ptl = ptl->prox;
                printf("Removido com sucesso!\n");
                free(rm);
            }else{
                ptl = rm->prox;
                ant->prox = ptl;
                printf("Removido com sucesso!\n");
                free(rm);
            }
        }
    }while(ptl != auxPt);


}
//fun��es da lista duplamente encadeada
void insertDup(int x, NoDupC *List){
    NoDup *neww = malloc(sizeof(NoDup));
    neww->value = x;
    NoDup *aux = List->inicio;
    if( List->inicio == NULL){
        neww->prox = neww->ant = NULL;
        List->inicio = List->fim = neww;
    }else{

        neww->prox = List->inicio;
        neww->ant = NULL;
        aux->ant = neww;
        List->inicio = neww;//aponta para o inicio da lista
    }

}
//busca duplamente encadeda
void searchListDup(NoDupC *List, int x){
    NoDup *aux = List->inicio;
    while(aux != NULL){
        if(aux->value == x){
            printf("Valor encontrado!\n");
            aux = List->fim;
        }else{
            aux = aux->prox;
        }
    }
}
//imprime a lista
void printDup(NoDupC *List){
    NoDup *aux = List->fim;
    while(aux != NULL){
        printf("[%d]->", aux->value);
        aux = aux->ant;
    }
    printf("\n\n");
}
//remove da lista
void removeListDup(NoDupC *List, int x){
    NoDup *aux = List->inicio;
    NoDup *rm;
    while(aux != NULL){
        if(aux->value == x){
            break;
        }else{
            aux = aux->prox;
        }
    }
    //significa que est�o no meio e n�o nas lateraos
    rm = aux;
    if((aux->prox && aux->ant) != NULL){
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux ->ant;
        free(rm);
        printf("Removido com sucesso!\n");

    }else{
        //siginigica que esta em uma das estremidades
        rm = aux;
        if(aux->ant == NULL){
            //significa que est� na  cabe�a
            List->inicio = aux->prox;
            aux->prox->ant = NULL;
            free(rm);
            printf("Removido com sucesso!\n");
        }else{
            if(aux->prox ==NULL){
                //significa que est� no fim da lista
                List->fim = aux->ant;
                aux->ant->prox = NULL;
                free(rm);
                printf("Removido com sucesso!\n");
            }
        }
    }
}
void clearDup(NoDupC *List){
    NoDup *aux = List->inicio;//recebe o endere�o da lista
    NoDup *cl;
    while(aux != NULL){
        cl = aux;
        aux = aux->prox;
        free(cl);
    }
}
//fila
//insere na fila
void insertFifo(NoDupC *fila, int x){
    NoDup *neww = malloc(sizeof(NoDup));
    neww->value = x;
    neww->ant = NULL;
    NoDup *aux = fila->fim;
    //primeiro endere�o da fila
    //fila ta vazia
    if(fila->fim == NULL){
        neww->prox = NULL;
        neww->ant = NULL;
        fila->inicio = fila->fim = neww;
    }else{
        neww->prox = aux;
        aux->ant = neww;
        fila->fim = neww;
    }
}
//imprime a fila
void printFifo(NoDupC *fila){
    NoDup *aux = fila->inicio;
    printf("FILA:");
    while(aux != NULL){
        printf("[%d]->", aux->value);
        aux = aux->ant;
    }
    printf("\n\n");
}
//remove fila //para liber toda a mem�ria basta chamar at� que esteja vazio
void removeFifo(NoDupC *fila){
    NoDup *aux = fila->inicio;//variavel para ser eliminada ou removida liberando espa�o
    if((fila->inicio || fila->fim) != NULL){
        //signigica que est� no final da lista
        if(fila->fim->prox == NULL){
            fila->inicio = fila->fim;
            free(aux);
            fila->inicio = fila->fim = NULL;

        }else{
            //caso dois n�o chegou no final da lista
            fila->inicio = aux->ant;
            fila->inicio->prox = NULL;
            free(aux);

        }

    }

}
//inserir na pilha
void insertLifo(NoDupC *pilha, int x){
    No *neww = malloc(sizeof(No));
    neww->value = x;
    No *aux = pilha->inicio;
    /*
    * pilha->inicio (inicio significa o topo da pilha
    */
    /*
    *pilha vazia
    *primeiro valor da pilha
    */
    if(pilha->inicio == NULL){
        neww->prox = NULL;
        pilha->inicio = neww;
    }else{
        //pilha est� com algum item ou algum valor
        neww->prox = aux;
        pilha->inicio = neww;


    }

}
//imprime a pilha
void printfLifo(NoDupC *pilha){
    No *aux = pilha->inicio;
    printf("Pilha:");
    while(aux != NULL){
            printf("[%d]->", aux->value);
            aux = aux->prox;
    }
    printf("\n\n");
}
//remove da pilha // para liberar toda a mem�ria alocada basta chamar varias vezes at� ficar vazio novamente
void removeLifo(NoDupC *pilha){
    No *aux = pilha->inicio;// inicio � o topo
    if(aux != NULL){
        pilha->inicio = aux->prox;
        free(aux);
    }

}
//menu lse
void menuLse(int *date, int tamVet){
    No *ptList = NULL;
    int op;
    int valor;
    do{
            if(ptList == NULL){
                for(int i = 0; i < tamVet; i++){
                    insertNo(date[i], &ptList);
                }
                printList(ptList);

            }else{
                printf("1-Buscar\n");
                printf("2-Remover\n");
                printf("3-Sair/escolher outro tipo de lista\n");
                scanf("%d", &op);
                if(op == 1){
                    printf("Informe o valor que deseja buscar: ");
                    scanf("%d", &valor);
                    busca(valor, ptList);
                }else{
                    if(op == 2){
                            printf("Informe o valor que deseja remover: ");
                            scanf("%d", &valor);
                            removeList(valor, ptList);
                            printList(ptList);
                    }

                }
            }


    }while(op !=3);
    clearList(&ptList);

}
//menu lista circular encadeada
void menuLcse(int *date, int tamVet){
    No *ptList = NULL;
    int op;
    int valor;
    do{
            if(ptList == NULL){
                for(int i = 0; i < tamVet; i++){
                    insertListCircle(date[i], &ptList, ptList);
                }
                ordena(ptList, ptList);
                printLitCircle(ptList);

            }else{
                printf("1-Buscar\n");
                printf("2-Remover\n");
                printf("3-Sair/escolher outro tipo de lista\n");
                scanf("%d", &op);
                if(op == 1){
                    printf("Informe o valor que deseja buscar: ");
                    scanf("%d", &valor);
                    searchListCircle(valor, ptList);
                }else{
                    if(op == 2){
                            printf("Informe o valor que deseja remover: ");
                            scanf("%d", &valor);
                            //removeList(valor, ptList);
                            removeListCircle(valor, ptList);
                             printLitCircle(ptList);
                    }

                }
            }


    }while(op !=3);
    clearListCircle(&ptList);
}
//menu lista Dup
void menuDup(int *date, int tamVet){
    NoDupC *ptCabeca = malloc(sizeof(NoDupC));
    ptCabeca->inicio = ptCabeca->fim = NULL;
    int op;
    int valor;
    for(int i = 0; i < tamVet; i++){
        insertDup(date[i], ptCabeca);
    }
    printDup(ptCabeca);
    do{

                printf("1-Buscar\n");
                printf("2-Remover\n");
                printf("3-Sair/escolher outro tipo de lista\n");
                scanf("%d", &op);
                if(op == 1){
                    printf("Informe o valor que deseja buscar: ");
                    scanf("%d", &valor);
                    searchListDup(ptCabeca, valor);
                }else{
                    if(op == 2){
                            printf("Informe o valor que deseja remover: ");
                            scanf("%d", &valor);
                            removeListDup(ptCabeca, valor);
                            printDup(ptCabeca);
                    }

                }



    }while(op !=3);
    clearDup(ptCabeca);

}
//menu pilha
void menuLifo(int *date, int tamVet){
    NoDupC *ptPilha = malloc(sizeof(NoDupC));
    ptPilha->inicio = NULL; //inicio ser� o topo;
    int op;
    int valor;
    for(int i = 0; i < tamVet; i++){
        insertLifo(ptPilha, date[i]);
    }
    printfLifo(ptPilha);
    do{
        printf("1-Remover\n");
        printf("2-Sair/escolher outro tipo de lista\n");
        scanf("%d", &op);
        if(op == 1){
            removeLifo(ptPilha);
            printfLifo(ptPilha);

        }
    }while(op != 2);
    //libera a memoria
    while(ptPilha->inicio != NULL){
        removeLifo(ptPilha);
    }
}
//menu de fila
void menuFifo(int *date, int tamVet){
    NoDupC *ptFila = malloc(sizeof(NoDupC));
    ptFila->inicio = ptFila->fim = NULL;
    int op;
    for(int i = 0; i < tamVet; i++){
        insertFifo(ptFila, date[i]);
    }
    printFifo(ptFila);
    do{
        printf("1-Remover\n");
        printf("2-Sair/escolher outro tipo de lista\n");
        scanf("%d", &op);
        if(op == 1){
           removeFifo(ptFila);
            printFifo(ptFila);

        }
    }while(op != 2);
    //libera a fila;
    while(ptFila->fim != NULL){
        removeFifo(ptFila);
    }
}
//menu
void menu(){
    int op;
    char aux = 'n';
    int tam  = 10; //variavel para o tamanho do vetor
    int valores[10];
    printf("Informe a quantidade de valores que deseja inserir na lista!\n");
    scanf("%d", &tam);
    valores[tam];
    printf("Qual os valores que deseja inserir nessa lista?\n");
    for(int i = 0; i < tam; i++){
        scanf("%d", &valores[i]);

    }
    do{
         printf("====================menu=============\n");
         printf("Qual tipo de dado gostaria de utilizar\n");
         printf("1- lista simplesmente encadeada\n");
         printf("2- lista circular simplesmente encadeada\n");
         printf("3- lista duplamente encadeada\n");
         printf("4- pilha\n");
         printf("5- fila\n");
         printf("0- sair\n");
         scanf("%d", &op);
         if(op != 0){
                
         }
        //lista simplesmente encadeada;
        if(op == 1){
            menuLse(valores, tam);
        }else{
            if(op == 2){
                menuLcse(valores, tam);
            }else{
                if(op == 3){
                    menuDup(valores, tam);
                }else{
                    if(op == 4){
                        menuLifo(valores, tam);
                    }else{
                        if(op == 5){
                            menuFifo(valores, tam);
                        }
                    }
                }
            }
        }
    }while(op != 0);
}

int main()
{
    menu();
     return 0;
}
