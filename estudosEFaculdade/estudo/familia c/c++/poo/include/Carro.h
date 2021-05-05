#ifndef CARRO_H
#define CARRO_H

#include <string>
using namespace std;
class Carro
{
   public:
   static unsigned int pneus;
   Carro();
   Carro(string marca, unsigned int ano);
   ~Carro();
    void setMarca(string marca);
    string getMarca();
    void setAno(unsigned int ano);
    unsigned int getAno();
   private:
    string marca;
    unsigned int ano;

};

#endif // CARRO_H
