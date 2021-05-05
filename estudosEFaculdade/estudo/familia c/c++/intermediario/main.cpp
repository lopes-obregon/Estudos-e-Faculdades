// programa de estudo de c++ avançado
#include <iostream>
#include <string.h>
using namespace std;
/*class Pessoa{
    private:
        string nome;
        unsigned short int idade;
        int *parentes;
        //construtor
        public:
            Pessoa(string nome, unsigned short int idade){
                this->nome = nome;
                this->idade = idade;
                parentes = new int[100];
            }
            string getNome(){
                return this->nome;
            }
            unsigned short int getIdade(){
                return this->idade;
            }
            //destrutor
            ~Pessoa(){
                delete[] parentes;
            }
};*/
class Estudante{
    public:
        char  *nome;
        unsigned short int idade;
        //construtor
        Estudante(const char  *nome){
            this->idade = 6;
            unsigned tam = strlen(nome) +1;
            this->nome = new char[tam];
            strcpy(this->nome, nome);
        }
        //construtor de copias
        Estudante(const Estudante& e){
            int tam = strlen(e.nome) +1;
            this->nome = new char [tam];
        }
};
int main()
{
    Estudante e("Carlos");
    /*Pessoa p("Jão",  30);
    cout <<p.getNome() << endl;
    cout <<p.getIdade() << endl;*/
    return 0;
}
