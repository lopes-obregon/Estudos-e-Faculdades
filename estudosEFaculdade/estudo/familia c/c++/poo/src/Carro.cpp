#include <string>
#include "Carro.h"
#include <iostream>
using namespace std;
void Carro::setMarca(string marca){
    this->marca = marca;
}
string Carro::getMarca(){
    return marca;
}
void Carro::setAno(unsigned int ano){
    if(ano > 1990){
        this->ano = ano;
    }else{
        this->ano = 1990;
    }
}
unsigned int Carro::getAno(){
    return ano;
}
//construtor
Carro::Carro(){
    this->marca = "Fiat";
}
Carro::Carro(string marca, unsigned int ano){
    this->marca = marca;
    this->ano = ano;
}

Carro::~Carro(){
    cout << "Carro destruido!"<<endl;
}
unsigned int Carro::pneus  = 4;
