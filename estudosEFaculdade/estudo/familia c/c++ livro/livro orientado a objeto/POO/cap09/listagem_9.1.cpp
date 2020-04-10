#include <iostream>
using namespace std;
//programa para ilustrar o uso de herança;
class Contador
{
protected:
	unsigned int contador;//remove o suporte a negativo;
public:
	Contador(){
		//construtor sem argumento.
		contador = 0;
	}
	Contador(int c){//construtor com 1 argumento
		contador = c;
	}
	int getContador() // retorna contador
	{
		return contador;
	}
	Contador operator ++ ()//pré-incremento
	{
		return Contador (++contador);
	}
};
class Decrementa:public Contador //classe derivada
{
public:
	Contador operator -- ()//decremento de contador
	{
		return Contador(--contador);
	}
};
int main(int argc, char const *argv[])
{
	Decrementa c1; // cria 1 objeto Decrementa
	cout << "\n Valor incial do objeto contador c1 = " << c1.getContador();
	++c1; ++c1; ++c1; ++c1;//incremeto c1 4 vezes
	cout << "\n Valor do depois do incremento de c1 = " << c1.getContador();
	--c1; --c1; --c1; // decremento c1 3 vezes
	cout << "\n Valor depois do decremento de c1 = " << c1.getContador();
	cout << endl << endl;
	return 0;
}