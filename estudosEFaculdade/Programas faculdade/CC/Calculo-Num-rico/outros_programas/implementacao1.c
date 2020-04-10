#include <stdio.h>
#include <math.h>
#include <math.h>
#define PI 3.14
//prototipos das funções
float calsen (double x, int j);
double potencia(double x, int i);
double fat(int i);
//função princinpal
int main(int argc, char const *argv[])
{
	double x;
	float senx;
	int j; //que controla o expoente e o fatorial;
	/*fazer um programa que:
		calcule o sen(x) = x^³/3! + x^5/5 - x^7/7 + x^9/9*/
	//entra com o valor 
	printf("informe o valor do seno: \n");
	scanf("%lf",&x);
	x = (x*PI)/180;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 0)
		{
			senx = x;
		}else{
			if (i %2 == 0)
			{
				senx = senx + calsen(x,j);
			}else{
				senx = senx - calsen(x,j);
			}
		}
	}
	printf("sen(x): %f \n",senx);
	return 0;
}
//funções
//função que calcula o seno	
float calsen(double x , int j){
	float result;
	double pote;
	double fato;
	pote = potencia(x, j);
	fato = fat(j);
	result = pote/fato;
	return result;
}
//função que calcula o expoente
double potencia(double x, int i){
	double potenciaa;
	potenciaa = pow(x, i);
	return potenciaa;
}
//função que calcula o fatorial do numero
double fat(int i){
	double valorFat= 1;
	//parte do fatorial
	for (int j = 1; i > 1; i=i-1){
		if (j > 1){
			valorFat = valorFat*j;
		}
	}
	return valorFat;
	
}