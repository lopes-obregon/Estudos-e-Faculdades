#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"
#include <unistd.h>
#include "../libary/arvoreBinaria.h"
const RAIO = 30;
typedef struct raiz{
    struct No_ab *ptRaiz;
}Raiz;
typedef struct no{
    unsigned short x,y;
    int value;
    struct no *prox;

}No;
void insertNo(No **pt, unsigned short x, unsigned short y, int value){
    No *neww = malloc(sizeof(No));
    neww->x = x;
    neww->y = y;
    neww->value = value;
    if(*pt == NULL){
        neww->prox = NULL;
        *pt = neww;

    }else{
        neww->prox = *pt;
        *pt = neww;
    }

}
//função que imprime os valores da arvore binaria de busca
void desenha_arvore(No_ab *pt, unsigned short xi, unsigned short xf, unsigned short y, No *pos){
    char str[64];
    unsigned short xm;
    if(pt == NULL)
        return;
    xm = (xi+xf)/2;
    snprintf(str, 64, "%i", pt->value);
    gfx_text(xm, y, str);
    insertNo(&(*pos), xm, y, pt->value);
    gfx_ellipse(xm+RAIO, y+RAIO, RAIO, RAIO);
    desenha_arvore(pt->esq, xi, xm, y+70, pos);
    desenha_arvore(pt->dir, xm, xf, y+70, pos);

}
//desenha a linha
void desenha_linha(No_ab *pt, No_ab *ant, No *pos){
    if(pt == NULL)
        return;

    No *aux = pos;
    while(pos != NULL){
        if(pos->prox != NULL){
            if(pt->value == pos->prox->value){
                if(pt->esq != NULL){
                    gfx_line(pos->x+(RAIO + RAIO), pos->y+RAIO, pos->prox->x, pos->prox->y+RAIO);

                }
            }
            if(pt->dir != NULL){
                No *aux2 = pos;
                pos = aux;
                while(pos != NULL){
                    if((pt->value == aux2->value) && (pt->dir->value == pos->value)){
                        gfx_line(aux2->x+(RAIO + RAIO), aux2->y+RAIO, pos->x, pos->y+RAIO);

                    }
                    pos = pos->prox;
                }
                pos = aux2;
            }
        }else{
            if(pt->dir != NULL){
                No *aux2 = pos;
                pos = aux;
                while(pos != NULL){
                    if((pt->value == aux2->value) && (pt->dir->value == pos->value)){
                        gfx_line(aux2->x+(RAIO + RAIO), aux2->y+RAIO, pos->x, pos->y+RAIO);

                    }
                    pos = pos->prox;
                }
                pos = aux2;
            }

        }
        pos = pos->prox;
    }
    pos = aux;
    desenha_linha(pt->esq, ant->esq, aux);
    desenha_linha(pt->dir, ant->dir, aux);
}
//insere na arvore
void menuInsere(Raiz *pt){
    unsigned  f, n;
    int valor=0;
    printf("Informe  a quantidade de elementos a ser inserido na arvore!\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Informe o %d valor da arvore: ", i+1);
        scanf("%d", &valor);
        //insere na arvore
        insertArvore(valor, &pt->ptRaiz, &f);
    }

}
//remove o elemento da arvore
void menuRemoveArvore(Raiz *pt){
    int valor = 0;// recebe zero para não ficar o lixo
    unsigned f;
    printf("Qual elemento deseja remover da arvore?\n");
    scanf("%d", &valor);
    removeTree(&pt->ptRaiz, valor, &f);


}
//funpção que faz a chamada para desenhar a arvore
void menuDesenhaAzrvore(Raiz *pt, No *ptLista){
    gfx_init(800, 600, "Arvore Binaria De Busca");
    gfx_set_font_size(40);
    gfx_set_color(255, 0, 0);
    desenha_arvore(pt->ptRaiz, 0, 800, 70, &ptLista);
    desenha_linha(pt->ptRaiz,  pt->ptRaiz,ptLista);
    gfx_paint();
    sleep(5);
    gfx_quit();
}
int main(){
    Raiz *pt = malloc(sizeof(Raiz));
    No *ptLista = NULL;//variavel para armazenar as posições dos elementos no plano

    int valor = 0;
    printf("\n-------manu-------\n");
    do{
        printf("0-Sair 1-Inserir arvore 2-Remover Elemento Arvore 3-Desenha arvore 4-Salvar Arvore\n");
        scanf("%d", &valor);
        if(valor == 1){
            menuInsere(pt);

        }else{
            if(valor == 2){
                menuRemoveArvore(pt);
            }else{
                if(valor == 3){
                    menuDesenhaAzrvore(pt, ptLista);

                }
            }

        }

    }while(valor != 0);


    //removeTree(&pt->cabeca, 6, &f);

    printf("\narvoreLimpa!\n");
    clearTree(&pt->ptRaiz);//limpa a arvore da memoria
    printArvorePre(pt->ptRaiz);
    return 0;
}
/**
    Busca, inserção e remoção de chaves inteiras;ok
    Visualização da árvore em modo gráfico usando a biblioteca gfx;ok
    Leitura e gravação da árvore em arquivo formato binário usando percurso em pré-ordem. A árvore não deve ser reconstruída através de operações de inserção;
    Desalocação da árvore completa.ok

*/
