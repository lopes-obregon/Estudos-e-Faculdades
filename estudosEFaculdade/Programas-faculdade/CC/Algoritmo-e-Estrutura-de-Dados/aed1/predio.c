#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANDAR 5
#define MAX_APS 2

//Definição dos Tipos de Dados
typedef struct AP{
	int   alugado;     //0-vago, 1-alugado
	char  nome[100];
	int   numero;
	char  cpf[15];
	int   adultos;
	int   criancas;
	float renda;
	int   veiculos;
}TipoAP;

// Protótipos de Funções
void numeracao_ap(TipoAP predio[MAX_ANDAR][MAX_APS]);
void mostra_ap(TipoAP apto);
void limpa_ap(TipoAP *apto);
void ocupa_ap(TipoAP predio[MAX_ANDAR][MAX_APS],int proc);
void mostra_predio(TipoAP predio[MAX_ANDAR][MAX_APS]);

//Função Principal
int main(int argc, char *argv[]){
	char op
	int num;	
	TipoAP predio[MAX_ANDAR][MAX_APS];
	

	numeracao_ap(predio);
	do{
		printf("Deseja ocupar um apartamento (S=1/N=0)?");
		scanf(" %c",&op);
		if(op== 1){		
			printf("Qual apartamento deseja ocupa: ");
			scanf(" %d",&num);
		}
	}while(op !=0)
	ocupa_ap(predio,301);
	mostra_predio(predio);

	return(0);
}

// Função que faz a entrada dos dados dos apartamentos e retorna a quantidade de apartamentos ocupados
void numeracao_ap(TipoAP predio[MAX_ANDAR][MAX_APS]){
	int i,j;
	for (i = 0; i < MAX_ANDAR; ++i){
		for (j = 0; j < MAX_APS; ++j){
		predio[i][j].numero = (MAX_ANDAR-i-1)*100+(j+1);
		limpa_ap(&predio[i][j]);
		}
	}
}

//Função que mostra os dados de um único apartamento
void mostra_ap(TipoAP apto){
	printf("\n");
	printf("Apartamento: %d",apto.numero);
	if (apto.alugado == 0){
		printf("(Livre)\n");
	}else{
		printf("(Ocupado)\n");
	}
	printf("Proprietário: %s(%s)\n",apto.nome,apto.cpf);
	printf("Adultos (%d). Crianças (%d)\n",apto.adultos,apto.criancas);
	printf("Renda familiar: %.2f\n",apto.renda);
	printf("Veículos: %d\n",apto.veiculos);
}

//Função que limpa o apartamento
void limpa_ap(TipoAP *apto){
	strcpy(apto->nome,"");
	strcpy(apto->cpf,"");
	apto->renda = 0;
	apto->adultos = 0;
	apto->criancas = 0;
	apto->veiculos = 0;
	apto->alugado = 0;
}

//Função que busca um apartamento e insere os dados nele, caso esteja desocupado.
void ocupa_ap(TipoAP predio[MAX_ANDAR][MAX_APS],int proc){
	int i,j;
	for (i = 0; i < MAX_ANDAR; ++i){
		for (j = 0; j < MAX_APS; ++j){
			if (proc == predio[i][j].numero){
				printf("Apartamento %d Encontrado!\n",proc);
				if (predio[i][j].alugado == 0){
					printf("Apartamento %d pode ser ocupado!\n",proc);
					printf("Digite o nome do proprietario: ");
					scanf("%s",predio[i][j].nome);
					printf("Digite o CPF do proprietario: ");
					scanf("%s",predio[i][j].cpf);
					printf("Digite a quantidade de adultos: ");
					scanf("%d",&predio[i][j].adultos);
					printf("Digite a quantidade de crianças: ");
					scanf("%d",&predio[i][j].criancas);
					printf("Digite a renda familiar: ");
					scanf("%f",&predio[i][j].renda);
					printf("Digite a quantidade de carros: ");
					scanf("%d",&predio[i][j].veiculos);
				}else{
					printf("Apartamento %d não pode ser ocupado!\n",proc);
				}				
			}
		}
	}
}

//Função que mostra todos os APs do prédio
void mostra_predio(TipoAP predio[MAX_ANDAR][MAX_APS]){
	int i,j;
	for (i = 0; i < MAX_ANDAR; ++i){
		for (j = 0; j < MAX_APS; ++j){
			mostra_ap(predio[i][j]);
		}
	}
}
