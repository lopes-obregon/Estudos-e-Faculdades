#include <stdio.h>
#include <stdlib.h>
//programa que soma elementos da matriz
int main(){
    float **mat;
    int linha, coluna;
    float aux;
    printf("informe a quantidade de linha: ");
    scanf("%d", &linha);
    printf("Informe a quantidade de coluna: ");
    scanf("%d", &coluna);
    mat = calloc(linha, linha * sizeof(float));
    if(mat == NULL){
        return -1;
    }
    //aloca as colunas
    for(int i = 0; i < linha; i ++){
        mat[i] = calloc(coluna, coluna * sizeof(float));
        if(mat[i] == NULL){
            return -1;
        }
    }

    //insere elmentos
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
           printf("Informe o elemento %d %d: ", i+1, j+1);
           scanf("%f",&aux);
           mat[i][j] = aux;
           aux = 0;

        }
        printf("\n");
    }
    //imprime os elementos da matriz
    printf("Os elementos da sua matriz eh!\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("%.1f ", mat[i][j]);
        }
        printf("\n");
    }
    //soma todo os elmentos
    aux = 0;
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            aux += mat[i][j];
        }
    }
    printf("Soma de todos os elementos eh: %.1f\n", aux);
    //libera
    for(int i = 0; i < linha; i++){
        free(mat[i]);
    }
    free(mat);
    sleep(100);
    return 0;

}
