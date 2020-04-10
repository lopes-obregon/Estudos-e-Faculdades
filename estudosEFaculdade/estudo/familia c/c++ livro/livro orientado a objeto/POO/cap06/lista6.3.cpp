#include <iostream>
using namespace std;
//estrutura de dados
//prototipos de funções
//variaveis globais
//classes
class Medida
{
private:
	int metro;
	float centimetros;
public:
	void setMedida(int m, double c){//define medida;
		metro = m;
		centimetros = c;
	}
	void getMedida(){//obtem medidas do usuario;
		cout << "\nDigite a parte de metros da medida: ";
		cin >> metro;
		cout << "\n DIgite a parte de centimetros da medida: ";
		cin >> centimetros;
	}
	void mostraMedida(){//monstra medidas
		cout << (metro + centimetros/100) << " metros \n";
	}
};
//função principal
int main(int argc, char const *argv[])
{
	Medida m1 ,m2;//cria 2 objetos de Medidas;
	m1.setMedida(25, 50);//define valores do objetos m1;
	m2.getMedida();//obtem valores para o objeto m2;
	cout << "\nMedida 1 = "; m1.mostraMedida();//exibe o valor total;
	cout << "\n Medida 2 = "; m2.mostraMedida();
	cout << endl;
	return 0;
}
