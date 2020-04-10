#include <iostream>
using namespace std;
//estrutra de dados
struct soma
{
	float num1;
	float num2;
};
//funçao principal
//programa que faz o calculo dos numeros reais e imaginarios;
int main(int argc, char const *argv[])
{
	soma cal;
	int op;
	cout << "Entre com os números reais ou imaginarios para realizar a soma de ambos os números: "<< endl;
	cin >> cal.num1 >> cal.num2;
	cout << "1- para somar real ou 2- para somar imaginaria";
	cin >> op;
	if (op == 1)//soma real
	{
		float resultado;
		cout << "resultado da soma é: " << (resultado = (cal.num1 + cal.num2)) << endl;
	}else{
		if (op == 2)//soma imaginaria;
		{
			float resultado;
			cout << "resultado da soma é: " << (resultado = (cal.num1 + cal.num2)) << endl;
		}
	}
	return 0;
}