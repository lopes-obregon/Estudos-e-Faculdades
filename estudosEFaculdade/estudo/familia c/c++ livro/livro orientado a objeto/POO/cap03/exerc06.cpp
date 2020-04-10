#include <iostream>
using namespace std;
//programa que faz a conversão de fahrenheit em celsius;
int main(int argc, char const *argv[])
{
	int ctemp,ftemp;//ctemp = (ftemp-32)*5/9;
	do{
		cout << "Digite a Temperatura em fahrenheit para converter em celsius (-99999 para sair):" << endl;
		cin >> ftemp;
		if (ftemp == -99999)
		{
			return 0;
		}
		ctemp = (ftemp -32)*5/9;
		cout << "A Temperatura em celsius é :" << ctemp << endl << endl;
	}while (ftemp != -99999);
	return 0;
}