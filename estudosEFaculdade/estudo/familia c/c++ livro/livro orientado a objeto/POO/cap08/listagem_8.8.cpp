#include <iostream>
#include <iomanip>
using namespace  std;
//programa para ilustrar sobrecarga de operadores
const int MAX = 10; // tamanho dos objetos Array
class ArraySeguro//especificação de operadores
{
private:
	int array [MAX];
public:
	int& operator[](int n)//retorno por referencia
	{
		if (n < 0 or n >= MAX)
		{
			cout << "\n Indice excede o valor maximo!";
			exit (1);
		}
		return array[n];
	}
};
int main(int argc, char const *argv[])
{
	ArraySeguro array1;
	for (int i = 0; i < MAX; ++i)
		array1[i] = i*i;//inserção de elementos do lado esquerdo de '=';
	
	cout << "Elemento Valor quadrado\n";
	for (int j = 0; j < MAX; ++j)
	{
		int x = array1[j];//inserção de elementos do lado direito de  '='
		cout << j << setw(11) << x  << endl; // exibe elementos
	}
	cout << endl << endl;
	return 0;
}