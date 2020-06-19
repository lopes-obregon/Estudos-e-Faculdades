#include "stdio.h"
struct s_no{

    int valor;
    struct s_no *prox;
};
//print lista
void print(struct s_no *ptl){
    struct s_no* pt = ptl;
    printf("\n Lista: inicio->");
    while (pt != NULL)
    {
        /* code */
        printf("%i ->", pt->valor);
        pt = pt->prox;
    }
    
}
/**
 * impresão recursiva
*/
void print_rec(struct s_no *ptl){
    if(ptl != NULL){
        print_rec(ptl->prox);
        printf("[%i] ->", ptl->valor);

    }
}
/**
 * insert value in nó
 * cl main.c in windows
*/
void insert(struct s_no **ptl, int value){
   struct s_no *pt = malloc(sizeof(struct s_no));
   if(pt == NULL){
       return;
   }
   //recebe o valor de value
   pt->valor = value;
   pt->prox = *ptl;
   *ptl = pt;
    
}
//main code
int main(){
    struct s_no *ptlista = NULL;
    insert(&ptlista, 20);
    insert(&ptlista, 30);
    insert(&ptlista, 80);
    insert(&ptlista, 190);
    print_rec(ptlista);
    return 0;
}