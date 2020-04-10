#include <iostream>
//programa que solicita ao usuario a entrada do dados de temperatura  em fahrenheit
	using namespace std;
int main(int argc, char const *argv[])
{
	float reais,dolar;
	do{
		cout <<"Digite a quantidade de dolar apra converter (cotação em R$ 3,3075)(-1 para sair)$:" << endl;
		cin >> dolar;
		if (dolar == -1)
		{
			return 0;
		}
		reais = dolar *3.3075;
		cout << "valor convertido R$: " << reais << endl; 
	}while(dolar != -1);
	return 0;
}