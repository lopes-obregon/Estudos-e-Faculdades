#include <iostream>
using namespace std;
//Programa para ilustrar a conversão de dados
const float METRO_PARA_PES = 3.2808; // taxa conversão metros p/ pés;
//que permite a soma de dois objetos;
//variavel global
//estruturas de dados
//prototipos das funções
//classes
class Medida// Espicificação da classe Medida
{
private:
	int metro;
	double centimetro;
public:
	Medida(){
		metro = 0;
		centimetro = 0.0;
	}
	Medida(int m, double c)//define medida
	{
		metro = m;
		centimetro = c;
	}
	Medida(double m) // construtor com argumento
	{
		double doubleMetro =m;
		metro = int (doubleMetro);//parte intteira
		centimetro = 100*(doubleMetro - metro); // parte fracionaria
	}
	void getMedida(){//obtem medida do usuario
		cout << "\nDigite a parte de metros da medida: ";
		cin >> metro;
		cout << "\nDigite a parte de centimetros da medida: ";
		cin >> centimetro;
	}
	void mostraMedida(){ //exibe medida
		cout<< (metro + centimetro/100) << " metros \n";
	}
	operator double()//função conversão
	{
		double parteMetro = centimetro/100;//converte para metro
		parteMetro += double(metro); // adiciona parte de metros
		return parteMetro*METRO_PARA_PES;//converte para pes
	}
	Medida Medida::operator + (Medida m1)//retorna o valor da soma
	{
		int m = metro + m1.metro;
		double c =centimetro + m1.centimetro;
		if (centimetro >= 100.0)
		{
			c -= 100.0; // decrementa centimetro
			m++;
		}
		return Medida(m,c);
	}
	
};
//função pincipal
int main(int argc, char const *argv[])
{
	Medida m1,m3;//cria 2 objetos Medida
	Medida m2 (100.25);
	m1.getMedida(); //obtem o valor para objeto m1
	cout << "\nValores inicias das medidas"; //exibe as medidas
	cout <<"\nMedida 1 = "; m1.mostraMedida();
	cout <<"\nMedida 2 = "; m2.mostraMedida();
	cout <<"\nMedida 3 = "; m3.mostraMedida();

	m3 = m2 + m1; // m3 = m2 + m1
	cout << "\nValores atualizados das medidas \n";
	cout << "\n Medida 1 = "; m1.mostraMedida(); //exibe valor total em metros
	cout << "\nMedida 2 = "; m2.mostraMedida();
	cout << "\nMedida 3 = "; m3.mostraMedida();
	cout << endl;
	double pes = double (m1);//chamada a função de conversão
	cout << "\nValor medida m1 convertido para pes\n";
	cout << "\n Valor medida m1 = " << pes << "pes \n\n";
	return 0;
}