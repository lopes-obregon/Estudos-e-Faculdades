#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
//clear && gcc ex.c && ./a.out <dados.txt

/*tipo de dados{rgm int,nome char [100], faltas int}(ok),vetor de alunos com 10 posições(ok).
programa deve : solicitar a quantidade de aulas(ok)
// junto com as faltas.	
	inteiro aulas
	escreva("informe as aulas");
	leia("%d",aulas);
	
-monstrar alunos reprovados por faltas (>25%)(ok).
void reprovados(TipoAluno al){// função para apresentar os alunos com mais de 25% de faltas.
//aqui deve ser o numero de faltas maior que 25%;
	aulas =(aulas*0.25); numero de aulas ex: 100 e o numero de faltas são 30	
	al.falta > aulas
se (al.faltas > aulas)então
		escreva (" Os alunos reprovados por faltas são : \n");
		escreva ("%c \n",al.nome);
	
}
-criar um vetor de alunos ordenados, de forma crescente, por faltas.POde sujar o vetor().

*/

// Definição dos Tipos de Dados
typedef struct Aluno{
	char nome[100];
	int rgm;
	int faltas;
}TipoAluno;

// Protótipos de Funções
void imprime1(TipoAluno reg);
void imprimev(TipoAluno v[]);
void limpav(TipoAluno v[]);
void entradav(TipoAluno v[]);
void ordenav(TipoAluno ori[], TipoAluno des[]);
void copia1(TipoAluno *d, TipoAluno o);
void limpa1(TipoAluno *reg);

// Função Principal
int main(int argc, char *argv[]){

	TipoAluno vet[MAX];
	TipoAluno ord[MAX];
	int aulas;

	limpav(vet);
	entradav(vet);
	printf("########################## Vetor DESORDENADO.\n");
	imprimev(vet);
	
	limpav(ord);
	
	ordenav(vet,ord);

	printf("########################## Vetor ORDENADO.\n");
	imprimev(ord);

	return(0);
}

//Função que imprime 1 unico registro
void imprime1(TipoAluno reg){
	printf("Nome: %s(%d). Faltas: %d\n",reg.nome,reg.rgm,reg.faltas);
}

//Função que imprime o vetor
void imprimev(TipoAluno v[]){
	int i;
	for (i = 0; i < MAX; ++i){
		imprime1(v[i]);
	}
}

//Função que limpa o vetor de registro
void limpav(TipoAluno v[]){
	int i;
	for (i = 0; i < MAX; ++i){
		v[i].rgm = 0;
		strcpy(v[i].nome,"");
		v[i].faltas = -1;
	}
}

//Função que faz a entrada dos dados
void entradav(TipoAluno v[]){
	int i;
	for (i = 0; i < MAX; ++i){
		//printf("Digite o nome do %d aluno: ",i+1);
		scanf(" %s",v[i].nome);
		//printf("Digite o RGM: ");
		scanf(" %d",&v[i].rgm);
		//printf("Digite a quantidade de Faltas: ");
		scanf(" %d",&v[i].faltas);
	}	
}

//Função que copia um registro para outro
void copia1(TipoAluno *d, TipoAluno o){
	strcpy(d->nome,o.nome);
	d->rgm = o.rgm;
	d->faltas = o.faltas;
}

//Função que limpa 1 unico registro
void limpa1(TipoAluno *reg){
	strcpy(reg->nome,"");
	reg->rgm = 0;
	reg->faltas = -1;
}

//Função que ordena o vetor
void ordenav(TipoAluno ori[], TipoAluno des[]){
	int i,j,f,pos;
	TipoAluno aux;

	limpa1(&aux);
	for (i = 0; i < MAX; ++i){
		f = 99999999;
		for (j = 0; j < MAX; ++j){
			if ((ori[j].faltas < f)&&(ori[j].faltas >= 0)){
				f = ori[j].faltas;
				pos = j;
			}			
		}
		copia1(&aux,ori[pos]);
		limpa1(&ori[pos]);
		copia1(&des[i],aux);
	}
}
