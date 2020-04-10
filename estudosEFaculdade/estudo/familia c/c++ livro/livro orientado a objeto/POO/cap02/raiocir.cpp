#include <iostream>
#define PI 3.14159
//listaguem 2.9;
//programa para calcular o volume de uma esfera com raio informado pelo usuario;
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char const *argv[])
{
	double volume, raio,area;
	raio = 5.0;// definição do valor do raio;
	cout << "Digite o valor do raio para fazer o calculo: ";
	cin >> raio;//parte de entrada de dados;
	volume=(4.0/3.0)*PI*(raio*raio*raio);//formula do volume da esfera	
	//Exibe na tale o valor calculado;
	std::cout << "O valor do volume é = "<< volume <<"\n\n";
	system("PAUSE");
	return 0;
}