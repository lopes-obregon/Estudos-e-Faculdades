#include <iostream>
using namespace std;
// Estudante getNome ,getNota, mostraNota, calculaMedia;
//estrututra de dados
//protótipos das funões
//variavel global
//classes
class Estudate
{
	char nome;
	float n1,n2,n3,n4;
public:
	void getNome(){
		cout << "Digite o nome do aluno :";
		cin >> nome;
	}
	float getNota(){
		cout << "DIgite as notas do aluno: ";
		cin >> n1;
		cin >> n2;
		cin >>  n3;
		cin >> n4;

	}
	float mostraNota(){
		return n1;
	}
	float mostraNota2(){
		return n2;
	}
	float mostraNota3(){
		return n3;
	}
	float mostraNota4(){
		return n4;
	}
	float calculaMedia(){
		float media;
		media = (n1 + n2 + n3 + n4)/4;
		return media;
	}
	
};
//função principal
int main(int argc, char const *argv[])
{
	Estudate e1;
	e1.getNome();
	e1.getNota();
	cout << "As notas digitadas são: " << e1.mostraNota() <<  "\t" << e1.mostraNota2()  << "\t" << e1.mostraNota3() << "\t" << e1.mostraNota4() << endl;
	cout << "A media de notas são: " << e1.calculaMedia() << endl;
	
	return 0;
}