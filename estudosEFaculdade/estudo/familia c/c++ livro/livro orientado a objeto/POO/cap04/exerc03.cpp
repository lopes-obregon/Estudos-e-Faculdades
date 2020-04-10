#include <iostream>
using namespace std;
//tipos de dados
struct cordenada
{
	float x;
	float y;
};
//função principal
int main(int argc, char const *argv[])//programa que faz o calculo de dois pontos de uma cordenada do espaço (IR 2)
{
	cordenada p1,p2;
	cout << "Digite as cordaenadas dos pontos 1 e 2 do espaço (IR 2): ";
	cout << "Digite as 2 cordenadas de x para os dois pontos.";
	cin >> p1.x >> p2.x;
	cout << "Digite as 2 cordenadas de y para os dois pontos.";
	cin >> p1.y >> p2.y;
	float soma = (p1.x+p1.x)+(p1.y+p1.y);
	cout << "A soma de p1+p1 do espaço IR 2 é :" << soma << endl;
	/*soma 
	para caso do IR 2 para IR é mais simples
	p1 == (x,y);
	p1+p1
	(x,y)+(x,y);
	(x1+x2)+(y1+y2)*/
	return 0;
}