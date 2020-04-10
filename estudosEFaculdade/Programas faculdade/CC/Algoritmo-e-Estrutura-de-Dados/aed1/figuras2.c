/*
obs:sou um vidraceiro;
(1)int tipo(1-circulo,2-retangolo){float raio float altura float largura int transparente (1-sim 2-fosco  3-espelho};
-fazer a entrada dos dados para um vetor de MAX intens(tamanho)(ok);(2){teste (0%)}
-mostrar o maior vidro em área dentre todos (ok);(3){teste (0%)}
-mostrar os tipos de áreas dos espelhos;(ok);(4){teste (0%)}
-mostrar retangolo fosco e espeelhados(ok);(5){teste (0%)}
-mostrar circulo,transparente e fosco(ok);(6){teste (0%)}*/
#include <stdio.h>
#include <math.h>
//parte das struct  das figuras

typedef struct Figura
{
	int tipo;//para o tipo de figura sendo ela 1- para circolo and 2- for Retangolo;
	float raio ;
	float altura;
	float largura; 
	int transparente;//1- sim 2- fosco 3-espelhos
	
}TipoFigura;
//protótipos da função
int entrada1(int max);
//função principal
int main (){
	int max;
	
	max = entrada1(max);
	printf("%d\n",max );
	return 0;

}
//função para a entrada de max intens
int entrada1(int max){
	
	printf("digite a quantidades de intens a ser inseridos\n");
	scanf("%d",&max);
	return (max);
}