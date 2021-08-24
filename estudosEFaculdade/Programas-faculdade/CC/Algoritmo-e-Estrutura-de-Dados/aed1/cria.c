#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *arq;
	int vet[10]={0,1,2,3,4,5,6,7,8,9};
	if ((arq=fopen("grava_bin.dat","wb"))==NULL)
	{
		printf("erro na abertura do arquivo\n");
		exit(1);
	}
	fwrite(vet,sizeof(int),10,arq);
	fclose(arq);
	return 0;
}