#include <stdio.h>
#include <stdlib.h>
/*prototipo da função*/
int fib(n);
/*main*/
int main()
{
   fib(10);
    return 0;
}
int fib(n){
    if(n <= 1){
        printf("%d\n", n);
    }else{
        printf("%d\n", fib(n-1) + fib(n-2));
    }

}
