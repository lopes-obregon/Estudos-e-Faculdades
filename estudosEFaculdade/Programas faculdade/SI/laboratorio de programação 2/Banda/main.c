#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct
typedef struct{
    char nome_da_banda[25];
    char genero[25];
    unsigned short int numero_de_integrantes;
    unsigned int posicao_rank;
}banda_t;
//protótipos
void getinfoBand(banda_t b[]);
void getInfoBandStyle(banda_t banda[]);
void printBanda(banda_t banda[]);
void favorita(banda_t banda[]);
//main
int main(int argc, char const *argv[])
{
    banda_t banda[5];
    int i;
    unsigned short int op = -1; // variavel de opção
    for(i = 0; i < 5; i++){
        printf("Nome da banda:");
        scanf("%s%*c", banda[i].nome_da_banda);
        printf("Genereno da banda:");
        scanf("%s%*c", banda[i].genero);
        printf("posicao rank:");
        scanf("%d%*c", &banda[i].posicao_rank);
        banda[i].numero_de_integrantes = 5;
    }
    while(op !=0){
        printf("\n0-sair  1-imprimir banda  2-encontrar banda no rank favorito 3-imprimir a banda corespondente ao estilo 4-encontrar a banda pelo nome\nopcao:");
        scanf("%d", &op);
        if(op == 0){
            break;
        }else if (op == 1){
            printBanda(banda);

        }else if(op == 2){
            getinfoBand(banda);

        }else if(op == 3){
            getInfoBandStyle(banda);

        }else if(op == 4){
            favorita(banda);

        }
    }
    return 0;
}

void printBanda(banda_t banda[]){
     //imprime na tela
     int i;
    for(i = 0; i < 5; i++){
        printf("Nome da banda %s, genero %s, numero de integrantes %d\n", banda[i].nome_da_banda, banda[i].genero, banda[i].numero_de_integrantes);
    }
}
//obtem pela posição do rank
void getinfoBand(banda_t b[]){
    unsigned short int aux;
    int i =0;
    printf("digite um numero de 1 ate 5:");
    scanf("%d%*c",&aux);
    for(i = 0; i < 5; i++){
        if(aux == b[i].posicao_rank){
            printf("\nNome da banda %s, genero %s, numero de integrantes %d\n", b[i].nome_da_banda, b[i].genero, b[i].numero_de_integrantes);
        }
    }
}
//obtem informação pelo estilo
void getInfoBandStyle(banda_t banda[]){
    char aux[25];
    int i;
    printf("Informe o estilo da banda:");
    scanf("%s%*c", aux);
    for ( i = 0; i < 5; i++)
    {
        if(strcmp(aux, banda[i].genero) == 0){
            printf("\nNome da banda %s, genero %s, numero de integrantes %d\n", banda[i].nome_da_banda, banda[i].genero, banda[i].numero_de_integrantes);
        }
    }
    
}
//mostra se a banda esta entre as cinco favoritas
void favorita(banda_t banda[]){
    char nome_da_banda[25];
    int i;
    printf("Entre com o nome da banda:");
    scanf("%s%*c", nome_da_banda);
    for ( i = 0; i < 5; i++)
    {
        //acha a banda
        if(strcmp(banda[i].nome_da_banda, nome_da_banda) == 0){
            //se a posição não for as da cinco primeiras 
            if(banda[i].posicao_rank <=5){
                printf("\n a banda %s esta entre as cinco favoritas\n", banda[i].nome_da_banda);
            }else{
                printf("\nA banda %s nao esta entre as favoritas\n", nome_da_banda);
            }
        }
    }
    
    
}
