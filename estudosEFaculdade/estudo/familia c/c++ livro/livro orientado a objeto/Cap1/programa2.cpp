#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
	//sizeof()retorna a quantidade memoria que cada variavel utiliza;
	int a =0;// 4bytes
	short int b = 0;//2bytes
	long int c = 0;// 8 bytes 
	int a2 = 0;
	signed int b2 = -10;//
	unsigned int c2 = -10;//nao amarzena numeros com sinais ou seja negativos(nao pode ter numeros negativos ou seja não armazena numéros negativos)
	cout << sizeof(a) << " - "<< a2 << endl;
	cout << sizeof(b) << " - "<< b2 << endl;
	cout << sizeof(c) << " - "<< c2 << endl;
	char caractere = 127;

}