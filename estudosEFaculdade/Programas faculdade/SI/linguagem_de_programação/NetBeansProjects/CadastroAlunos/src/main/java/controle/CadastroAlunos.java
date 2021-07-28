
package controle;

import entidade.Aluno;
import entidade.Aluno.EstadoCivil;
import java.util.ArrayList;


public class CadastroAlunos {
    private static Aluno[] alunos_cadastrados;
    //private static Aluno[] alunos;
    public static void main(String[] args) {
       cadastrarAlunos();
       imprimirAlunos("Alunos Cadastrados", alunos_cadastrados);
       ArrayList<Aluno>alunos_selecionados = selecionarAlunos(EstadoCivil.solteiro, 'F', 1992);
        imprimirAlunos("Alunos Selecionados", alunos_selecionados.toArray(new Aluno[alunos_selecionados.size()]));
       
    }

    private static void cadastrarAlunos() {
        alunos_cadastrados = new Aluno[8];
        alunos_cadastrados[0] = new Aluno("Ana Julllia", 1995, 'F', EstadoCivil.solteiro, false);
        alunos_cadastrados[1] = new Aluno("Joaquim", 1990, 'M', EstadoCivil.casado, true);
        alunos_cadastrados[2] = new Aluno("Ana Ligia", 1998, 'F', EstadoCivil.solteiro, false);
        alunos_cadastrados[3] = new Aluno("Mateus", 1991, 'M', EstadoCivil.solteiro, false);
        alunos_cadastrados[4] = new Aluno("Livia", 1985, 'F', EstadoCivil.casado, true);
        alunos_cadastrados[5] = new Aluno("Roberto", 1990, 'M', EstadoCivil.casado, false);
        alunos_cadastrados[6] = new Aluno("Ana Maria", 1991, 'F', EstadoCivil.solteiro, false);
        alunos_cadastrados[7] = new Aluno("Sandro", 1992, 'M', EstadoCivil.solteiro, true);
        
    }

    private static void imprimirAlunos(String alunos_Cadastrados, Aluno[] alunos1) {
        int n = 1;
        System.out.println(alunos_Cadastrados);
        for (Aluno aluno: alunos1) {
            System.out.println(n++ +"-"+ aluno);
            
        }
    }

    private static ArrayList<Aluno> selecionarAlunos(EstadoCivil estado_civil, char estrangeiro, int ano_inicial) {
        ArrayList<Aluno> alunos_selecionados = new ArrayList();
        EstadoCivil estado_civil_aluno;
        boolean is_estrangeiro;
        int ano_nascimento;
        System.out.println("\n---Filtros:"
        + "- Estado Civil:"+ estado_civil
        + " - Estrangeiro=" + estrangeiro
        + " - Ano Inicial:" + ano_inicial + "\n");
        for (Aluno aluno : alunos_cadastrados) {
            estado_civil_aluno = aluno.getEstadiCivil();
            is_estrangeiro = aluno.getEstrangeiro();
            ano_nascimento = aluno.getAnoNascimento();
            if((estado_civil != null) && (estado_civil != estado_civil_aluno)) continue;
            if((estrangeiro == 'T') && !is_estrangeiro) continue;
            if((estrangeiro == 'F') && is_estrangeiro) continue;
            if((ano_inicial != -1) && (ano_nascimento < ano_inicial)) continue;
            alunos_selecionados.add(aluno);
            
        }
        return alunos_selecionados;
    }
}
