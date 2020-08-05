#include <stdio.h>
#include <stdlib.h>
//função global
int linha, coluna;
//procedimentos
//encontra o maior pivo da linha
float returnPivoLinha(float mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){

        }
    }
}
//imprime matriz
void printMat(float mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            if(j + 1 != coluna){
                printf("%.2f ", mat[i][j]);
            }else{
                printf("%.2f\n", mat[i][j]);
            }
        }
    }
}
//insere valores na matriz
void insere(float mat[linha][coluna]){
    printf("Informe o elemento da matriz\n");
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("a%d%d: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
}
//main
int main()
{
    printf("Informe a Dimenção da sua matriz: ");
    scanf("%d %d", &linha, &coluna);
    float matriz[linha][coluna];
    insere(matriz);
    printf("Sua matriz é!\n");
    printMat(matriz);
    return 0;
}
