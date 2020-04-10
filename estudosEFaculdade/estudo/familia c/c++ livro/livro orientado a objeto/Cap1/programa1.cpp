#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char const *argv[])
{
	//cin -> para ler o teclado
	// >> extrair os dados; 
	//obj cin;
	//obj cout;//<< operador de inserção;
	//hex numeros hexdecima
	//estabelecer o tamanho de um campo; setw()//biblioteca iomanip;
	cout <<"estudando a entrada e saida de dados."<< endl;
	/*cout << setw(10) << 1 << endl;
	cout << setw(10) << 2 << endl;
	cout << setw(10) << 3 << endl;
	cout << setw(10) << 4 << endl;
	*/
	//>>( operador de extração)/ leitura de teclado;
	cout << "enter a number :  " << endl;
	int num1 = 0;
	cin >> num1;
	cout <<"Tell me another number: "<< endl;
	int num2 =0;
	cin >> num2;
	cout << "the numbers entered are: "	<<num1
									<<" and "
									<< num2 
								 	<< endl;
	cout << "the soma dos number is:  "<< num1 + num2 << endl;
	return 0;
}