#include <iostream>
using namespace std;
//estrutura dedadps
//protótipos da função
int maior_menor();
//variaveis global
//função principal
int main(int argc, char const *argv[])
{
	//função que solicite a entrada de 2 numeros e retorne o maior entre eles;
	cout << "Maior numero digitado é :" << maior_menor() << endl;
	return 0;
}
//função que retorna o maior numero digitado;
int maior_menor(){
	cout << "Digite os dois numeros para encontrar o maior numero entre eles: ";
	int n1,n2;
	cin >> n1 >> n2;
	if (n1 > n2)
	{
		return n1;
	}else{
		return n2;
	}

}