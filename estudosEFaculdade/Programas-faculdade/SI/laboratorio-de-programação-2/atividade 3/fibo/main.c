#include <stdio.h>
#include <stdlib.h>
int gFib(int f0, int f1, int n);
int main(int argc, char const *argv[])
{
    gFib(0, 1 , 3);
    return 0;
}

int gFib(int f0, int f1, int n){
    if((n <= f0)){
        return f0;
    }else if(f1 == n){
        return f1;
     
    }else{
        
        return gFib(f0, f1, n-1) +    gFib(f0, f1, n-2);
    }
}