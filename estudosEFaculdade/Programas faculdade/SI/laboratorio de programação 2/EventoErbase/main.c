#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//enumerado
enum TipoPariticipacao {A = 1, B, C, D};
//estruturas
typedef struct{
    char string[3];
}boolean;


typedef struct{
    char nome[15];
    char sobrenome[15];
    enum TipoPariticipacao participacao;
    boolean socio_da_sbc;
}erbase;
//prot�tipos
void cadastroPariticipante(erbase participante);
void imprimeParitcipantes(erbase participante);
float calculoDoPreco(erbase participante);
void getEnum(erbase participante);
void printEnum(erbase participante);
int main()
{
    erbase aluno;
    cadastroPariticipante(aluno);
    imprimeParitcipantes(aluno);
    calculoDoPreco(aluno);
    return 0;
}
void cadastroPariticipante(erbase participante){
    printf("Entre com o nome:");
    scanf("%s%*c", participante.nome);
    printf("Entre com o sobrenome:");
    scanf("%s%*c", participante.sobrenome);
   // printf("Entre com o tipo de participa��o: ");
    //scanf("%d%*c", &participante.participacao);
    getEnum(participante);
    printf("Socio SBC S-SIM OU N-NAO: ");
    scanf("%s%*c", participante.socio_da_sbc.string);
}
void imprimeParitcipantes(erbase participante){
    printf("---PARTICIPANTES CADASTRADOS---\n");
    printf("Nome: %s %s  Socio SBC:%s", participante.nome, participante.sobrenome, participante.socio_da_sbc);
    printEnum(participante);
}
float calculoDoPreco(erbase participante){
    if(participante.participacao == A){
        return 30;
    }else if(participante.participacao == B){
        return 60;
    }else if(participante.participacao == C){
        return 90;
    }else if(participante.participacao == D){
        return 100;
    }

}
void getEnum(erbase participante){
    char string[2];
    printf("Entre com o tipo de participacao: ");
    scanf("%s%*c", string);
    if((strcmp(string, "A") ||(strcmp(string, "a") || (strcmp(string, "1"))))){
        participante.participacao = A;
    }else if((strcmp(string, "B") ||(strcmp(string, "b") || (strcmp(string, "2"))))){
        participante.participacao = B;
    }else if((strcmp(string, "C") ||(strcmp(string, "c") || (strcmp(string, "3"))))){
        participante.participacao = C;
    }else if((strcmp(string, "D") ||(strcmp(string, "d") || (strcmp(string, "4"))))){
        participante.participacao = D;
    }
}
//imprime o enum
void printEnum(erbase participante){
    if(participante.participacao == A){
        printf("Tipo participacao: A\n");
    }else if(participante.participacao == B){
        printf("Tipo participacao: B\n");
    }else if(participante.participacao == C){
        printf("Tipo participacao: C\n");
    } else if(participante.participacao == D){
        printf("Tipo participacao: D\n");
    }
}