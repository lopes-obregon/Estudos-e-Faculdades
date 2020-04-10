#include <iostream>
//programa que solicita ao usuario a entrada do dados de temperatura  em fahrenheit
	using namespace std;
int main(int argc, char const *argv[])
{
	int ctemp,ftemp;
	cout <<"Digite a temperatura em fahrenheit: " << endl;
	cin >> ftemp;
	ctemp = (ftemp -32)*5/9;
	cout << "A temperatura em celsius é : " << ctemp << endl; 
	return 0;
}