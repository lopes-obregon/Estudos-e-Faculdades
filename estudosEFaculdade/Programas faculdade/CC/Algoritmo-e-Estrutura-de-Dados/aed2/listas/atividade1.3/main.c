#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    int value;
    struct no *prox;
    struct no *ant;
}No;
void Pa(No **ptInicio){
    No *ptl = *ptInicio;
    int count = 0;
    No *aux = *ptInicio;
    int soma = 0;
    while(ptl != NULL){
        while(aux != NULL){
            if(ptl == *ptInicio  && aux->prox == NULL){
                soma = ptl->value + aux->value;
            }
            if((ptl->value + aux->value) == soma){
                printf("Passou na primeira condição de PA\n");
            }
            if((ptl->value + aux->value)/2 == aux->prox){
                count += 1;
                if(count >= 1){
                    printf("Passou na segunda condição\n");
                }
            }
            if(ptl == *ptInicio  && aux->prox == NULL){
                if(busca((ptl->value +aux->value)/2, &ptInicio) == 0){
                    printf("Passou na terceira condição");
                }
            }
        }
    }

}
//função para busca da lista
int busca(int x, No **ptInicio){
    No *ptl = *ptInicio;
    int valorRetorno = 1;
    while(ptl != NULL){
        if(ptl->value == x){
            valorRetorno = 0;
        }else{
            ptl = ptl->prox;
        }
    }
    return valorRetorno;
}
//função para inserer valores
void insertDup(No **ptInicio, int x){
    No *neww = malloc(sizeof(No));
    neww->value = x;
    No *aux = *ptInicio;
    neww->prox = NULL;
    neww->ant = NULL;
    if(*ptInicio == NULL){
        //aponta para o inicio da lista
        *ptInicio = neww;
    }else{
        while(aux != NULL){
            if(aux->prox == NULL){
                aux->prox = neww;
                neww->ant = aux;
            }
        }

    }

}
//imprime a lista
void printDup(No **ptInicio){
    No *ptl = *ptInicio;
    while(ptl != NULL){
        printf("[%d]->", ptl->value);
        ptl = ptl->prox;
    }
    printf("\n\n");
}
int main()
{
    No *ptInicio = NULL;
    insertDup(&ptInicio, 4);
    printDup(&ptInicio);
    Pa(&ptInicio);
    return 0;
}
