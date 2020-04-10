#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//prototipos da função
void aleatorio(FILE *arq);
void maior_menor(int *vet, int i, int count);
void soma_par(int *vet,int i,int count);
void soma_imp(int *vet,int i,int count);
//função principal
int main(int argc, char const *argv[])
{
	FILE *arq;
	int vet[50];
	int variavel;
	int i=0;
	int count=0;
	if ((arq = fopen("numeros.txt","r"))== NULL)
	{
		printf("o arquivo não existe, ele será criado...\n");
		arq = fopen("numeros.txt","w");
		aleatorio(arq);
	}else{
		printf("Arquivo existente lendo...\n");
		arq =fopen("numeros.txt","r");
		while(!feof(arq)){
			fscanf(arq,"%d",&vet[i]);
			//printf("%d\n",vet[i] );
			count +=1;
			i +=1;
		}
		printf("valores do vetor:\n");
		for ( i = 0; i < (count-1); ++i)
		{
			printf("%d\n",vet[i] );
		}
		maior_menor(vet,i,count);
		soma_par(vet,i,count);
		soma_imp(vet,i,count);

	}
	fclose(arq);
	return 0;
}
//função que gera os numeros de linhas e os numros aleatorios para o arquivo;
void aleatorio(FILE *arq){
	srand(time(NULL));
	int min=10;
	int max = 1000;
	int variavel;
	int count = (1+(rand()%(50-1+1)));
	for (int i = 0; i < count; ++i)
	{
		variavel=(min+(rand()&(max-min+1)));
		fprintf(arq, "%d\n",variavel );
	}
}
//função que calcula o menor e maior numero do vetor;
void maior_menor(int *vet, int i,int count){
	int min=0;
	int max=0;
	//parte do maior
	for ( i = 0; i < count; ++i)
	{
		min = vet[i];
		if (min > max)
		{
			max =min;
		}
	}
	printf("o valor maior é %d\n",max );
	//parte do menor
	min = vet[0];
	for ( i = 0; i < count; ++i)
	{
		if (vet[i] < min )//min==290
		{
			min = vet[i];
		}
	}
	printf("o menor valor é %d\n",min );

}
//função que faz a soma dos numeros pares
void soma_par(int *vet,int i,int count){
	int par;
	for (i = 0; i < count; ++i)
	{
		if (vet[i]%2 == 0)
		{
			par+=vet[i];
		}
	}
	printf("A soma dos numeros pares são :%d\n",par );
}
//função que mostra a soma dos numeros impares;
void soma_imp(int *vet,int i,int count){
	int imp;
	for ( i = 0; i < count; ++i)
	{
		if (vet[i]%2 != 0)
		{
			imp += vet[i];
		}
	}
	printf("A soma dos numeros impares é : %d\n",imp );
}