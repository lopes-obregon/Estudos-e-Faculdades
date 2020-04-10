#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *arq;
	int numeros[10];
	int num,i=0;
	if ((arq=fopen("grava_bin.dat","rb"))==NULL)
	{
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	while(!feof(arq)){
		fread(&num,sizeof(int),1,arq);
		if (!feof(arq))
		{
			numeros[i]= num;
			i++;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",numeros[i] );
	}
	fclose(arq);
}