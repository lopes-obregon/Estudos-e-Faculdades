#include <iostream>
using namespace std;
//estrutura de dados
//variaveis globais
//classes
class Contador//especificação do contador
{
private:
	int contador;//unsingned não é necessario o copilador do linux nao reconhece;
public:
	Contador(){contador = 0; } // construtor
	int getContador(){return contador ;} //retorna contador
	void operator ++(){ ++contador;}//pre-incremento(essa operação diz ao copilador para dar o incremento todoa vez que "++" é chamado)
};
//prototipos de funções
//função principal
int main(int argc, char const *argv[])
{
	Contador c1, c2; //declaração de 2 objetos contador
	cout << "\nContador  antes 1 do incremento = " << c1.getContador();
	cout << "\n Contador antes 2 do incremento = " << c2.getContador();
	++c1; // incremento c1 uma vez;
	++c2; // incremento de 3 vezes em c2;
	++c2;
	++c2;
	cout << "\n\n Contador 1 depois do incremento = " << c1.getContador();
	cout << "\n Contador 2 depois do incremento = " << c2.getContador();
	cout << endl << endl;
	return 0;
}