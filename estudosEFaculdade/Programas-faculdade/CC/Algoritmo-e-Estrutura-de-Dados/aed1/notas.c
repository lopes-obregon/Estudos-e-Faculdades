#include <stdio.h>
#include <stdlib.h>
//estrutura de dados
typedef struct facu
{
	float nota;
	float nota2;
	float nota3;
	float nota4;
	char materia[50];
	float media;
}Tipofacu;
//prototipo da função
void leitura(Tipofacu *notas,FILE *arq,int count);
void limpa(Tipofacu *notas, int count);
//função principal
int main(int argc, char const *argv[])
{
	Tipofacu notas[50];
	FILE *arq;
	if ((arq= fopen("notas.txt","r"))==NULL)
	{
		printf("Arquivo não existe\n");
		exit(1);
	}else
		printf("quantas notas tem:\n");
		int count;
		scanf("%d",&count);
		//while(!feof(arq)){
		leitura(notas,arq,count);	
		//}
		fclose(arq);
	return 0;
}
void leitura(Tipofacu *notas,FILE *arq, int count){
	float soma =0;
	limpa(notas,count);
	for ( int i = 0; i < count; ++i)
	{
		
		
		fscanf(arq,"%f",&notas[i].nota);
		fscanf(arq,"%f",&notas[i].nota2);
		fscanf(arq,"%f",&notas[i].nota3);
		fscanf(arq,"%f",&notas[i].nota4);
		fscanf(arq,"%s",notas[i].materia);
	}
}
void limpa(Tipofacu *notas, int count){
	for (int i = 0; i < count; ++i)
	{
		notas[i].nota=0;
		notas[i].media=0;
	}
}