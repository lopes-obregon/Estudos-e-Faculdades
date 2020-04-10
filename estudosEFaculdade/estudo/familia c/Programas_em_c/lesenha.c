#include <stdio.h>
#include <stdlib.h>
//prototipos da função
void verificac(char *senha,char *senhad,char aux);
void verificanum(char *senha,char *senhad,char aux,int i);
//função principal
int main(int argc, char const *argv[])
{
	FILE *arq;
	if ((arq=fopen("senha.dat","rb"))==NULL)
	{
		printf("problema na leitura do arquivo\n");
		exit(1);
	}
	char senha[8];
	fseek(arq,0,SEEK_SET);
	fread(senha,sizeof(char),8,arq);
	char aux;
	char senhad[8];
	verificac(senha,senhad,aux);
	printf("sua senha é:\n");
	for (int i = 0; i < 8; ++i)
	{
		if (senhad[i]==senha[i])
		{
			printf("%c",senhad[i]);
		}
	}
	printf("\n");
	return 0;
}
//função que verifica os caracteres da senha;
void verificac(char *senha,char *senhad,char aux){
	char c;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 97; j < 122; ++j)
		{
			aux =senha[i];
			c=j;
			if (c==aux){
				senhad[i]=c;
			}
		}
		verificanum(senha,senhad,aux,i);
	}
}
//procedimento que verifica os numeros
void verificanum(char *senha,char *senhad,char aux,int i){
	char c;
	for (int j = 48; j < 57; ++j)
		{
			aux =senha[i];
			c=j;
			if (c==aux)
			{
				senhad[i]=c;
			}
		}
}