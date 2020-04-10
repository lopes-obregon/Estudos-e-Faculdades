#include <iostream>
using namespace std;
//estruturas de dados
struct corrdenada
{
	int x;
	int y;
};
//prototipos da função
float calculadis(corrdenada p, corrdenada p2);
//variaveis globais;
//função principal
//programa que retorna a distancia de dois pontos;
int main(int argc, char const *argv[])
{
	corrdenada p;
	corrdenada p1;
	cout << "Informe os 2 pontos para calcular a distaia do plano IR 1 ";
	cin >> p.x >> p1.x;
	cout << "a distancia é :" << calculadis(p,p1) << endl;
	return 0;
}
//função que calcula a distacia dos dois pontos
float calculadis(corrdenada p, corrdenada p2){
	/*	a distancia dos pontos

	p1 -p2
	*/
	float distancia;
	distancia = p.x - p2.x;
	return distancia;
}