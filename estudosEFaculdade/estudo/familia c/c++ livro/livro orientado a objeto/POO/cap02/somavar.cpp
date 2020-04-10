#include <iostream>
int main(int argc, char const *argv[])
{//listaguem 2.3	
	int x1,x2,soma;//define a variavel x1,x2;
	std::cout << "DIgite o valor para x1 e x2"<<"\n\n";
	std::cin >> x1;//parte onde pede para o usuario digitar o valor do x1;
	std::cin >> x2;//parte onde pede para o usuario digitar o valor do x2;
	soma = ( x1 + x2);//variavel que recebe a soma de x1 e x2;
	std::cout << "x1 + x2 = " << soma << "\n\n";//exibe na tela a soma das variaveis declaradas;

	return 0;
}