#include <stdio.h>
int main(){
    printf("//A soma de 2 + 3 eh %d\n", 2+3);
    return ;
}
/**
 * main.c: In function ‘main’:
main.c:4:5: warning: ‘return’ with no value, in function returning non-void
    4 |     return ;
      |     ^~~~~~
main.c:2:5: note: declared here
    2 | int main(){
      |     ^~~~
* recebo um aviso que não tem valor a função retorna vazio
*/