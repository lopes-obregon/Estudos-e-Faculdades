#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//prototipo da função
void gera (int numero,FILE *arq);
//função principal
int main (){
	int numero;
	FILE *arq;
	arq = fopen("numeros.txt","w");
	if (arq == NULL){
		printf("Arquivo não foi possivel ser abeerto.zn");
		exit (1);
	}else {
		printf("Arquivo aberto com sucesso.\n");
		gera(numero,arq);//gera n numeros aleatorios; 
	}

	return 0;
}

void gera (int numero,FILE *arq){
	int n,x,y;
	srand(time(NULL));
	printf("Digite, a quantidade de linhas\n");
	scanf("%d",&n);
	printf("Digite o intervalo de x: \n");
	scanf("%d",&x);//x tendo como base x sendo o menor;	
	printf("Digite o intervalo de y: \n");
	scanf("%d",&y);	//considerando que y sendo o maior;
	fprintf(arq,"%d\n",n);
	for(int i=0; i<n; i++){
		numero = (x+(rand()%(y-x+1)));
		fprintf(arq,"%d\n",numero);
	}
	fclose(arq);
}
