#include <stdio.h>
#define TAMANHO 20
//dados personalizados
typedef struct 
{
    int t[TAMANHO];
    int n;//quantidade de elementos
}fila_prioridade_t;
//prototipos
void subir(int *t, int i);
void descer(int *t, int n, int i);
void inserir(int *t, int *n, int m, int novo);
void swap(int *i, int *j);
int pai(int i);
int filho_esquerdo(int i);
void printFila(int *fila, int quantidade_de_elementos);
void substituiElementoDaFila(int *t, int elemento_atual, int novo_elemento, int quantidade_de_elementos);
int buscaElemento(int elemento_buscado, int *t, int quantidade_de_elementos);
int maximo(int *t, int quantidade_de_elementos);
//main
int main(int argc, char const *argv[])
{
    
    fila_prioridade_t fila_prioridade;
    fila_prioridade.n = 0;//inicializa com 0 para indiciar que não tem elementos
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 100);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 19);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 36);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 3);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 25);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 1);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 2);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 7);
    inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, 111);
    printFila(fila_prioridade.t, fila_prioridade.n);
    printf("Prioridade máxima: %d\n", maximo(fila_prioridade.t, fila_prioridade.n));
    substituiElementoDaFila(fila_prioridade.t, 100, 27, fila_prioridade.n);
    printf("fila atualizada\n");
    printFila(fila_prioridade.t, fila_prioridade.n);
    substituiElementoDaFila(fila_prioridade.t, 25, 85, fila_prioridade.n);
    printf("fila atualizada\n");
    printFila(fila_prioridade.t, fila_prioridade.n);
    return 0;
}
//sobe a prioridade dos  elementos
void subir(int *t, int i){
    //recebe o indicie do pai de i
    int j = pai(i);
    //se i tem pai
    if(i > 0){
        // i prioridade maior que o pai
        if(t[i] > t[j]){
            swap(&t[i], &t[j]);
            subir(t, j);
        }
    }
}
//desce a prioridade dos elementos
void descer(int *t, int n, int i){
    //recebe o indicie do filho esquerdo de i
    int j = filho_esquerdo(i);
    //se i tem filhos
    if(j <= n-1){
        //se tem 2 filhos
        if(j < n-1){
            //defino j como o indicie do maior filho
            if(t[j+1]> t[j]){
                j = j + 1;
            }
        }
        //troca i com o maior dos 2 filhos, se i for menor
        if(t[i] < t[j]){
            swap(&t[i], &t[j]);
            descer(t, n, j);
        }
    }
}

//insere elementos
void inserir(int *t, int *n, int m, int novo){
    // n e a quantidade de elementos em T
// m e a capacidade maxima de T
    if(*n < m){
        t[*n] = novo;
        *n+= 1;
        subir(t, *n-1);
    }else{
        printf("Priority queue overflow");
    }
}

void swap(int *i, int *j){
    int aux = *i;
    *i = *j;
    *j = aux;
}
//retorna o pai
int pai(int i){
    return (i-1)/2;
}
//retorna o indicie do filho esquerdo
int filho_esquerdo(int i ){
    return (2 * i + 1);
}
//imprime os elementos
void printFila(int *fila, int quantidade_de_elementos){
    int i;
    printf("Elementos da fila:\n");
    for(i = 0; i < quantidade_de_elementos; i++){
        printf("%d ", fila[i]);
    }
    printf("\n");
}

//substitui elemento da fila
void substituiElementoDaFila(int *t, int elemento_atual, int novo_elemento, int quantidade_de_elementos){
    int indicie_do_elemento_alterar;
    indicie_do_elemento_alterar = buscaElemento(elemento_atual, t, quantidade_de_elementos);
    //insere o novo elemento no lugar do atual
    t[indicie_do_elemento_alterar] = novo_elemento;
    printf("fila alterada\n");
    printFila(t, quantidade_de_elementos);
    descer(t, quantidade_de_elementos, indicie_do_elemento_alterar);
    subir(t, indicie_do_elemento_alterar);
}

//busca o elemento retornando o indice
int buscaElemento(int elemento_buscado, int *t, int quantidade_de_elementos){
    int i;
    for(i = 0; i < quantidade_de_elementos; i++ ){
        if(t[i] == elemento_buscado){
            return i;
        }
    }
}
//elemento de maior prioridade
int maximo(int *t, int quantidade_de_elementos){
    //lista vazia
    if(quantidade_de_elementos == 0){
        printf("Priority Queue underflow!\n");
    }
    else{
        return t[0];
    }
}
