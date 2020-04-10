#include <iostream>
using namespace std;
//estruturas de dados
//variaveis globais
//prototipos da função
//classes
class estoqueCelular
{
private:
	int codigoFabricante;
	int codigoModelo;
	double custo;
public:
	 void setDados(int f, int m, double c){//definição de dados
		codigoFabricante = f;
		codigoModelo = m;
		custo = c;
	}
	void mostraDados()//mostra os dados
	{
		cout << "\n Codigo do fabricante = " << codigoFabricante;
		cout << "\n Codigo do modelo = " << codigoModelo;
		cout << "\n Custo = " << custo;
		cout << endl; 
	}
	
};
//função principal
int main(int argc, char const *argv[])
{
	estoqueCelular obj1,obj2; // declaração de 2 objetos
	obj1.setDados(1234, 777, 117.5);//chamada da função menbro para definir os valores
	obj2.setDados(4567, 999, 599.99);
	obj1.mostraDados();//chamada a função membro para mostrar valores;
	obj2.mostraDados();
	cout << endl;
	return 0;
}