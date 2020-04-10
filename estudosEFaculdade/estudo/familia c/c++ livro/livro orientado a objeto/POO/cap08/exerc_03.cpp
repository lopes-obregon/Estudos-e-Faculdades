#include <iostream>
using namespace std;
//variaveis globais
//classes
class Soma
{
	double num, num2;
public:
	Soma(){
		num = 0.0;
		num2 = 0.0;
	}
	Soma (double valor, double valor2){//define os valores
		num = valor;
		num2 = valor2;
	}
	void getSoma(){
		//obtem os valores pelo usuario
		cout <<"\nDigite os muneros complexo: ";
		cin >> num >> num2;
	}
	void mostraSoma(){
		//exibe o valor da soma
		cout << "valor : " << (num + num2) << endl; 
	}
	Soma operator + (Soma);
};
Soma Soma::operator + (Soma n1)//retorna o valor da soma
{
	int nu = num + n1.num;
	double nu2 = num2 + n1.num2;
	return Soma(nu, nu2);
}
//estruturas de dados
//prototipos de funções
//função principal
int main(int argc, char const *argv[])
{
	Soma v1,v2;
	Soma v3(0, 0.0);
	v1.getSoma();//obtem valor para o objeto 1;
	v3 = v2 + v1;
	v1.mostraSoma(); 
	v2.mostraSoma(); 
	v3.mostraSoma(); 

	
	return 0;
}