#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"
#include <unistd.h>
#include "../libary/arvoreBinaria.h"
const RAIO = 20;
typedef struct raiz{
    struct No_ab *ptRaiz;
}Raiz;
typedef struct ponteiro{
    struct arqNo *cabeca;
}Ponteiro;
//função que imprime os valores da arvore binaria de busca
void desenha_arvore(No_ab *pt, unsigned short xi, unsigned short xf, unsigned short y){
    char str[64];
    //variavel aux para auxiliar no dezenho da linha
    unsigned short xm, aux;

    if(pt != NULL){
        xm = (xi+xf)/2;
        snprintf(str, 64, "%i", pt->value);
        gfx_set_color(220, 20, 60);
        //parte que desenha linha
        if(pt->dir != NULL && pt->esq != NULL){
            aux = (xm + xf)/2;
            gfx_line(xm, y, aux, y+70);
        }
        if(pt->esq != NULL){
            aux = (xm + xi)/2;
            gfx_line(xm, y, aux, y+70);
        }else{
            if(pt->dir != NULL){
                aux = (xm + xf)/2;
                gfx_line(xm, y, aux, y+70);
            }
        }
        //insertNo(&(*pos), xm, y, pt->value);
        gfx_set_color(173, 255, 47);
        gfx_filled_ellipse(xm, y+9, RAIO, RAIO);
        gfx_set_color(143, 188, 143);
        gfx_ellipse(xm, y+9, RAIO, RAIO);
        gfx_set_color(0, 100, 0);
        gfx_text(xm - strlen(str)*4, y- strlen(str)*2, str);
        desenha_arvore(pt->esq, xi, xm, y+70);
        desenha_arvore(pt->dir, xm, xf, y+70);
    }


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
void menuDesenhaAzrvore(Raiz *pt){
    gfx_init(1000, 800, "Arvore Binaria De Busca");
    gfx_set_font_size(20);
    desenha_arvore(pt->ptRaiz, 0, 1000, 70);
    gfx_paint();
}
/*
{15,1,0}{4,1,0}...


*/
//gravação no arquivo binario
void menuArquivoBinario(Raiz *pt){
    FILE *fp;//declaração do ponteiro do tipo arquivo
    char buffer[64];
    printf("Informe o nome do Arquivo para salvar: ");
    scanf("%s", buffer);
    addBin(buffer);
    fp = fopen(buffer, "rw");
    if(fp == NULL){
        printf("Erro na abertura do arquivo\n");

    }else{
        Ponteiro *ptCabeca = NULL;
        printArvorePre(pt,&ptCabeca->cabeca, fp);
        fclose(fp);//fecha o arquivo binario  em modo escrita.
    }



}
//menu que lê do arquivo
void menuArquivoBinarioLeitura(Raiz *pt){
    FILE *fp;
    char buffer[64];
   // unsigned short filhoEsquerdo, filhoDireito;
    //filhoEsquerdo = filhoDireito = 0;
    printf("Informe o nome do Arquivo para ler: ");
    scanf("%s", buffer);
    addBin(buffer);
    fp = fopen(buffer, "rb");
    if(fp == NULL){
        printf("Erro na abertura do arquivo\n");
    }else{
        leituraPreOrdemArquivo(&pt->ptRaiz, &pt->ptRaiz, fp);
        fclose(fp);
    }
}
//limpa a lista
//principal
int main(){
    Raiz *pt = malloc(sizeof(Raiz));
    FILE *arq;
    char buffer[100];
    char str[] = "testando";
    int valor = 0;
    do{
        printf("\n-------manu-------\n");
        printf("0-Sair 1-Inserir arvore\n 2-Remover Elemento Arvore 3-Desenha arvore\n 4-Salvar Arvore  5-Ler Do Arquivo \n");
        scanf("%d", &valor);
        if(valor == 1){
            menuInsere(pt);

        }else{
            if(valor == 2){
                menuRemoveArvore(pt);
            }else{
                if(valor == 3){
                    menuDesenhaAzrvore(pt);

                }else{
                    if(valor == 4){
                        menuArquivoBinario(pt);
                    }else{
                        if(valor == 5){
                            clearTree(&pt->ptRaiz);//limpa a arvore da memoria
                            pt->ptRaiz = NULL;//arvore vazia então deve apontar para null
                            menuArquivoBinarioLeitura(pt);

                        }
                    }
                }
            }

        }

    }while(valor != 0);


    //removeTree(&pt->cabeca, 6, &f);

    printf("\narvoreLimpa!\n");
    gfx_quit();
    clearTree(&pt->ptRaiz);//limpa a arvore da memoria
    return 0;
}
/**
    Busca, inserção e remoção de chaves inteiras;ok
    Visualização da árvore em modo gráfico usando a biblioteca gfx;ok
    Leitura e gravação(ok) da árvore em arquivo formato binário usando percurso em pré-ordem. A árvore não deve ser reconstruída através de operações de inserção;
    Desalocação da árvore completa.ok

*/
