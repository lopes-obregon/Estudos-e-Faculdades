#include <iostream>
//programa que solicita ao usuario a entrada do dados de temperatura  em fahrenheit
	using namespace std;
int main(int argc, char const *argv[])
{
	float reais,dolar;
	cout <<"Digite a quantidade de dolar apra converter (cotação em R$ 3,3075)$:" << endl;
	cin >> dolar;
	reais = dolar *3.3075;
	cout << "valor convertido R$: " << reais << endl; 
	return 0;
}