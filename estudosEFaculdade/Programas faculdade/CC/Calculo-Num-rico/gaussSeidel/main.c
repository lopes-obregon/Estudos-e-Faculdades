#include <stdio.h>
#include <stdlib.h>
//variavel global
//n representa as linhas e m representa as colunas
int n, m;
//procedimentos
//calcula o error
float calcError(float *vet, float *vet2){
    float maior, maior2, aux;
    maior = maior2 = -99999999;
    for(int i = 0; i < n; i++){
        aux = abs(vet[i] - vet2[i]);
        printf("|x%d - x%d| = %f\n", i+ 1, i + 1, aux);
        if(maior < abs(aux) &&  maior2 < abs(vet[i])){
            maior = abs(aux);
            maior2 = abs(vet[i]);
        }
    }
    printf("dr = %.9f/%.9f", maior/maior2);
    return maior/maior2;
}
//imprime vetor xn
void printVet(float *vet){
    for(int i = 0; i < n; i++){
        printf("|%.9f|\n", vet[i]);
    }

}
//copia o vetor
void copyVet(float *v1, float *v2){
    for(int i = 0; i < n; i++){
        v2[i] = v1[i];
    }
}
//calcula a matriz
void calcMat(float mat[n][m], float erro, float *vetIni){
    float vet[n], aux, div;
    int k = 0;
    printf("%f", mat[0][m -1]);
    do{
            copyVet(vetIni, vet);
            for(int i = 0; i < n; i++){
                aux = mat[i][m -1];
            for(int j = 0;  j < m; j++){
                if(i != j){
                    aux = aux - mat[i][j] * vet[j];
                }else{
                    div = mat[i][j];
                }
            }
            vet[i] = aux/div;
        }
        printf("k = %d\n", k);
        printVet(vet);
        k += 1;
    }while(calcError(vet, vetIni)  > erro);

}
//imprime a matriz
void printMat(float mat[n][m]){
 for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(j+ 1 == m){
            printf("%f",mat[i][j]);
            printf("\n");

        }else{
            printf("%f ", mat[i][j]);
        }
    }
 }

}
//insere dados na matriz
void insere(float mat[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j+1 == m){
                printf("b:");
                scanf("%f", &mat[i][j]);
            }else{
                printf("a%d%d: ", i + 1, j +1);
                scanf("%f", &mat[i][j]);
                printf("\n");
            }
        }
    }

}
//main
int main()
{
    printf("Informe o tamanho da matriz!\n");
    scanf("%d %d", &n, &m);
    m += 1;
    //gera a matriz nova
    float matriz[n][m], x[n], error;
    insere(matriz);
    printMat(matriz);
    //insere o dado do xn
    for(int i = 0; i < n; i++){
        printf("Informe o %dº: ", i +1);
        scanf("%f", &x[i]);
        printf("\n");
    }
    printf("Informe o erro: ");
    scanf("%f", &error);
    calcMat(matriz, error, x);
    return 0;
}
