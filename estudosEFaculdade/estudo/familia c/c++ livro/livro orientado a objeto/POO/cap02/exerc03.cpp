#include <iostream>
//programa que faz a geração de 10 em 10 numeros com encremento de decremento;
using namespace std;
int main(int argc, char const *argv[])
{
	int x;
	x += 10;
	cout <<"incremento :" << x << endl;
	x += 10;
	cout << "incremento: " << x << endl;
	x += 10;
	cout << "incremento: " << x << endl;
	x -= 10;
	cout << "Decremento :" << x << endl;
	x -= 10;
	cout << "Decremento :" << x << endl;
	x -= 10;
	cout << "Decremento :" << x << endl;

 	return 0;
}