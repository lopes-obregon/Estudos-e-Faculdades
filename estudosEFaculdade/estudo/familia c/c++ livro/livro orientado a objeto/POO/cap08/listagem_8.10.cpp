#include <iostream>
using namespace std;
//programa para ilustrar uso de funções friend
class Medida
{
private:
	int metro;
	double centimetro;
public:
	Medida(){
		metro = 0;
		centimetro = 0.0;
	}
	Medida(int m, double c){//define medida
		metro = m;
		centimetro = c;
	}
	void getMedida()//obtem medida do usuario
	{
		cout << "\n Digite a parte de metros da medida: ";
		cin >> metro;
		cout << "Digite a parte de centimetros da medida: ";
		cin >> centimetro;
	}
	void mostraMedida(){
		cout << (metro + centimetro/100) << "metros \n";
	}
	Medida operator + (Medida);
	friend double quadrado (Medida m1); //função friend
};
Medida Medida::operator + (Medida m1)//retorna o valor da soma
{
	int m = metro +m1.metro;
	double c = centimetro + m1.centimetro;
	if (centimetro >= 100.0)//testa se centimetro >= 100
	{
		c -= 100.0;//decrementa centimetro
		m++;
	}
	return Medida(m, c);
}
double quadrado(Medida m){
	double parteMetro = m.metro + m.centimetro/100;// converte para metro
	return parteMetro*parteMetro;//converte para pes
}
int main(int argc, char const *argv[])
{
	Medida m1, m3; // cria 2 objetos Medida
	Medida m2(12, 5.0);
	double mQuadrado;
	m1.getMedida();
	m3 = m2 + m1; // m3 = m2 + m1
	mQuadrado = quadrado(m3);
	cout << "\n Valores atualizados das medidas \n";
	cout << "\n Medida 1 = "; m1.mostraMedida();//exibe valor total metros;
	cout << "\n Medida 2 = "; m2.mostraMedida();
	cout << "\n Medida 3 = "; m3.mostraMedida();
	cout << "\n Quadrado da medida m3 = " << mQuadrado;
	cout << endl << endl;
	return 0;
}