#include <iostream>
using namespace std;
//variavel global
//estrutura de dados
//classes
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
	Medida(int m, double c){
		//define medida
		metro = m;
		centimetro = c;
	}
	//obetem medida do usuario
	void getMedida(){
		cout << "\n Digite a parte de metros da medida: ";
		cin >> metro;
		cout << "\n Digite a parte de centimetros da medida: ";
		cin >> centimetro;
	}
	//mostra a medida
	void mostraMedida(){
		cout << (metro + centimetro/100) << " metros \n";
	}
	Medida operator + (Medida m1);
	friend double quadrado (Medida m1);//função que acessa o dobro do quadrado;
	friend double area(Medida m1);//função que calcula a area das medidas;
	
};
//retorna o valor da soma;
Medida Medida::operator + (Medida m1){
	int m = metro + m1.metro;
	double c = centimetro + m1.centimetro;

	if (centimetro >= 100.0)
	{
		c -= 100.0;//decrementa centimetro
		m++;
	}
	return Medida(m, c);
}
//pre-função que retorna o quadrado da medida
double quadrado(Medida m){
	double parteMetro = m.metro + m.centimetro/100;//converte para metro
	return parteMetro*parteMetro;//converte para pes	
}
double area(Medida m){
	double parteMetro = m.metro * m.centimetro/100;//transforma para metro;
	//tomamos conta que a area seja lado x lado;
	double area = parteMetro*parteMetro;
	return area;
}
//prototipos da função
//função principal
int main(int argc, char const *argv[])
{
	Medida m1, m3;//cria 2 objetos Medida
	Medida m2(12, 5.0);
	double 	mQuadrado;//variavel metros quadrado;
	m1.getMedida();
	m3 = m2 + m1;
	mQuadrado = quadrado(m3);
	double aream;
	aream = area(m1);
	cout << "\n Valores atualizados das medidas \n";
	cout << "\n Medida 1 = "; m1.mostraMedida();//exibe valor total metros;
	cout << "\n Medida 2 = "; m2.mostraMedida();
	cout << "\n Medida 3 = "; m3.mostraMedida();
	cout << "\n Quadrado da medida m3 = " << mQuadrado;
	cout << "\n area m1 = " << aream;
	cout << endl << endl;
	return 0;
}
