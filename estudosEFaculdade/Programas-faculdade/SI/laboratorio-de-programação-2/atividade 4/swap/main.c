#include <stdio.h>
#include <stdlib.h>
//questao 3 e quatro
void swap(int *p1, int *p2);
int main()
{

    int a = 2;
    int b = 5;
    int c = 7;
    //a vai para b
    swap(&a, &b);
    //b para o c
    swap(&b, &c);
    //c para a
    swap(&c, &a);
    printf("%d %d %d\n", a, b, c);
    return 0;
}

void swap(int *p1, int *p2){
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}
