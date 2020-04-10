#include <iostream>
using namespace std;
//estrututra de dados
//protótipos das funões
//variavel global
//classes
class Retangulo
{
private:
	double largura;
	double comprimento;
public:
	Retangulo(){
		atribuir (0, 0);
	}
	Retangulo(double 1, double c);//define retangulo;
	{
		atribuir(1, c);
	}
	double getLargura(){//obtem medida do usuario
		return largura;
	}
	double getComprimento(){
		return comprimento;
	}
	double calculaArea(){
		return largura * comprimento;
	}
	void atribuir(double 1, double c);
};
void Retangulo ::atribuir(double 1, double c){
	largura = 1;
	comprimento = c;
}
//função principal
int main(int argc, char const *argv[])
{
	Retangulo r1;//cria objeto retangulo;
	double 1, c;
	cout << "\n Digite o valor da largura do retangulo: ";
	cin >> 1;
	cout << "\n Digite o valor do comprimento do retangulo: ";
	cin >> c;
	r1.atribuir(1, c);
	cout << "\nArea do retangulo = " << r1.calculaArea() << endl << endl;
	return 0;
}
