#include <iostream>
using namespace std;
//programa que faz deposito(ok) saque (ok) e consulta de saldo.
//estrutra de dados
//variaveis globais
//classes
class ContaCorrente
{
private:
	float saldo;//variavel saldo armazena os valores de positados
	float saque;//variavel para saque;
public:
	ContaCorrente(){saldo = 0;}//construtor
	float getDeposito(){
		cout << "Digite o valor para deposito : ";
		cin >> saldo;
		return saldo;//deve retornar para função principal
	}
	float Saque (){
		cout << "Quanto deseja sacar : ?"; //variavel para realizar o calculo para saque;
		cin >> saque;
		saldo -= saque;//saldo = saldo - saque;
	}
	float getSaldo(){
		return saldo;
	}
};
//prototipos de dados
//função principal
int main(int argc, char const *argv[])
{
	ContaCorrente c1; // objeto 1 
	cout << "Saldo atual da conta = " << c1.getSaldo() << endl;//exibe o saldo atual
	c1.getDeposito();
	c1.Saque();
	cout << "\nSaldo atual é de R$:" << c1.getSaldo() << endl;
	return 0;
}