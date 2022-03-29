//programa que imprime a quantidade de linhas e colunas completamente nulas
#include <stdio.h>
#define LINHA 10
#define COLUNA 10
int main(){
    int matriz[LINHA][COLUNA], contador_linha, contador_coluna, linha, coluna, i, j, linha_nulas, coluna_nulas;
    printf("Informe a dimensão da sua matriz formato(nxm): ");
    scanf("%d%*c%d", &linha, &coluna);
    //leitura matriz
    for( i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("Informe o valor %dx%d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
    //imprime matriz
     for( i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("%d ", matriz[i][j]);
            
        }
        printf("\n");
    }
    contador_linha = 0;
    contador_coluna = 0;
    linha_nulas = 0;
    coluna_nulas = 0;
    //operação da conta das linhas
    for( i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
           if(matriz[i][j] == 0){
               contador_linha++;

           }
        }
        if(contador_linha  == coluna ){
            linha_nulas++;
            contador_linha = 0;
        }else{
            contador_linha = 0;
        }
    }

    //operação da contagem de coluna
    for( i = 0; i < coluna; i++){
        for(j = 0; j < linha; j++){
           if(matriz[j][i] == 0){
               contador_coluna++;

           }
        }
        if(contador_coluna  == linha ){
            coluna_nulas++;
            contador_coluna = 0;
        }else{
            contador_coluna = 0;
        }
    }

    printf("Matriz tem %d linhas lunas e %d colunas nulas\n", linha_nulas, coluna_nulas);
    return 0;
}