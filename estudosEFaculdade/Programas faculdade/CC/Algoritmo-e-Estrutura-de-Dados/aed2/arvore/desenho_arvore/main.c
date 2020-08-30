#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"
#include <unistd.h>
#include "../libary/arvoreBinaria.h"
const RAIO = 30;
typedef struct raiz{
    struct No_ab *cabeca;
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
int main(){
    Raiz *pt = malloc(sizeof(Raiz));
    No *ptLista = NULL;
    unsigned  f;
    insertArvore(15, &pt->cabeca, &f);
    insertArvore(6, &pt->cabeca, &f);
    insertArvore(100, &pt->cabeca, &f);
    printArvorePre(pt->cabeca);
    gfx_init(800, 600, "Arvore Binaria De Busca");
    gfx_set_font_size(40);
    gfx_set_color(255, 0, 0);
    desenha_arvore(pt->cabeca, 0, 800, 70, &ptLista);
    desenha_linha(pt->cabeca,  pt->cabeca,ptLista);
    gfx_paint();
    sleep(5);
    gfx_quit();
    return 0;
}
