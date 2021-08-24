#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//enumerado
enum pariticipacaos {A = 1, B, C, D}participacao;
//estruturas
typedef struct{
    char nome[15];
    char sobrenome[15];
    enum pariticipacaos pariticipacao_do_aluno;
    char socio_da_sbc[3];
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
    scanf("%s%*c", participante.socio_da_sbc);
}
void imprimeParitcipantes(erbase participante){
    printf("---PARTICIPANTES CADASTRADOS---\n");
    printf("Nome: %s %s  Socio SBC:%s", participante.nome, participante.sobrenome, participante.socio_da_sbc);
    printEnum(participante);
}
float calculoDoPreco(erbase participante){
    if(participante.pariticipacao_do_aluno == A){
        return 30;
    }else if(participante.pariticipacao_do_aluno == B){
        return 60;
    }else if(participante.pariticipacao_do_aluno == C){
        return 90;
    }else if(participante.pariticipacao_do_aluno == D){
        return 100;
    }

}
void getEnum(erbase participante){
   
    printf("Entre com o tipo de participacao: ");
    scanf("%d%*c", &participacao);
    if(participacao == A){
        participante.pariticipacao_do_aluno = A;
    }else if(participacao == B){
        participante.pariticipacao_do_aluno = B;
    }else if(participacao == C){
        participante.pariticipacao_do_aluno = C;
    }else{
        participante.pariticipacao_do_aluno = D;
    }
    
}
//imprime o enum
void printEnum(erbase participante){
    if(participante.pariticipacao_do_aluno == A){
        printf("Tipo participacao: A\n");
    }else if(participante.pariticipacao_do_aluno == B){
        printf("Tipo participacao: B\n");
    }else if(participante.pariticipacao_do_aluno == C){
        printf("Tipo participacao: C\n");
    } else if(participante.pariticipacao_do_aluno == D){
        printf("Tipo participacao: D\n");
    }
}