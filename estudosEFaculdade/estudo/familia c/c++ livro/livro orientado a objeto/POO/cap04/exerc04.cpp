#include <iostream>
using namespace std;
//tipos de dados
struct tempo
{
	int horas;
	int segundos;
	int minutos;
};
//função principal
int main(int argc, char const *argv[])//programa que faz a soma das horas sendo elas t e t2;
{
	tempo t,t2;
	//deve entrar com dados ao usuario para t e t2 e depois fazer a soma de ambos
	cout << "digite as Horas/minutos/segundos do primeiro tempo: ";
	cin >> t.horas >> t.minutos >> t.segundos;
	cout << "Digite as Horas/Minutos/segundos do segundo tempo : ";
	cin >> t2.horas >> t2.minutos >> t2.segundos;

	int somah,somam,somaseg;
	somah = t.horas + t2.horas;
	somam = t.minutos + t2.minutos;
	somaseg = t.segundos + t2.segundos;
	cout << "A soma do primeiro tempo mais o segundo é: ";
	cout << somah << ":" << somam << ":" << somaseg << endl;
	return 0;
}