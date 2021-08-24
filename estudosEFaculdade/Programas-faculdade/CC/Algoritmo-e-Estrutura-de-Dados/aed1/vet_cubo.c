#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 5
/* um vetor de cubo com 5 posições(ok),gerar 3 inteiros aleatoriamente(ok) p/cada cubo visualizar todos os cubos.(ok)
descobrir 
()qual cubo c/maior volume
()qual o cubo mais {()alto ()largo ()profundo}
()qual cubo com menor volume.*/
	
typedef struct CUBO{
		int l;
		int a;
		int	p;
	}TipoCUBO;
//prototipo da função
void preenche_cubo (TipoCUBO c[]);
void imprime_cubo(TipoCUBO c);
//função principal
int main (){
	int i,aux;
	
	TipoCUBO cubo [MAX];	
	for(i =0; i<MAX;i++){	
		preenche_cubo(cubo);
		imprime_cubo(cubo]);
	}
	return 0;
}

void preenche_cubo (TipoCUBO c[]){//função para preencher um cubo. 
	int 	min=1;
	int max =100;
	int i;
	srand(time (NULL));
	c[i].l = (min+(rand()%(max-min+1)));
	c[i].a	=	(min+(rand()%(max-min+1)));
	c[i].p	=	(min+(rand()%(max-min+1)));//-> para o conteudo do registro.

}

void imprime_cubo(TipoCUBO c){
	printf("L[%.2d],A[%.2d], P[%.2d]\n",c.l,c.a,c.p);


}	
int volume(TipoCUBO C){
	

}
