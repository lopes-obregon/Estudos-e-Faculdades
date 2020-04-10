#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	FILE *arquivo;
	int op,num, elem;
	if ((arquivo=fopen("fseek.dat","a+b"))== NULL)
	{
		printf("Erro na abertura do arquivo.\n");
		exit(1);
	}
	do
	{
		printf("Digite:\n\t 1-Gravar \n\t 2-ler \n\t op: ");
		scanf("%d",&op);
		if (op == 1)
		{
			printf("Digite o número: \n");
			scanf("%d",&num);
			fseek(arquivo, 0, SEEK_END);
			fwrite(&num,sizeof(int), 1, arquivo);
		}else if (op == 2)
		{
			printf("Digite o elemento a ser mostrado: \n");
			scanf("%d", &elem);
			if (fseek(arquivo,(elem-1)*sizeof(int),SEEK_SET)==0 &&(fread(&num,sizeof(int),1, arquivo)>0))// a primeira parte posiciona o cursor para ler dele para frente, depois lé o byte
			{
				printf("Elemento %d é %d.\n",elem,num );

			}else{
				printf("Elemento Inexistente.\n");
			}
		}
	} while ((op == 1|| op == 2));
	fclose(arquivo);
}