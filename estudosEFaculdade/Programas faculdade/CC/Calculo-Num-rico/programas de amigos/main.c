#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TAM 10

void calculoConv(float [TAM][TAM], int, int, float *);
void calculoRes(float [TAM][TAM], float [], float, int, int);
float DistRel(float [], float [], int);

int main(){

    int i, j, lin, col, k = 0;
    float mat[TAM][TAM], vet[TAM - 1], erro, conv = 0;

    printf("informe a dimensao:");
    scanf("%d %d", &lin, &col);

    printf("informe os elementos da matriz:\n");
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("[%d][%d]:", i + 1, j + 1);
            scanf("%f", &mat[i][j]);
        }
    }

    printf("informe o resultado inicial da matriz:\n");
    for(j = 0; j < col - 1; j++) {
        printf("[%d]:", j + 1);
        scanf("%f", &vet[j]);
    }

    printf("calculo da convergencia:\n");
    calculoConv(mat, lin, col, &conv);

    if(conv < 1) {
        printf("informe o erro:");
        scanf("%f", &erro);
        calculoRes(mat, vet, erro, lin, col);

    }
    else
        printf("\ndo jeito que a matriz esta a representado a convergencia nao e garantida!!\n");

    return 0;
}

void calculoConv(float mat[TAM][TAM], int lin, int col, float *conv){

    int i, j;
    float div;

    for(i = 0; i < lin; i++){
        for(j = 0; j < col - 1; j++){
            if(j != i)
                *conv += fabsf(mat[i][j]);
            else
                div = fabsf(mat[i][j]);
        }

        *conv /= div;

        if(*conv >= 1)
            break;
    }
}

void calculoRes(float mat[TAM][TAM], float vet[], float erro, int lin, int col){
    float ResAnt[col - 1], dr, div, soma;
    int i, j, k = 0;

    do{

        for (j = 0; j < col - 1; j++)
            ResAnt[j] = vet[j];

        printf("\nk = %d\n", k);
        for (i = 0; i < lin; i++) {
            soma = mat[i][col - 1];
            for (j = 0; j < col - 1; j++) {
                if (j != i)
                    soma = soma - (mat[i][j] * ResAnt[j]);
                else
                    div = mat[i][j];
            }
            vet[i] = soma / div;
            printf("[%d]: %.2f\n", i+1, vet[i]);
        }

        dr = DistRel(vet, ResAnt, col);
        printf("dr(%d) = %.2f\n", k + 1, dr);
        k++;

    }while(dr >= erro);

}

float DistRel(float vet[], float vetAnt[], int col){

    int i;
    float maiorSub = 0, maiorVetAt = 0, t;

    for(i = 0; i < col - 1; i++){


        if(fabsf(vet[i] - vetAnt[i]) > maiorSub) {
            maiorSub = fabsf(vet[i] - vetAnt[i]);
        }
        if(fabs(vet[i]) > maiorVetAt)
            maiorVetAt = fabsf(vet[i]);
    }

    return maiorSub/maiorVetAt;
}