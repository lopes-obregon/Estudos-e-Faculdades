
int main(){
    printf("//A soma de 2 + 3 eh %d\n", 2+3);
    return 0;
}
/**
 * main.c: In function ‘main’:
main.c:3:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    3 |     printf("//A soma de 2 + 3 eh %d\n", 2+3);
      |     ^~~~~~
main.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’
main.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
  +++ |+#include <stdio.h>
    1 | 
* declaracao implicita da função printf pede para adicionar a biblioteca stdio.h para declarar a função printf
*/