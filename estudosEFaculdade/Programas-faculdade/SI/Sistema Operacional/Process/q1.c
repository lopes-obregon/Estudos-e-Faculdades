#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int i;
    for(i = 0;  i < 4; i++){
        fork();

    }
    scanf("%d", &i);
    return 0;
}
