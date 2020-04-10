#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//função principal
int main(int argc, char const *argv[])
{
	FILE *arq;
	int vet[50];
	if (arq==NULL)
	{
		printf("O arquivo nao existe, ele será criado...\n");
		arq = fopen("numeros.txt","w");
		//gera(arq,vet);
		int min=10,max=1000;
		srand(time(NULL));
		int variavel;
		int count = (1+(rand()%(50-1+1)));
		for (int i = 0; i < count; ++i)
		{
			variavel= (min+(rand()%(max-min+1)));
			fprintf(arq, "%d\n",variavel);
		}
		return 0;
	}
	if (arq != NULL){
		printf("arquivo existente abrindo para leitura\n");
		arq =fopen("numreos.txt","r");
		//leitura(arq);
		int vet[50];
		while(!feof(arq)){
			fscanf(arq,"%d",vet);
		}
		for (int i = 0; i < 35; ++i)
		{
			printf("%d\n",vet[i] );
		}
	}
	fclose(arq);
	return 0;
}
