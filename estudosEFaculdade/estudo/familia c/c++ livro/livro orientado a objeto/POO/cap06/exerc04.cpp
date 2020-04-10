#include <iostream>
using namespace std;
//estrutura de dados
//variaveis globais
//prototipos das funções
//classes
class Retangulo
{
private:
	int largura;
	int altura;
public:

	void getRetangulo(){//entrada dos dados 
		cout << "Informe a entrada de da medidas largura e altura: ";
		cin >> largura >> altura;

	}
	int areaRetangulo(){ //exibe a area do retangulo
		return largura * altura;

	}
	
};
//função principal;
int main(int argc, char const *argv[])
{
	Retangulo r1;
	r1.getRetangulo();
	cout << "Area do retangulo é : " << r1.areaRetangulo() << endl;
	return 0;
}