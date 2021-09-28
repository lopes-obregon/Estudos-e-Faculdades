//programa para calcular em bytes a lista
#include<stdio.h>
typedef struct 
{
    int key;
    struct node_t *next;
    
}node_t;

int main(int argc, char const *argv[])
{
    printf("%ld\n", sizeof(node_t));
}
