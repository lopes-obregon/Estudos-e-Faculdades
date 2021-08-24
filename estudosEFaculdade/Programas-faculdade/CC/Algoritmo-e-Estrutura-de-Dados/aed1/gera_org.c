#include <stdio.h>
#include <stdlib.h>
//estrutra de dados
//prototipos da função
void leitura(FILE *arq,int *v,int count);
void par(FILE *arq,int *v, int count);
void imp(FILE *arq,int *v,int count);
void limpa(int *v,int count);
//função principal
int main(int argc, char const *argv[])
{
	FILE *arq;//declaremento do arquivo file;
	int count=10000;//variavel contadora;
	int v[count];//vetor para armazenar e facilitar na hora de gerar e gravar no arquivo file;
	if ((arq = fopen("numeros.dat","rb"))==NULL)//verificação do arquivo;
	{
		//parte da verificão da existencia do arquivo
		printf("Arquivo não encontrado\n");
		exit(1);
	}
	//limpa(v,count);
	leitura(arq,v,count);//chamada do procedimentode leitura;
	par(arq,v,count);//chamada do procedimento que calcula os numeros pares e guarda no arquivo;
	imp(arq,v,count);//chamada do procedimento que calcula os numeros impares e guarda no arquivo
	return 0;
}
//processamenbto que faz a leitura dos dados do arquivo .dat
void leitura(FILE *arq,int *v,int count){
	fseek(arq,0,SEEK_SET);//seta para o inicio do arquivo
	if((fread(v,sizeof(int),count,arq))>0) {//condição que nao precisava mas vou deixar só para garantir;se a leitura tiver ok arquivo lido com sucesso;
		printf("leitura ok\n");
	}
}
//procedimento que encontra os numeros pares e armazena em um arquivo par
void par(FILE *arq,int *v, int count){
	arq=fopen("pares.txt","w");//ativa o arquivo para o modo de escrita;
	int aux;//variavel para auxiliar no armazenamento dos dados do vetor;
	for (int i = 0; i < count; ++i)
	{
		if (v[i]%2==0)//verifica no vetor o valor se for igual a zero ele é par;
		{
			aux = v[i];// o auxiliar recebe o valor verificado no vetor e depous salva no arquivo;
			fprintf(arq, "%d\n",aux);//salva no arquivo .txt
		}
	}
}
//função que gera os arquivos impares e salva no arquivo com nomde de (impar.txt);
void imp(FILE *arq,int *v,int count){
	arq=fopen("impares.txt","w");//ativa o arquivo para o modo de escrita;
	int aux;//variavel para auxiliar no armazenamento dos dados do vetor;

	for (int i = 0; i < count; ++i)
	{
		if (v[i]%2!=0)//verifica no vetor o valor se for diferente de zero ele é impar;
		{
			aux =v[i];// o auxiliar recebe o valor verificado no vetor e depous salva no arquivo;
			fprintf(arq, "%d\n",aux);//salva no arquivo .txt
		}
	}
}
//função que limpa o vetor
void limpa(int *v,int count){
	for (int i = 0; i < count; ++i)
	{
		v[i]=0;
	}
}