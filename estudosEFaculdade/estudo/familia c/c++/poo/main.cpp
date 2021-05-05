#include <iostream>
#include <string>
#include <cstdlib>
#include "Carro.h"
using namespace std;
//classe
// static atruibuto da classe alterar ela muda o atruibuto da classe
int main()
{
    //construtor
    Carro c2("ferrari", 2020);
    //meuObjeto
    Carro c1;
    c1.setMarca("Fiat");
    c1.setAno(1640);
    c2.pneus = 2;
    cout << c1.pneus << endl;
    cout << c1.getAno() << endl;
    cout << c2.getMarca() <<endl;
    cout << c2.pneus <<endl;
    return 0;
}
