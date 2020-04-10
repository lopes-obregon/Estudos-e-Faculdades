#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *arq;
	if ((arq=fopen("senha.dat","wb"))==NULL)
	{
		printf("erro na abertura do arquivo\n");
		exit(1);
	}
	printf("Digite uma senha de até no maximo 8 caracteres:\n");
	char senha [8];
	scanf("%s",senha);
	fwrite(senha,sizeof(char),8,arq);
	return 0;
}