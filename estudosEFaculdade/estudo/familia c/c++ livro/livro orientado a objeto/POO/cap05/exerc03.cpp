#include <iostream>
using namespace std;
//estrutura de dados
//variaveis global
float op;
//prototipos da função
void converte ();
float converte ();
//função principal
int main(int argc, char const *argv[])
{
	//programa que faz a conversão de moedas;
	//fazer uma função que converta dolar em reais(ok)
	//que possa ser chamadas varias vezes que o usuario pedir;
	cout << "Por favor digite a cotação do dolar para converter ou tecle -1 para usar converção atual";
	cin >> op;
	if (op == -1)
	{
		converte();
	}
	converte();
	return 0;
}
//função que converte moedas com cotação atual;
void converte (){
	float moeda;
	cout << "Digite a quantidade de moedas a converter para reais, cotação $ 3.3075 ";	
	moeda *= 3.3075;//parte automatica
	cout << "Valor convertido" << moeda << endl;
}	
//função que converte moedas com cotação informada;
float converte (){
	float moeda;
	cout << "Digite a quantidade de moedas a converter para reais ";	
	moeda *= op;
	cout << "Valor convertido" << moeda << endl;
}