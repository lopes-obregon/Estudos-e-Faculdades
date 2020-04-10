#include <stdio.h>
#include <stdlib.h>
//função principal
int main (){
	FILE *arq;
	int result;
	arq = fopen("numeros.txt","rt");	
	if (arq == NULL){
		printf("O arquivo não foi encontrado :'(\n");
		exit(1);
	}else{
			printf("O arquivo foi aberto com sucesso.\n");
			while ((result=fgetc(arq)) != EOF){
			//lê uma linha (inclusive o '\n')
			//para dados a serem lidos do arquivo;
			printf("%d\n",result );
		}
		fclose(arq);
	}

	return 0;	
}
