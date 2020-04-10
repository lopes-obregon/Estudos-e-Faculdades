#include <iostream>
#include <iomanip>
//programa que gera a sainda de '*';
using namespace std;
int main(int argc, char const *argv[])
{
	int e, max,aux;
	max = 6;
	aux = max;
	for (int i = 0; i <max; ++i)
	{
		e=1;
		while(e <= i){//6 -2
			cout << "*"; //<< "\t";
			e +=1;
		}
		cout << "\t";
		while(e <= max){
			cout << "*";
			e += 1;
		}
		cout << endl;
	}
	return 0;
}