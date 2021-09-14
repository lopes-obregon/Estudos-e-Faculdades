#include<stdio.h>
typedef struct  {
    float x, y;
}ponto2d_t;
typedef struct {
    ponto2d_t inferior_esquerdo;
    ponto2d_t superior_direito;
}retangulo_t;
//protótipos
float calculaAreaDoRetangulo(retangulo_t retangulo);
//main
int main(int argc, char const *argv[])
{
    retangulo_t retangulo;
    retangulo.superior_direito.x = 9;
    retangulo.superior_direito.y = 6;
    retangulo.inferior_esquerdo.x = 1;
    retangulo.inferior_esquerdo.y = 1;
    printf("Area do retangulo eh:%f\n", calculaAreaDoRetangulo(retangulo));
    return 0;
}

//calula a area do retangulo
float calculaAreaDoRetangulo(retangulo_t retangulo){
    float altura, base;
    altura = retangulo.superior_direito.y - retangulo.inferior_esquerdo.y;
    base = retangulo.superior_direito.x - retangulo.inferior_esquerdo.x;
    return base * altura;
}
