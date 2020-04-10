#include <iostream>
using namespace std;
//variavel global
//estrutura de dados
//prototipos das funções
//classes
class Contador
{
private:
	int contador; // variavel privada;
public:
	Contador(){contador = 0;}
	int getContador()
	{
		return contador;//retorna contador
	}
	void operator +=(int a){
		//variavel = variavel + variavel2
		contador += 3;//pré-incremento
	}
};
//função principal
int main(int argc, char const *argv[])
{
	Contador c1, c2; // declaração de 2 objetos contador
	cout << "\n Contador 1 antes do incremento = " << c1.getContador();
	cout << "\n Contador 2 antes do incremento = " << c2.getContador();
	int a;
	c1 += a;// c1 = c1 + ???;
	c1 += a;
	c2 += a;//incremento dos objetos
	cout << "\n Contador 1 depois do incremento = " << c1.getContador();
	cout << "\n Contador 2 depois do incremento = " << c2.getContador() << endl;
	return 0;
}