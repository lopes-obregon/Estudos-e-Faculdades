#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define NUMERO_CILINDRO 5000
#define NUMEROS_MAXIMO 1000
typedef struct {
    int solicitacao[NUMEROS_MAXIMO];
    int final, inicio;
}fila_de_solicitacao_t;
//protótipos
void cilindroInit(int *cilindro);
void solisitacaoInit(fila_de_solicitacao_t *solisitacao);
void insereFila(fila_de_solicitacao_t *fila, int valor);
void initFila(fila_de_solicitacao_t *fila);
int removeDaFila(fila_de_solicitacao_t *fila);
void fcfs(fila_de_solicitacao_t fila, int *cilindro, int inicio_cilindro);
int sstfRecursiva(int *cilindro,int *vetor , int inicio, int requisicao_atual, int indicie);
int recursivaCompara(int *cilindro, int *vetor, int indicie, int i);
void sstf(fila_de_solicitacao_t *fila, int *cilindro, int incio_cilindro);

void printCilindro(int *cilindro);
//main
int main(int argc, char const *argv[])
{
    int posicao_inicial_do_cabecote_cilindro;
    int cilindros[NUMERO_CILINDRO];
    
    fila_de_solicitacao_t fila;
    posicao_inicial_do_cabecote_cilindro = atoi(argv[1]);
    cilindroInit(cilindros);
    initFila(&fila);
    solisitacaoInit(&fila);
    fcfs(fila, cilindros, posicao_inicial_do_cabecote_cilindro);
    solisitacaoInit(&fila);
    sstf(&fila, cilindros, posicao_inicial_do_cabecote_cilindro);
    return 0;
}
//inicia o cilindro
void cilindroInit(int *cilindro){
    int i;
    for(i = 0; i < NUMERO_CILINDRO; i++){
        cilindro[i] = i;
    }
}
// inicia as solicitações
void solisitacaoInit(fila_de_solicitacao_t *solisitacao){
    //solisitacao->solicitacao = (int *) malloc(sizeof(int) * NUMEROS_MAXIMO);
    int i;
    solisitacao->inicio =  solisitacao->final = -1;
    for(i = 0; i < NUMEROS_MAXIMO; i++){
        insereFila(solisitacao, rand() % (NUMERO_CILINDRO - 1));
    }
}
//inicia a fila
void initFila(fila_de_solicitacao_t *fila){
    fila->inicio = -1;
    fila->final = 0;
}
//insere na fila
void insereFila(fila_de_solicitacao_t *fila, int valor){
   //verifica se está cheia
   if(fila->final >= NUMEROS_MAXIMO){
       printf("Overflow!\n");
   }else{
    fila->solicitacao[fila->final] = valor;
    //verifica se é o primeiro
    if(fila->inicio == -1){
        fila->inicio = 0;
    }
    fila->final++;

   }
}

//remove o elemento da fila
int removeDaFila(fila_de_solicitacao_t *fila){
    int aux;
    aux = fila->solicitacao[fila->inicio];
    fila->inicio += 1;
    return aux;
}
//algoritmo fcfs
void fcfs(fila_de_solicitacao_t fila, int *cilindro, int inicio_cilindro){
    int aux;
    int i;
    printf("%d->", cilindro[inicio_cilindro]);
    do{
        aux = removeDaFila(&fila);
        for( i = 0; i < NUMERO_CILINDRO; i++){
            if(aux == cilindro[i])
                printf("%d->", cilindro[i]);        
        }

    }while(fila.inicio != fila.final);
    printf("\n");
}
//algoritmo de sstf
void sstf(fila_de_solicitacao_t *fila, int *cilindro, int incio_cilindro){
    int vetor_auxiliar[NUMEROS_MAXIMO];
    int i;
    puts("veotor auxiliar");
    i = 0;
    while(fila->inicio != fila->final){
        vetor_auxiliar[i] = removeDaFila(fila);
        printf("%d->", vetor_auxiliar[i]);
        i++;
    }
    printf("\n");
  //printf("\nelemento %d da posição %d\n", cilindro[incio_cilindro], incio_cilindro);
   printCilindro(cilindro);
   puts("algoritmo sstf");
   sstfRecursiva(cilindro, vetor_auxiliar, incio_cilindro, 0, incio_cilindro);
    

    

}

int sstfRecursiva(int *cilindro,int *vetor , int inicio, int requisicao_atual, int indicie){
    if(indicie >= NUMERO_CILINDRO){
        return inicio - 1;
    }else if(indicie < 0){
        return -1;
    }else if(indicie >= inicio){
        printf("%d->", recursivaCompara(cilindro, vetor, indicie, 0));
        sstfRecursiva(cilindro, vetor, inicio, requisicao_atual, indicie + 1);
    }else if(indicie < inicio){
        printf("%d->", recursivaCompara(cilindro, vetor, indicie, 0));
        sstfRecursiva(cilindro, vetor, inicio, requisicao_atual, indicie - 1);
    }
}
int recursivaCompara(int *cilindro, int *vetor, int indicie, int i){
    if(cilindro[indicie] == vetor[i]){
        return cilindro[indicie];
    }else{
        recursivaCompara(cilindro, vetor, indicie, i + 1);
    }
}
void printCilindro(int *cilindro){
    int i;
    puts("--------------");
    puts("cilindro");
    for(i = 0; i < NUMERO_CILINDRO; i++){
        printf("%d->", cilindro[i]);
    }
    puts("--------------");
    printf("\n");
}