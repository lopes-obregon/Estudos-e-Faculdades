#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//estrutura de dados
void gera(FILE *arq);
int verifica(int *valores,int count,int valor);
//prototipos da função
//função principal
int main(int argc, char const *argv[])
{
	FILE *arq;
	if ((arq=fopen("numeros.dat","wb"))==NULL){//verifica a existencia do arquivo
		printf("arquivo nao existe erro\n");
		exit(1);
	}
	gera(arq);//chamada da função que gera os valores;
	return 0;
}
//função que gera e guarda no arquivo;
void gera(FILE *arq){
	srand(time(NULL));
	int count=10000;//função contadora;
	int v[count];//vetor para armazenar os valores gerados;10000
	int g;//variavel para auxiliar no geramento dos numeros e do calculo para ser guardada no vetor;
	for (int i = 0; i < count; ++i)
	{
		g = (1+((rand()%(1000000))));//parte que gera os numeros aleatoris
		//chamada da função junto do laço
		while((verifica(v,count,g))==1)//se for verdade entao entra no laço e gera novamente outro numero;
		{
			g = (1+((rand()%(1000000))));//gera valor novamente
		}
		v[i]=g;
	}
	fwrite(v,sizeof(int),count,arq);//salva o vetor dentro do arquivo .dat
}
//função que verifica os numeros;
int verifica(int *valores,int count,int valor){
	//se for falso retona 0 se for verdade retorna 1;
	for (int i = 0; i < count; ++i)//entra no laço do tamanho do vetor referente ao i anterior;
	{
		if (valores[i]== valor)//verifica se o valor for igual ao valor do vetor então 
		{
			return (1);//se for verdade sai do laço 
		}
	}
	return(0);//continua com a geraçao sendo não;
}