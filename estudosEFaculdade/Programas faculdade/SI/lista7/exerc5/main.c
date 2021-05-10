//programa que imprime e determina uma matriz transposta
#include <stdio.h>
#define LINHA 10
#define COLUNA 10
int main(){
    int matriz[LINHA][COLUNA], matriz_transposta[LINHA][COLUNA] , linha, coluna, i, j;
    printf("Infome a dimensão da matriz no formato nxm: ");
    scanf("%d%*c%d", &linha, &coluna);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("Informe o elemento %dx%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    //imprime a matriz
    printf("Matriz!\n");
     for(i = 0; i < linha; i ++){
        for(j = 0; j < coluna; j++){
               printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
//transpostya
    for(i = 0; i < LINHA; i++){
        for(j = 0; j < COLUNA; j++){
           matriz_transposta[i][j] = matriz[j][i];
        
           
        
        }
        printf("\n");
    }
    //imprime a matriz
    printf("Matriz trasposta!\n");
    for(i = 0; i < coluna; i ++){
        for(j = 0; j < linha; j++){
               printf("%d ", matriz_transposta[i][j]);
        }
        printf("\n");
    }

    return 0;
}