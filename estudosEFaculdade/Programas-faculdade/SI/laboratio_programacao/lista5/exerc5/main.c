#include <stdio.h>
/*Monstra o numero de tres sumeros difentes em ordem crescente*/

int main(){
    int a,b,c;
    printf("Informe os numeros: ");
    scanf("%d %d %d",&a, &b, &c);
    if (a < b && b < c)
    {
      printf("A ordem crescente: %d %d %d\n", a, b, c);
    }
  else if (a < c && c < b)
    {
      printf("A ordem crescente: %d %d %d\n", a, c, b);
    }
  else if (b < a && a < c)
    {
      printf("A ordem crescente: %d %d %d\n", b, a, c);
    }
  else if (b < c && c < a) 
    {
      printf("A ordem crescente: %d %d %d\n", b, c, a);
    }
  else if (c < a && a < b) 
    {
      printf("A ordem crescente: %d %d %d\n", c, a, b);
    }
  else /* b < c && c < a */
    {
      printf("A ordem crescente: %d %d %d\n", c, b, a);
    }
    return 0;
}