#include <iostream>
#include <limits>
using namespace std;
//programa que checa os limes dos tipos de dados;
//linstaguem 2.11	
int main(int argc, char const *argv[])
{
	cout << "Limite inferior de <char>: " << (int)numeric_limits<char>::min() << endl;
	cout << "Limite superior de <char>: " << (int)numeric_limits<char>::max() << endl;
	cout << "numeros de bytes de char: " << sizeof(char) << endl;
	cout << "Limite inferior de <short>: " << numeric_limits<short>::min() << endl;
	cout << "Limite superior de <short>: " << numeric_limits<short>::max() << endl;
	cout << "tamanho em bytes de short: " << sizeof(short) << endl;
	cout << "Limite inferior de <int>: " << numeric_limits<int>::min() << endl;
	cout << "Limite superior de <int>: " << numeric_limits<int>::max() << endl;
	cout << "tamanho em bytes de int : " << sizeof(int) << endl;
	cout << "Limite inferior de <long>: " << numeric_limits<long>::min() << endl;
	cout << "Limite superior de <long>: " << numeric_limits<long>::max() << endl;
	cout << "tamanho em bytes de long : " << sizeof(long) << endl;
	cout << "Limite inferior de <float>: " << numeric_limits<float>::min() << endl;
	cout << "Limite superior de <float>: " << numeric_limits<float>::max() << endl;
	cout << "tamanho em bytes de float : " << sizeof(float) << endl;
	cout << "Limite inferior de <double>: " << numeric_limits<double>::min() << endl;
	cout << "Limite superior de <double>: " << numeric_limits<double>::max() << endl;
	cout << "tamanho em bytes de double : " << sizeof(double) << endl;
	return 0;
}