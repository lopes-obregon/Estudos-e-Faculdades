#include <iostream>
using namespace  std;
//programa para ilustrar o uso de herança
class Contador //especificação da classe base Contador
{
protected:
	unsigned int contador;
public:
	Contador(){
		//construtor sem argumento.
		contador = 0;
	}
	Contador(int c) {
		//construtor com 1 argumento
		contador = c;
	}
	int getContador(){
		//retorna contador
		return contador;
	}
	Contador operator ++ (){
		//pré-incremento de contador
		return Contador (++contador);
	}
};
class Decrementa: public Contador //classe derivada
{
public:
	Decrementa(): Contador()//construtor sem argumento
	{}
	Decrementa(int c): Contador(c){}//construtor com 1 argumento 
	Decrementa operator -- (){
		//decremento de contador
		return Decrementa(--contador);
	}
};
int main(int argc, char const *argv[])
{
	Decrementa c1;//cria 1 objeto Decrementa
	Decrementa c2(10);
	cout << "\n Valor inicial do objeto contador c1 = " << c1.getContador();
	cout << "\n Valor inicial do objeto contador c1 = " << c2.getContador();
	++c1; ++c1; ++c1; ++c1; //incremeta c1 4 vezes;
	cout << "\n Valor depois do incremento de c1 = " << c1.getContador();
	--c1; --c1; --c1; //decrementa c1 3 vezes
	--c2; --c2; --c2; --c2;//decrementa c2 4 vezes
	cout << "\n\n Valor depois do decremento de c1 = " << c1.getContador();
	cout << "\n\n Valor depois do decremento de c2 = " << c2.getContador();
	cout << endl << endl;
	while (1){
		++c1;
		++c2;
		cout << "\nValor incrementado em c1 = " << c1.getContador();
		cout << "\nValor incrementado em c2 = " << c2.getContador();
	}
	return 0;
}