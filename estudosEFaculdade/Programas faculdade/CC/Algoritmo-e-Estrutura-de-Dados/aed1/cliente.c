#include <stdio.h>
#include <stdlib.h>
//tipos de dados
typedef struct cliente
{
	int cod_cliente;//variavel que armazena o codigo do cliente;
	char nome_cliente[50];
	int idade;
}Tipocliente;
//prototipo das funções
void leia(FILE *arq,Tipocliente cl);
void busca(FILE *arq,Tipocliente cl);
void ve_dados(FILE *arq,Tipocliente cl);
void limpa(Tipocliente cl);
//função principal
int main(int argc, char const *argv[])
{
	FILE *arq;
	Tipocliente cl;
	int op;
	if ((arq= fopen("cliente.dat","wb"))== NULL)
	{
		printf("arquivo não existe\n");
		exit(1);
	}
	do
	{
		printf("Digite:\n\t 1-gravar\n \t 2-busca\n \t 3-altera\n \t 0-sair\n  \t 4-ver_dados\n");
		scanf("%d",&op);
		limpa(cl);
		if (op == 1)
		{
			leia(arq,cl);		
		}else{
			if (op == 2)
			{
				busca(arq,cl);
			}else{
				if (op == 4)
				{
					ve_dados(arq,cl);
				}
			}	
		}
	} while (op == 0);

	return 0;
}
//função que faz a entrada de dados;
void leia(FILE *arq,Tipocliente cl){
	int nome;
	printf("Digite o código do cliente:\n");
	scanf("%d",&cl.cod_cliente);//parte que digita o nome do usuario;
	//fwrite(&cl.cod_cliente,sizeof(cl.cod_cliente),1,arq);//escreve no arquivo binario;
		
	printf("Digite o nome do cliente:\n");
	scanf("%s",cl.nome_cliente);
	//fwrite(cl.nome,sizeof(cl.nome_cliente),50,arq);
	printf("Digite a idade do cliente:\n");
	scanf("%d",&cl.idade);
	//fwrite(&cl.idade,sizeof(cl.idade),1,arq);
	printf("%s\n",cl.nome_cliente );
	printf("cod:%d\n",cl.cod_cliente );
	printf("idade: %d\n",cl.idade );
	fwrite(&cl,sizeof(Tipocliente),1,arq);
}
//função que busca os registros;
void busca(FILE *arq,Tipocliente cl){
	int elem;
	printf("DIgite o código  do cliente: \n");
	scanf("%d", &elem);
	if ((fseek(arq,(elem-1)*sizeof(int),SEEK_SET)== 0)&&(fread(&cl.cod_cliente,sizeof(int),1,arq)>0))
	{
		printf("cliente encontrado\n");
	}else{
		printf("cliente nao encontrado ou nao existe\n");
	}
}
//procedimento que ve os dados
void ve_dados(FILE *arq,Tipocliente cl){ 
	if((arq= fopen("cliente.dat","rb")) ==NULL){
		
		printf("problema na leitura\n");
	}
	fread(&cl,sizeof(Tipocliente),1,arq);
	printf("codigo do cliente: %d\n nome do cliente: %s\nidade do cliente: %d\n",cl.cod_cliente,cl.nome_cliente,cl.idade );
	printf("\n\n");
	fclose(arq);
}
//procedimento que limpa a variavel;
void limpa(Tipocliente cl){
		cl.cod_cliente = 0;
		cl.idade = 0;
	
}