#include <stdio.h>
#include <stdlib.h>
#include "gfx.h"
#include <unistd.h>
#include "../libary/arvoreBinaria.h"
#include "../libary/arvoreAvl.h"
const RAIO = 20;
typedef struct raiz{
    struct Avl *ptRaiz;
}Raiz;
typedef struct ponteiro{
    struct arqNo *cabeca;
}Ponteiro;
//função que imprime os valores da arvore binaria de busca
void desenha_arvore(Avl *pt, unsigned short xi, unsigned short xf, unsigned short y){
    char str[64];
    //variavel aux para auxiliar no dezenho da linha
    unsigned short xm, aux;

    if(pt != NULL){
        xm = (xi+xf)/2;
        snprintf(str, 64, "%i|%i", pt->chave, pt->bal);
        gfx_set_color(220, 20, 60);
        //parte que desenha linha
        if(pt->esq != NULL){
            aux = (xm + xi)/2;
            gfx_line(xm, y, aux, y+70);
        }
        if(pt->dir != NULL){
            aux = (xm + xf)/2;
            gfx_line(xm, y, aux, y+70);
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
    unsigned  n;
    FILE *fp;
    //unsigned short f;
    bool f;
    int valor=0;
    //printf("Informe  a quantidade de elementos a ser inserido na arvore!\n");
    //scanf("%d", &n);
    //leitura do usuario
    /*for(int i = 0; i < n; i++){
        printf("Informe o %d valor da arvore: ", i+1);
        scanf("%d", &valor);
        //insere na arvore
        //insertArvore(valor, &pt->ptRaiz, &f);
        insertAvl(valor, &pt->ptRaiz, &f);
    }*/
    //leitura do arquivo
    fp = fopen("dados", "r");
    if(fp == NULL){
        printf("Erro na abertura do arquivo");
    }else{
        while(!feof(fp)){
            n = valor;
            fscanf(fp, "%d", &valor);
            if(n != valor){
                insertAvl(valor, &pt->ptRaiz, &f);
            }
        }

    }
    printf("Para visualizar a alteração feita solicite a opção 3\n");

}
//remove o elemento da arvore
void menuRemoveArvore(Raiz *pt){
    int valor = 0;// recebe zero para não ficar o lixo
    bool f;
    printf("Qual elemento deseja remover da arvore?\n");
    scanf("%d", &valor);
    //removeTree(&pt->ptRaiz, valor, &f);
    removeAvl(valor, &pt->ptRaiz, &pt->ptRaiz, &f);
    printf("Para visualizar a alteração feita solicite a opção 3\n");


}
//funpção que faz a chamada para desenhar a arvore
void menuDesenhaAzrvore(Raiz *pt){
    gfx_init(800, 600, "Arvore Binaria De Busca");
    gfx_set_font_size(20);
    desenha_arvore(pt->ptRaiz, 0, 800, 70);
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
    fp = fopen(buffer, "wb");
    if(fp == NULL){
        printf("Erro na abertura do arquivo\n");

    }else{
        Ponteiro *ptCabeca = NULL;
        printArvorePre(pt,&ptCabeca->cabeca, fp);
        fclose(fp);//fecha o arquivo binario  em modo escrita.
        printf("Arquivo Salvo com sucesso!\n");
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
        printf("Arquivo lido com sucesso!\n");
    }
}
//menu da busca
void menuBusca(Raiz *pt){
    No_ab *temp = pt->ptRaiz; //variavel para armazenar a raiz
    int valorBuscar, aux;//variavel que recebe um valor a ser buscado
    unsigned short f;//variavel f usada para indicar se  vazia, achou ou não variavel op para indicar se deseja inserir na arvore ou não
    unsigned short op;
    printf("\n Informe Qual Valor Devo Buscar: \n");
    scanf("%d", &valorBuscar);
    //busca a arvore
    buscaArvore(valorBuscar, &pt->ptRaiz, &f);
    //se o resultado da busca armazenado em f for igual a zero então essa arvore está vazia
    if(f == 0){
        printf("Arvore vazia!\n");
    }else{
        //se o resultado da busca igual a um o elemento foi encontrado
        if(f == 1){
            printf("Chave encontrada!\n");
            pt->ptRaiz = temp;//seta para a raiz

        }else{
            printf("Chave não encontrada!\n");
        }
    }
}
//principal
int main(){
    Raiz *pt = malloc(sizeof(Raiz));
    FILE *arq;
    char buffer[100];
    char str[] = "testando";
    int valor = 0;
    do{
        printf("\n-------manu-------\n");
        printf("0-Sair 1-Inserir arvore\n 2-Remover Elemento Arvore 3-Desenha arvore\n 4-Salvar Arvore  5-Ler Do Arquivo \n 6-Buscar Elemento Na Arvore 7-Imprimir No Terminal\n");
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

                        }else{
                            if(valor == 6){
                                menuBusca(pt);
                            }else{
                                if(valor == 7){
                                    printTerminal(pt->ptRaiz);
                                }
                            }
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
