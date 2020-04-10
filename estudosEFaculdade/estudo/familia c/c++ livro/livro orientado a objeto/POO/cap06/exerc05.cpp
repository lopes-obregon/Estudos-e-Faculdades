#include <iostream>
using namespace std;
//estruturas de dados
//prototipos da função
//variavel global
//classes
class Distancia
{
private:
	float x;
public:
	void getDados(){
		cout << "Infome as cordenadas dos pontos : ";
		cin >> x;
	}
	float calculaDistancia(){	
		return x;
	}
	float mostraDados(){
		return x;
	}
	
};
//função principal
int main(int argc, char const *argv[])
{
	Distancia p1, p2;
	p1.getDados();//entrada de dados
	p2.getDados();
	cout << "os daodos do ponto 1 é: " << p1.mostraDados() << endl;//mostra os dados armazenados;
	cout << "os daodos do ponto 2 é: " << p2.mostraDados() << endl;
	cout << "Á Distancia é :" << p1.calculaDistancia() - p2.calculaDistancia();
	return 0;
}