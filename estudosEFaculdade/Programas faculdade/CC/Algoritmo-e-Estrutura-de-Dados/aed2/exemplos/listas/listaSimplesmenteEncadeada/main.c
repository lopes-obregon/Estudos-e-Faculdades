#include <stdio.h>
#include <stdlib.h>
/**
 * 1) Desalocação da lista iterativamente;
 * 2) Desalocação da lista recursivamente;ok
 * 3) Inserção de nó no final da lista;ok
 * 4) Inserção de nó na i-ésima posição da lista (i é um parâmetro);
 * 5) Busca de um nó por um valor procurado;ok
 * 8) Remoção de um nó com determinado valor x;ok
*/
/***/
struct list{
    struct no *first;
};

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
 * função end_rec(no ptl)
 *  se(ptl != lambda) então
 *      end_rec(ptl^.prox)
 *   senão
 *      ptl := lambda
*/
//função que desaloca recursivamente
void end_rec(struct s_no **ptl){
    if(*ptl != NULL){
        end_rec(&(*ptl)->prox);
    }else{
        free(*ptl);
        *ptl = NULL;
    }
}
/**
 * insert value in nó
 * cl main.c in windows
*/
//feito de acompanhamento em aula
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
/**
 * função insere_no_final()
 *  no atual := Lista^.primeiro;
 *  novo^.prox := lambda;
 *  enquanto atual^.prox != lambda
 *      atual := atual^.prox;
 *  fimEnquanto
 * atual^.prox := novo;
*/
//insere no final da lista
void insert_end(struct s_no **ptl, struct list *List){
    struct s_no* atual = List->first;
    struct s_no *novo = malloc(sizeof(struct s_no));
    novo->prox = NULL;
    while (atual->prox !=NULL)
    {
        /* code */
        //percorre até no final
        atual = atual->prox;
    }
    //coloca o novo nó no final do atual;
    atual->prox = novo;

    
}
/**
 * no procura()
 *  se(ptl^.valor == valor) então
 *          retorne ptl
 *  se(ptl^.prox !=lambda) então
 *          retorne procurar(ptl^.prox, valor);
*/
//busca da lista por um valor procurado
struct s_no* search(struct s_no *ptl, int value){
    if(ptl->valor == value){
        return ptl;    
    }
    if(ptl->prox !=NULL){
        return search(ptl->prox, value);
    }
    return NULL;
}
/**
 * seguindo o algoritmo do livro 2.17 remoção do nó
 * se pont != lambda então
 * ant^.prox
 * valor-recuperado := pont^.info
 * desocupar(pont)
 * senão  "nó não encontrado na tabela"
*/
//remove 
int remove(struct s_no *ptl, struct s_no *back){
    int valueBack = 0 ;
    if(ptl != NULL){
        back->prox = ptl->prox;
        valueBack = ptl->valor;
        end_rec(ptl);
    }else{
        printf("Nó não encontrado");
    }
}
//main code
int main(){
    struct s_no *ptlista = NULL;
    insert(&ptlista, 20);
    insert(&ptlista, 30);
    insert(&ptlista, 80);
    insert(&ptlista, 190);
    print_rec(ptlista);
    end_rec(&ptlista);
    printf("\n");
    print_rec(ptlista);
    printf("\n");
    return 0;
}