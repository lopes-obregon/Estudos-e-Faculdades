#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int e;
	for (int i = 0; i < 4; ++i)
	{
		e = 1;
		while(e <= i){
			cout << "*";
			e += 1;
		}
		cout << endl;
	}
	int maior = 4;
	for (int i = 0; i < 4; ++i)
	{
		e = 1;
		while ((e <=(maior - i))){
			cout << "*";
			e += 1;
		}
		cout << endl;
	}
	return 0;
}