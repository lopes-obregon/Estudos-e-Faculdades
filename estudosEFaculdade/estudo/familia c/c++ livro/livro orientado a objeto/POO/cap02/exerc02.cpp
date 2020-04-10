#include <iostream>
//programa que faz a geração de 10 em 10 numeros com encremento de decremento;
using namespace std;
int main(int argc, char const *argv[])
{
	int x;
	x += 10;
	cout <<"valor :" << x << endl;
	x += 10;
	cout << "valor: " << x << endl;
	x += 10;
	cout << "valor: " << x << endl;
	x-= 11;
	cout <<"valor: " << x << "x" << endl;
	return 0;
}