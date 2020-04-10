#include <iostream>
using namespace std;
//programa para cocatenação de strings
const int MAX = 100; // tamanho dos objetos da strings
enum meuBoolean
{
	falso, verdadeiro
};
class String
{
private:
	char string[MAX];
public:
	String(){
		//construtor sem argumento
		strcpy(string,"");
	}
	String( char s[]){ // construtor com 1 argumento;
		strcpy(string, s);

	}
	void mostraString(){
		//exibe string
		cout << string;
	}
	void getString(){
		//ler string
		cin.get(string, MAX);
	}
	meuBoolean operator == (string argString)//testa se strings são iguais
	{
		return (strcmp (string, argString.string) == 0) ? verdadeiro: falso;
	}
};
int main(int argc, char const *argv[])
{
	String s1 = "sim";//cria 3 objetos string
	String s2 = "nao";
	String s3;
	cout << "\n Responda 'sim' 'nao': ";
	s3.getString();//ler string do usuario
	if (s3 == s1)//checa se sim
	{
		cout << "\n Voce digitou sim \n\n";
	}else{
		if (s3 == s2)//checa se nao
		{
			cout << "\n voce digitou nao \n\n"
		}else{
			cout << "\nResposta diferente das esperadas ('sim' ou 'nao')! \n\n";
		}
	return 0;
}