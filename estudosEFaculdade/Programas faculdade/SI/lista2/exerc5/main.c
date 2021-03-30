#include <stdio.h>
int main(){
    printf("//A soma de 2 + 3 eh %d\n", 2+3)
    return 0;
}
/**
 * main.c: In function ‘main’:
main.c:3:45: error: expected ‘;’ before ‘return’
    3 |     printf("//A soma de 2 + 3 eh %d\n", 2+3)
      |                                             ^
      |                                             ;
    4 |     return 0;
      |     ~~~~~~   
* resultado error esperado um ; antes do return
*/