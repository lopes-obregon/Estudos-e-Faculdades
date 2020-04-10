#include <stdio.h>
#include<stdlib.h>
//variaveis globais
int linha,coluna;
//protótipos das funções
float entra_dados(int col);
float entrada_dados_independente(float mat[linha][coluna],int i);
void print_mat(float mat[linha][coluna]);
void calc_mat(float mat[linha][coluna]);
float func_abs(float mat[linha][coluna], int i, int passocoluna);
void troca_linha(float mat[linha][coluna]);
void func_copy_mat(float mat[linha][coluna], float auxmat[linha][coluna]);
void cal_mat(float mat[linha][coluna]);
//função principal
int main(int argc, char const *argv[]){
    printf("Informe o tamanho da matriz(linha e coluna): ");
    scanf("%d %d",&linha, &coluna);
    coluna +=1;
    float matriz[linha][coluna];
    for(int i = 0; i < linha; i++){
        printf("Informe os valores  da %dº linha \n",i+1);
        for(int j = 0; j < coluna-1; j++){
            matriz[i][j] = entra_dados(j);
        }
         entrada_dados_independente(matriz,i);
    }
    printf("sua matriz é: \n");
    print_mat(matriz);
    cal_mat(matriz);
    printf("\n");
    print_mat(matriz);
    return 0;
}
//função que entra os dados
float entra_dados(int col){
    float valor;
    printf("informe o valor da %dº coluna \n",col+1);
    scanf("%f",&valor);
    return valor ;
}
//entrada dos valores dos termos independentes
//linha vai ser andada as colunas vão ser pré definida ou seja as ultimas para ser uma matriz aumentada
float entrada_dados_independente(float mat[linha][coluna], int i){
    float valor;
    printf("informe o %dº termo independente: \n",i+1);
    scanf("%f", &valor);
    mat[i][coluna-1] = valor;

}
//função que imprime a matriz
void print_mat(float mat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++)
        {
            printf("%.2f ",mat[i][j]);
        }
        printf("\n");
        
    }
    
}
//função que verifica qual é maior em modulo da linha correspondente
void cal_mat(float mat[linha][coluna]){
    
    troca_linha(mat);
}
//função que calcula o valor em modulo;
float func_abs(float mat[linha][coluna], int i, int passocoluna){
    float valor;
    valor = mat[i][passocoluna];
    if (valor < 0) {
        valor = valor * -1;
    }
    return valor;
}
//função que troca a linha
void troca_linha(float mat[linha][coluna]){
    float menor = 99999;
    int linhaAserTrocada;
    int lintroca;
    int passcol = 0;
    float aux, maior = 0;
    float matb[linha][coluna];
    
    //verificar a colina
    //primeiro percorrer a matriz
    for(int i = 0; i < linha; i++){
        //trava a coluna
        if (func_abs(mat,i,passcol) > maior) {
            maior = mat[i][passcol];
            lintroca = i;
        }
        
    }
    //realizar a troca da linha
    
    //achar o menor 
    //temos que percorrer para achar o menor valor para trocar a linha
    for(int i = 0; i < linha; i++)
    {
        if (func_abs(mat,i,passcol) < menor) {
            linhaAserTrocada = i;
        }
        
    }
    //copia os valores para a matriz b para que possa realizar os calculos da troca de linhas
    func_copy_mat(mat,matb);
    for(int i = 0; i < coluna; i++){
        mat[linhaAserTrocada][i] = matb[lintroca][i];
        mat[lintroca][i] = matb[linhaAserTrocada][i];
    }
    
}
//função que copia
void func_copy_mat(float mat[linha][coluna], float auxmat[linha][coluna]){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++)
        {
            auxmat[i][j] = mat[i][j];
        }
        
    }
    
}