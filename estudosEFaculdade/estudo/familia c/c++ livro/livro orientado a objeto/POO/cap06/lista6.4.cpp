#include <iostream>
using namespace std;
//estrututra de dados
//protótipos das funões
//variavel global
//classes
class Conta
{
private:
	double saldo;
public:
	Conta(){saldo = 0;}//construtor
	void creditar (double quantia){
		saldo = saldo + quantia;
	}//função credito
	double getSaldo(){return saldo;}//função getSaldo
};
//função principal
int main(int argc, char const *argv[])
{
	double quantiaDeposito;
	Conta c1, c2;//cria dois objetos Conta;
	cout << "\nSaldo da C/C 1 = " << c1.getSaldo();//exibe saldo inicial;
	cout << "\n Saldo da C/C 2 = " << c2.getSaldo();
	c1.creditar(777.99);//credita 777.99na c/c 1;
	c2.creditar(255.55);//credita 777.99na c/c 1;
	cout << "\n\n Saldo da C/C 1 apos credito = " << c1.getSaldo();//exibe saldo
	cout << "\n\n Saldo da C/C 2 apos credito = " << c2.getSaldo();//exibe saldo
	cout << "\n\n Digite quantia a ser creditada na C/C 2: ";
	cin >> quantiaDeposito;//ler quantia de deposito;
	cout << "\n Saldo da C/C 2 apos credito = " << c2.getSaldo() << endl << endl;

	return 0;
}