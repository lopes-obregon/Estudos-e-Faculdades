#include <stdio.h>
#include <stdlib.h>
float potencia(float x, int n);
int main(int argc, char const *argv[])
{
   printf("Potencia %f\n", potencia(4, 4));
    return 0;
}

float potencia(float x, int n){
    if(n == 0){
        return 1;
    }else if ( n == 1){
        return x;
    }else{
        return x * potencia(x, n-1);
    }
    
}