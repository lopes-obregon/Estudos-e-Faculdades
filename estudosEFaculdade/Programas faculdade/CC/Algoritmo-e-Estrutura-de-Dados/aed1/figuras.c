/*
obs:sou um vidraceiro;
(1)int tipo(1-circulo,2-retangolo){float raio float altura float largura int transparente (1-sim 2-fosco  3-espelho};
-fazer a entrada dos dados para um vetor de MAX intens(ok);(2){teste (0%)}
-mostrar o maior vidro em área dentre todos (ok);(3){teste (0%)}
-mostrar os tipos de áreas dos espelhos;(ok);(4){teste (0%)}
-mostrar retangolo fosco e espeelhados(ok);(5){teste (0%)}
-mostrar circulo,transparente e fosco(ok);(6){teste (0%)}*/
#include <stdio.h>
#include <math.h>
#define MAX 5
//parte das struct  das figuras

typedef struct Figura
{
	int tipo;//para o tipo de figura sendo ela 1- para circolo and 2- for Retangolo;
	float raio ;
	float altura;
	float largura; 
	int transparente;//1- sim 2- fosco 3-espelhos
	
}TipoFigura;
//protótipos da função
int entrada1(int max);
void entrada_dados(TipoFigura v[],int max);
void area_maior(TipoFigura v[],int max);
void tipo_area(TipoFigura v[],int max);
void espelho_retangolo(TipoFigura v[],int max);
void tipo_vet(TipoFigura vet[],int max);
void espelho_circolo(TipoFigura v[],int max);
//função principal
int main (){
	int max;
	max = entrada1(max);//correto
	TipoFigura vet[max];
	tipo_vet(vet,max);
	area_maior(vet,max);
	tipo_area(vet,max);
	espelho_retangolo(vet,max);
	espelho_circolo(vet,max);
	return 0;

}
int entrada1(int max){//função de gambiarra.
	printf ("informe a quantida de intens a ser inseridos.\n");
	scanf("%d",&max);
	return (max);		
}
void tipo_vet(TipoFigura vet[],int max){
	int i;
	for ( i = 0; i < max; ++i)
	{
		printf("informe o tipo de figura a para saber os tipos de dados a ser pedidos\n 1- para circolo ou  2- para retangolo\n");
		scanf(" %d",&vet[i].tipo);


		if(vet[i].tipo == 1){
	
	 		entrada_dados(vet,max);
		}else{
			if(vet[i].tipo == 2){
			entrada_dados(vet,max);
				}
			}
	}

}

void entrada_dados(TipoFigura v[],int max){//função para entrada de dados de ambos.
	int i;
		
		for (i = 0; i < max; ++i)
		{

		
			if(v[i].tipo == 1 ){
					printf("posição (%d)\n",i );
				
					printf("informe a largura do circolo: \n");
					scanf(" %f",&v[i].largura);
					printf("informe a altura do circolo: \n");
					scanf(" %f",&v[i].altura);
					printf("informe a raio do circolo: \n");
					scanf(" %f",&v[i].raio);
					printf("informe o tipo de espelhos de circolo 1- transparente 2- fosco 3-espelhos: \n");
					scanf(" %d",&v[i].transparente);
					
			}else{
				if(v[i].tipo == 2){
					printf("posição (%d)\n",i );
					printf("informe a largura do retangolo: \n");
					scanf(" %f",&v[i].largura);
					printf("informe a altura do retangolo \n");
					scanf(" %f",&v[i].altura);
					printf("informe a raio do retangolo \n");
					scanf(" %f",&v[i].raio);
					printf("informe o tipo de espelhos de circolo 1- transparente 2- fosco 3-espelhos: \n");
					scanf(" %d",&v[i].transparente);
					
				}
			}
		}
}

void area_maior(TipoFigura v[],int max){//função para mostrar o maior raio dos vidros.
	float maior,maiorret,area,raioquad,base,altura;
	float pi = 3.14;
	int i;
	int check=0;
	maior =99999;

	for(i=0;i<max;i++){	
		//parte do circolo.
		if (v[i].tipo == 1&& maior > v[i].raio){
				raioquad=v[i].raio;
				area=pi*pow(raioquad,2);
				maior = area;
				check =1;			
		}else{
		
		//parte do retangolo.
			if (v[i].tipo ==2 && maior > v[i].raio){				
					base = v[i].largura;
					altura = v[i].altura;				
					area=base*altura;
					maiorret = area;
					check =1;
				}
		}
	}
	if (check ==1)
	{
		printf("o circolo com o maior área é: %f \n",maior );
	
	}
	if (check ==1)
	{
		printf("o retangolo com o maior área é:(%d) com : %f \n",i,maiorret );
	}
		
}

void tipo_area(TipoFigura v[],int max){//função para mostrar o tipo de area que existe no vetor de figuras;
	int i;
	float area,pi=3.14;
	float base,altura,raioquad;//gambiarra;
	printf("os tipos de áreas são: \n ");
	//devemos fazer o calculo de cada área da figura a segir.
//area do circulo.
	for(i=0;i<max;i++){
		if (v[i].tipo ==1)//circolo
		{
		
		
			raioquad=v[i].raio;
			area=pi*pow(raioquad,2);
			printf("a area do circulo(%d) é: %f\n",i,area);
		}
		if (v[i].tipo == 2)//retangolo
		{
				base = v[i].largura;
				altura = v[i].altura;				
				area=base*altura;
				printf("a area do retangolo(%d) é: %f\n",i,area);
		}

	}
	
}
void espelho_retangolo(TipoFigura v[],int max){//função para mostrar o tipo de transparencia dos espelhos em retangolo.,fosco e espeelhados
	int i,fosco =0,espeelhados=0;
	for(i=0; i< max;i++){
		if(v[i].transparente== 2){
			fosco =fosco+1;
			
		}else{
			if(v[i].transparente== 3){
				espeelhados= espeelhados+1;
				espeelhados=espeelhados+1;
				
			}
		}
	}
	printf("A quantida de espelhos fosco retangolo é %d\n",fosco);
	printf("A quantida de espelhos espelhados  retangolo é %d\n",espeelhados);
		
}
void espelho_circolo(TipoFigura v[],int max){//função para mostrar o tipo de transparencia dos espelhos em retangolo.,fosco e espeelhados
	int i,fosco =0,transpar=0;
	for(i=0; i< max;i++){
		if(v[i].transparente== 1){
			fosco =fosco+1;
			
		}else{
			if(v[i].transparente== 3){
				transpar= transpar+1;
				
				
			}
		}
	}
	printf("A quantida de espelhos  circolo fosco é %d\n",fosco);
	printf("A quantida de espelhos  circolo transparente  é %d\n",transpar);
		
}
