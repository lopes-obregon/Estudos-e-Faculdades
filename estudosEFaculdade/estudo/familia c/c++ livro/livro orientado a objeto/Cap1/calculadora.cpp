#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	//calculadora
	float num,num2;
	int op;
	cout << "Seja bem vindo a calculadora :D"<< endl;
	cout << "infome qual operação  voçê deseja realizar:  "<<endl;
	cout <<"1-adição 2-subtração 3-multiplicação 4-divisão"<< endl;
	cin >> op;
	if (op == 1)
	{
		cout<< "informe os dois numeros da 1-adição"<< endl;
		cin >>num;
		cin >>num2;
		cout << num + num2<<endl;
	}else{
		if (op == 2)
		{
			cout<< "informe os dois numeros da 2-subtração"<< endl;
			cin >>num;
			cin >>num2;
			cout << num - num2<<endl;
		}else{
			if (op == 3)
			{
				cout<< "informe os dois numeros da 3-multiplicação"<< endl;
				cin >>num;
				cin >>num2;
				cout << num * num2<<endl;
			}else{
				if (op== 4)
				{
					cout<< "informe os dois numeros da 4-divisão"<< endl;
					cin >>num;
					cin >>num2;
					

					cout << num/num2<<endl;

				}
			}
		}
	}

	return 0;
}