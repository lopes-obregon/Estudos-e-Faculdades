#include <iostream>
//programa que gera a sainda de '*';
using namespace std;
int main(int argc, char const *argv[])
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}