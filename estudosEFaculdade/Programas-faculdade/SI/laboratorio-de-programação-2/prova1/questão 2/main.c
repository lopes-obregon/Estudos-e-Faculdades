#include <stdio.h>


int g(int n){
    if(n == 0){
        return 1;
    }else{
        return 2*g(n-1);
    }
}
int main(int argc, char const *argv[])
{
    printf("%d\n", g(8));
    return 0;
}

