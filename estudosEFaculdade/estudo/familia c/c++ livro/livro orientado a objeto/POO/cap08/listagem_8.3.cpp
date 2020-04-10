#include <iostream>
using namespace std;
//programa para ilustrar a sobrecarga de operadores;
//estruturas de dados
//variaveis globais
//classes
class Contador // especificação de classe
{
	int contador;
public:
	Contador() { contador = 0;}// construtor;
	Contador(int c){contador = c ;}//construtor quando com 1 argumento;
	int getContador() {return contador;} // retorna contador
	Contador operator ++() //pré-incremento
	{
		++contador;//incremento contador
		return (contador); // retorna o valor;
	}
};
//protótipos das funções
//função principal
int main(int argc, char const *argv[])
{
	Contador c1 ,c2 ,c3; //declaração de 2 objetos contador
	cout << "\nContador 1 antes do incremento = " << c1.getContador();
	cout << "\n Contador 2 antes do incremento = " << c2.getContador();
	cout << "\n Contador 3 antes do incremento = " << c2.getContador();
	++c1; // c1 = 1 incremento c1 duas vez 
	++c1;
	++c2; // c2 =1 incrementa c2 3 vezes;
	++c2; // c2 = 2	
	c3 = ++c2; // c3 =3 c2 = 3;
	cout << "\n\n Contador 1 depois do incremento = " << c1.getContador();
	cout << "\n contador 2 depois do incremento =  " << c2.getContador();
	cout << "\n contador 3 depois do incrmento = " << c3.getContador();
	cout << endl << endl;
 	return 0;
}