#include <iostream>
using namespace std;
//estrutura de dados
//prototipos da função
void calcula(float p1, float p2,float p3, float p4, int i);
void entrada(int count);
int  pergunta();
//variaveis global
int op;
//função principal
//programa que calcula a media aritméticas das notas de n alunos;
int main(int argc, char const *argv[])
{
	//função que calcula e exibe a média aritmética das notas digitadas(ok)
	//um conjunto de n alunos;(ok)
	//deve aceitar entrada de novas notas para controlar a execução do programa;
	cout << "Digite a quantidade de alunos : " << endl;
	//int op;
	cin >> op;
	entrada(op);
	do
	{
	} while (pergunta() == 1);
	return 0;
}
//função que calcula a media das notas digitadas;
void calcula(float p1, float p2,float p3, float p4, int i){
	float media;
	media = ((p1 + p2 + p3 + p4)/4);
	cout << "Média do aluno " << i << ":" << media << endl;
}
//função que faz a entrada dos dados (as notas);
void entrada(int count){
	float n1,n2,n3,n4;
	for (int i = 0; i < count; ++i){	
		cout << "Digite a nota do aluno :" << i << endl;
		cin >> n1 >> n2 >> n3 >> n4;
		calcula(n1,n2,n3,n4,i);
	}
}
//função que faz a pergunta para manter o laço da função;
int  pergunta(){
	cout << "Deseja entrar com mais dados(n-nao s-sim) ?";
	char resposta;
	int rep;
	 cin >> resposta;//le os dados digitados pelo usuario;
	if (resposta == 'n')//nao
	{
		rep = 0; 
		return rep;
	}else{
		if (resposta == 's' )//sim
		{
			cout << "Quantos alunos deseja que acresentar ?" << endl ;
			cin >> op;
			entrada(op);
		}
	}
}	