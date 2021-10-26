#include <stdio.h>
#define TAMANHO 10
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
void aumentar_prioridade(int *fila, int indicie, int nova_prioridade);
int maximo(int *t, int quantidade_de_elementos);
int extrair_maximo(int *fila, int *n);
//main
int main(int argc, char const *argv[])
{
    
    fila_prioridade_t fila_prioridade;
    int op, novo, maximo_elemento;
    fila_prioridade.n = 0;//inicializa com 0 para indiciar que não tem elementos
    
    printFila(fila_prioridade.t, fila_prioridade.n);
    do{
        printf("\n-------- operações com fila------------\n");
        printf("1-Inserir \t 2-Aumentar prioridade \t 3-Extrair máximo \t 4-Imprimir maior prioridade \t 0-sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o elemento a ser inserido:\n");
                scanf("%d", &novo);
                inserir(fila_prioridade.t,&fila_prioridade.n, TAMANHO, novo);
                break;
            case 2:
                printf("Digite a nova prioridade:\n");
                scanf("%d", &novo);
                aumentar_prioridade(fila_prioridade.t, 0, novo);
                break;
            case 3:
                maximo_elemento = extrair_maximo(fila_prioridade.t, fila_prioridade.n);
                break;
            case 4:
                printf("Prioridade máxima: %d\n", maximo(fila_prioridade.t, fila_prioridade.n));
                break;
            default:
                puts("Opção invalida digite novamente");
                break;

        }
    }while(op != 0);
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
//aumenta a prioriadade
void aumentar_prioridade(int *fila, int indicie, int nova_prioridade){
    //indicie -> do elemento que deseja aumetar a prioridade
    if (nova_prioridade < fila[indicie]){
        printf("Error! nova Chave é menor");
    }else{
        fila[indicie] = nova_prioridade;
        subir(fila, indicie);
    }
}

//extrai o maximo
int extrair_maximo(int *fila, int *n){
    int tmp;
    if(n !=0){
        tmp = fila[0];
        fila[0] = fila[*n-1];
        *n -=1;
        descer(fila, *n, 0);
    }
}