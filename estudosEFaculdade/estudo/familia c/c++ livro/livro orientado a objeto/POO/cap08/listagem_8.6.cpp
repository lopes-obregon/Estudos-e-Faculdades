#include <iostream>
using namespace std;
//programa que ilustra a concatenação de strings
const int Max = 100; //tamanho dos objetos string
class String // especificação da classe string
{
private:
	char string[Max];
public:
	String(){//construtor sem argumento
		strcpy (string,"");
	}
	String( char s[]){//construtor com 1 argumento
		strcpy(string, s);
	}
	void mostraString(){
		//exibe string
		cout << string;
	}
	String operator + (String argString)//concatena strings
	{
		String tmp;
		if (strlen(string) + strlen(argString.string) < Max)
		{
			strcpy(tmp.string, string); // copia string para tmp
			strcat(tmp.string, argString.string);//concatena argumento com string;
		}
		else{
			cout << "\nOcorreu overflow de string";
			exit(1);
		}
		return tmp; // retorna string tmp
	}
};
int main(int argc, char const *argv[])
{
	String s1 = "Antonio Mendes ";//cria objeto string
	String s2 = "da Silva Filho";
	String s3;
	cout << "\nString s1 = "; s1.mostraString();
	cout << "\nString s2 = "; s2.mostraString();
	cout << "\nString s3 = ";
	s3 = s1 + s2; //  concatena a string s2 com a s1 e atribui a s3
	s3.mostraString();//exibe string s3
	cout << endl << endl;
	return 0;
}