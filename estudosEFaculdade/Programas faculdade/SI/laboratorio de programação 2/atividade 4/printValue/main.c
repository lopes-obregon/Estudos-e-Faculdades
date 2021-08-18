#include <stdio.h>
#include <stdlib.h>
//questao 2
int main()
{
    int x, y;
    int *p, *q;
    x = 2;
    y = 8;
    p = &x;
    q = &y;
    //imprimir endereco e valor de x
    printf("&x:%lu  x:%d\n", &x, x);
    //imprimir endereco e valor de p
    printf("p:%lu  *p:%d\n", p, *p);
    //imprimir endereco e valor de y
    printf("&x:%lu  x:%d\n", &y, y);
    //imprimir endereco de p
    printf("&p:%lu", &p);
    return 0;
}
