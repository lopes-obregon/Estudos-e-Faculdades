#include <iostream>
using namespace std;
//estruturas de dados
//prototipos de funções
//classes
//variaveis globais
//funções principais
int main(int argc, char const *argv[])
{
	/*
		dever ir gerando e armazenado conforme for digitado as infomações
	*/
	int n = 0;//contador e tamanho do array;
	double media;
	double valorNota;
	do
	{	
		cout << "Digite a quantia de nota para acresentar (ou -1 para cancelar)" << n << endl;
		double nota[n];
		cin >> n;
		if (n != -1)
		{
			for (int i = 0; i < n; ++i){
				cout << "Digite as notas para salvar no sistema\n";
				cin >> nota[i];//estou armazenando valor na posição i
			}
			//media é a somatoria das i notas divido por n
			for (int i = 0; i < n; ++i){
	 			valorNota = nota[i];
	 			media += valorNota;// 6 + 3
	 		} 
	 
			 cout << "media total: " << media/n << endl;
		}
	} while (n != -1);
	
	return 0;
}