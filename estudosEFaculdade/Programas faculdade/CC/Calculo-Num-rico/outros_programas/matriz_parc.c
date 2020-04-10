#include <stdio.h>
#include <stdlib.h>
//variavel global
int linha, coluna; // variavel para dar o tamanho da matriz;
//protótipos da função
float entradaElementos();
float perMat(float mat[linha][coluna]);
void imprimeMat(float mat[linha][coluna]);
float perMat(float mat[linha][coluna]);
void copy(float mat[linha][coluna], float matB [linha][coluna]);	
void trocaMat(float mat[linha][coluna], float matB[linha][coluna], int lt1, int lt2);
void calMat(float mat[linha][coluna], float pivo, int inter, float elemento);

//função principal
int main (){
	int valor;
	printf("informe o tamanho da matriz\n");
	scanf("%d %d",&linha, &coluna);
	float matriz[linha][coluna];
	printf("Informe os elementos da matriz\n");
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			matriz[i][j] = entradaElementos();
		}
	}
	printf("\n");
	imprimeMat(matriz);
	printf("\n");
	perMat(matriz);
	printf("\n");
	imprimeMat(matriz);
	return 0;
}
//função que entra os dados na matriz;
float entradaElementos(){
	float valor;
	scanf("%f", &valor);
	return valor;
}
//função que imprime os elementos da matriz
void imprimeMat(float mat[linha][coluna]){
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			printf("%0.f ",mat[i][j] );
		}
		printf("\n");
	}
}
//função que percorre a matriz
float perMat(float mat[linha][coluna]){
	float elemento;
	float matModulo[linha][coluna];
	int valorLinhaDeTroca;//variavel para fazer a troca de linha da matriz
	float maiorElemento = 0; 
	float menorElemento = 99999;
	int valorLinhaDeTroca2;
	float pivo;
	int inter = 0;//variavel para calcular a interação; 
	for (int i = 0; i < linha; ++i){
		for (int j = 0; j < coluna; ++j)
		 {
		 	if((elemento = mat[i][inter]) != 0){
				if (abs(elemento) > maiorElemento ){
					maiorElemento = elemento;
					 valorLinhaDeTroca = i;
				}
				if (abs(elemento) < menorElemento)
				{
					menorElemento = elemento;
					valorLinhaDeTroca2 = i;
				}
			} 
		 } 
	}
	pivo = maiorElemento;
	float matB[linha][coluna];
	copy(mat,matB);
	trocaMat(mat,matB,valorLinhaDeTroca,valorLinhaDeTroca2);
	calMat(mat,pivo,inter,elemento);
	inter +=1;
}
//funcção que copia a matriz;
void copy(float mat[linha][coluna], float matB [linha][coluna]){
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			matB[i][j] = mat[i][j];
		}
	}
}
//função que troca o valor da matriz.
void trocaMat(float mat[linha][coluna], float matB[linha][coluna], int lt1, int lt2){
	int menorvalor;
	for (int i = 0; i < linha; ++i)
	{
		for (int j = 0; j < coluna; ++j)
		{
			mat[lt2][j] = matB[lt1][j];
			mat[lt1][j] = matB[lt2][j];
		}
	}
}
//zera os elementos da matriz
void calMat(float mat[linha][coluna], float pivo, int inter, float elemento){
	int A;
	int elementoMult;
		for (int i = 0; i < linha; ++i)
		{
			for (int j = 0; j < coluna; ++j)
			{
				if((elemento = mat[i][inter]) != 0){
					if (abs(elemento) != pivo ){
					
						A = (mat[i][inter]/pivo);
						elementoMult = mat[i][j];
						
					}
				}
			}
	}
}
