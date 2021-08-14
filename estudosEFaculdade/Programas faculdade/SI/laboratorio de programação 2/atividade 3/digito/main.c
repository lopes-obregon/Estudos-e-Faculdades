#include <stdio.h>
#include <stdlib.h>
//protótipos
int digitos(int n, int count);
int main(int argc, char const *argv[])
{
    printf("%d\n", digitos(100, 1));
    return 0;
}
int digitos(int n, int count){
    
    if(count <= 0){
        count = 1;
    }else if(n > 9){
        //elimina um digito
        n = n/10;
        return digitos(n, count + 1);
    }else{
        return count;
    }
}