#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//operação ternária;
	cout << "Digite um numéro: " << endl;
	int i=0;
	cin >> i;
	string texto = (i<= 10) ? "menor do que dez" : "maior do que dez";// tipo <variavel> = (condição) ? => (se a condição for verdade)(valor1) : => (se não) o (valor 2 )
	cout << "o valor digitado anteriormente é: " << texto << endl;
	return 0;
}