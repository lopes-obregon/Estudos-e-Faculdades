#include <stdio.h>
#include <stdlib.h>
//Prog_hotel v:1.0;by:Renan_Lopes_Obregon;
//tipos de dados
typedef struct Predio
{
	int numero_ap;//numero do apartamento;
	char propriatario [50];//nome do propriatario;
	int andar_ap;//andar do apartamento;
	int quant_pe;// quantidade de pessoas morando no apartamento;
	float alug;//aluguel do apartamento;
}TipoPredio;
//prototipos da função
void leitura(FILE *arq, TipoPredio *apto, int i,int count);
void limpa(TipoPredio *apto,int count,int i);
void maior_aluguel(TipoPredio *apto,int count, int i);
void dados(TipoPredio *apto,int count, int i);
void alug_pag(TipoPredio *apto,int count,int i);
void cal_mora(TipoPredio *apto, int count, int i,int *vet_soma,int *vet_and);
void maior_pes_and(int *vet_soma,int *vet_and,int count,int i,TipoPredio *apto);
void menor_ap_mos(int *v,int *v_and,int count,int i, TipoPredio *apto);
void menu(TipoPredio *apto,int count,int i);
void limpa_vet(int *v_and,int *v,int count,int i);
void alug_pag_m(int *vet_soma,int *vet_and,int count,int i,TipoPredio *apto);
void alug_pag_mo(int *vet_soma, int *vet_and, int count,int i,TipoPredio *apto);
//função principal
int main(int argc, char const *argv[]){
	TipoPredio apto[40];
	int i=0;//contador para ajudar no vetor;
	FILE *arq;
	int count=0;//quantidade de predios
	if ((arq= fopen("predio.txt","r"))==NULL)
	{
		printf("arquivo nao existe para realizar a leitura\n");
		exit(1);
	}else{
		while(!feof(arq)){
			printf("Seja Bem vindo\n Aguarde estamos lendo os dados....\n");
			leitura(arq,apto,i,count);//nesta parte chama o procedimento que realiza a leitura do arquivo;
			
		}
	}
	fclose(arq);//fecha o arquivo;
	return 0;
}
//função que faz a leitura dos dados contido no arquivo de texto (predio.txt);
void leitura(FILE *arq, TipoPredio *apto, int i,int count){
	fscanf(arq,"%d",&count);//realizamos a primeira leitura, guardamos na variavel contadora, onde será armazenado o numeros de apartamentos;
	limpa(apto,count,i);//chama a função que limpa todo o registro para que nao de bug na hora de realizar os calculos para que não fique com lixo;
	for (i = 0; i < count; ++i)
	{
		fscanf(arq,"%d",&apto[i].numero_ap);//faz a leitura e guarda no registro;
		fscanf(arq,"%d",&apto[i].andar_ap);
		fscanf(arq,"%d",&apto[i].quant_pe);
		fscanf(arq,"%f",&apto[i].alug);
		fscanf(arq,"%s",apto[i].propriatario);//parte de leitura da string
	}
	printf("leitura feita com sucesso.\n");
	printf("\n\n\n\n\n");
	menu(apto,count,i);//parte onde se inicia uma especie de gambiarra, onde é chamada o procedimento que apresenta a parte do menu;
}
//função com as opções para parecer menos gambiarra;
void menu(TipoPredio *apto,int count,int i){
	int op;
	int vet_soma[count];
	int vet_and[count];
	
	do{
			printf("Oque deseja fazer\n \n1- ver dados \n2-ver o maior aluguel \n3-ver a soma dos alugies pago de cada andar\n4-ver o andar com maior moradors \n5- o andar com menos apartamentos\n0-sair\n");
			printf("op:");
			scanf("%d",&op);
			if (op==1)
			{
				dados(apto,count,i);//chamada do procedimento que mostra para o usuario os dados que foram lidos e que estavam contido no arquio, e que agora estão dentro do registro;
			}else{
				if (op==2){
					maior_aluguel(apto,count,i);//chamada do procedimento que mostra o maior aluguel do predio;
				}else{
					if (op==3){
						alug_pag(apto,count,i);//chamada do procedimento que realiza o calculo dos alugueis; 
					}else{
						if (op==4)
						{
							cal_mora(apto,count,i,vet_soma,vet_and);//chamada do procedimento que calcula a quanditade de moradores no predio, por andar;
							maior_pes_and(vet_soma,vet_and,count,i,apto);//chamada do procedimento que printa o andar com maior numero de pessoas no predio;
					}else{
						if (op==5){
							cal_mora(apto,count,i,vet_soma,vet_and);//chamando o mesmo procedimento;
							menor_ap_mos(vet_soma,vet_and,count,i,apto);//chamada do procedimento que mostra o andar com o menor numero de moradores possivel;
						}else{//caso o usario aperte 0 é enterrompido o laço e se encerra o programa;
							printf("Saindo do programa...\n");
							break;
						}
					}
				}
			}

		}
	}while(op==0);
}
//procedimento que limpa todo o vetor de registro;
void limpa(TipoPredio *apto,int count,int i){
	for (i = 0; i < count; ++i)
	{
		apto[i].numero_ap = 0;
		apto[i].andar_ap = 0;
		apto[i].quant_pe = 0;
		apto[i].alug = 0;
	}
}
void limpa_vet(int *v_and,int *v,int count,int i){
	for ( i = 0; i < count; ++i)
	{
		v[i]= 0;
		v_and[i]=0;
	}
}
//procedimento que mostra o maior aluguel por morador;
void maior_aluguel(TipoPredio *apto,int count, int i){
	float menor = 0;
	float maior = 0;
	for ( i = 0; i < count; ++i)
	{
		menor = apto[i].alug;
		if (menor > maior)
		{
			maior = menor;
		}
	}
	printf("\nMaior Aluguel é :%.2f\n", maior);
	printf("\n\n\n");
	menu(apto,count,i);
}
//função para mostrar os dados de cada ap;
void dados(TipoPredio *apto,int count, int i){
	for (int i = 0; i < 9; ++i){
		if (apto[i].quant_pe== 0){
				break;
			}
		printf("Numero Do Apartamento: %d\n", apto[i].numero_ap);
		printf("Andar:%d\n",apto[i].andar_ap );
		printf("Quantidade De Pessoas: %d\n",apto[i].quant_pe );
		printf("Valor Do Aluguel: %.2f\n",apto[i].alug );
		printf("Nome Do Propriatario: %s\n",apto[i].propriatario);
		printf("\n");
		
	}
	printf("Fim dados\n");
	printf("\n\n\n");
	menu(apto,count,i);//chamada do menu novamente para ficar em um laço até que seja precionado 0;
}
//função que calcula os alugueis pagos
//soma dos alugueis pago de cada andar;
void alug_pag(TipoPredio *apto,int count,int i){
	int soma;
	int pag_soma[count]; // variavel alxiliar;
	int v_and[count];
	limpa_vet(pag_soma,v_and,count,i);
	//esta parte ficou estença pq não consegui zerar de outra forma e essa foi a melhor solução, que consigui encontrar;
	//nesta parte  é verificada as condições se estiverem ok a variavel soma(recebe o valor do aluguel do vetor de registro e guarda em outro vetor);
	for ( i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
			{
				if ((apto[j].andar_ap==i)&& (apto[j].quant_pe >0))
				{
					soma +=apto[j].alug;
					pag_soma[j]=soma;
					v_and[j]=apto[j].andar_ap;
				}
			}
		soma =0;	
	}	
	alug_pag_m(pag_soma,v_and,count,i,apto);
}
//procedimento que mostra os alugueis pagos por andar no caso a soma dos alugueis;
void alug_pag_m(int *vet_soma,int *vet_and,int count,int i,TipoPredio *apto){
	printf("\n");
	for (i = 0; i < count; ++i)//este for realiza o caminho de cada andar travando no andar;
	{
		alug_pag_mo(vet_soma,vet_and,count,i,apto);//cahmada do procedimento;
	}
	printf("Fim dos dados...\n");
	printf("\n\n");
	menu(apto,count,i);//chamada do menu novamente para ficar em um laço até que seja precionado 0;
}
//procedimento para mostrar os alugueis
void alug_pag_mo(int *vet_soma, int *vet_and, int count,int i,TipoPredio *apto){
	int maior= 0;
	int menor= 0;
	int andar = 0;
	for (i = 0; i < count; ++i)//for para pecorrer todo o vetor de soma e do andar;
	{
		menor =vet_soma[i];
		if ((menor> maior))
		{
			maior = menor;
			andar = vet_and[i];
			vet_soma[i]=0;
		}
	}
	printf("o andar : %d\n",andar);
	printf("aluguel: %d\n",maior );
}
//procedimento que mostar o ap que tem o maior numero de moradores;
void cal_mora(TipoPredio *apto, int count, int i,int *vet_soma,int *vet_and){	
	int soma=0;
	//parte que limpa os dois vetores;
	limpa_vet(vet_and,vet_soma,count,i);
	/*nesta parte deve se calcular a soma das pessoas caso a condição nao seja atendida a soma recebe zero, para cada fim de
	 andar a soma recebe zero e foi assim para os seguintes (não encontrei outro metodo por isso utilizei este que mostrou melhor 
	 	resultado dentre todos que testei);*/
	for ( i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
			{
				if ((apto[j].andar_ap==i)&& (apto[j].quant_pe >0))
				{
					soma +=apto[j].quant_pe;
					vet_soma[j] = soma;
					vet_and[j] = apto[j].andar_ap;
				}
			}
		soma =0;	
	}
//(apto[i].andar_ap==0)&&(apto[i].quant_pe > 0)? (vet_and[i]= apto[i].andar_ap),(soma += apto[i].quant_pe),(vet_soma[i]= soma):(soma = 0);	
	
}
//procedimento para encontrar o  andar com o maior numero de pessoas e printa o andar correspondente;
void maior_pes_and(int *vet_soma,int *vet_and,int count,int i,TipoPredio *apto){
	int maior= 0;
	int menor= 0;
	int andar = 0;
	printf("\n");
	for (i = 0; i < count; ++i)
	{
		menor =vet_soma[i];
		if ((menor> maior))
		{
			maior = menor;
			andar = vet_and[i];
		}
	}
	printf("o andar com maior numero de pessoas é: %d\n",andar);
	printf("Fim dados\n\n\n");
	menu(apto,count,i);//chamada do menu novamente para ficar em um laço até que seja precionado 0;
}
//procedimento que mostra o andar com o menor numero de moradores;
void menor_ap_mos(int *v,int *v_and,int count,int i,TipoPredio *apto){
	int maior= 999999999;
	int menor= 0;
	int andar = -1;
	for (i = 0; i < count; ++i)
	{
		menor =v[i];
		if ((menor<= maior)&&(v[i]> 0))
		{
			maior = menor;
			andar = v_and[i];
		}
	}
	printf("\nO andar com menos apartamento é: %d\n",andar);
	printf("\nFim\n\n\n");
	menu(apto,count,i);//chamada do menu novamente para ficar em um laço até que seja precionado 0;
}