
package controle;

import entidade.Aluno;
import entidade.Curso;
import entidade.Data;
import entidade.Endereço;
import entidade.Matrícula;
import entidade.Matrícula.Bolsa;
import java.util.ArrayList;
import java.util.HashMap;

/**
 *
 * @author renan
 */
public class EscolaInformática {
    public static HashMap<String, Curso> cursos = new HashMap();
    public static HashMap<String, Aluno> alunos = new HashMap();
    public static ArrayList<Matrícula> matrículas = new ArrayList();
    public static void main(String[] args) {
        cadastrarCursos();
        cadastrarAlunos();
        cadastrarMatrículas();
        imprimirMatrículas("Matrículas Cadastradas:", matrículas);
        imprimirMatrículas("Matrículas Selecionadas:",
        selecionarMatrículas(null, null, 'X'));
        imprimirMatrículas("Matrículas Selecionadas:",
        selecionarMatrículas(Bolsa.parcial, null, 'X'));
        imprimirMatrículas("Matrículas Selecionadas:",
        selecionarMatrículas(Bolsa.parcial, "Dourados", 'X'));
        imprimirMatrículas("Matrículas Selecionadas:",
        selecionarMatrículas(Bolsa.parcial, "Dourados", 'F'));
    }
    public static void inserirAluno(Aluno novo_aluno){
        String chave_aluno = novo_aluno.getCpf();
        if(alunos.get(chave_aluno) == null) alunos.put(chave_aluno, novo_aluno);
        else System.out.println("Aluno já cadastrado");
    }
    private static void inserirMatrícula(String cpf_aluno, String título_curso, Matrícula.Bolsa bolsa, Data inícioData){
        Aluno aluno = alunos.get(cpf_aluno);
        Curso curso  = cursos.get(título_curso);
        if(aluno == null){
            System.out.println("Matrícula mal sucedida: aluno não cadastrado");
            return;
        }
        if(curso == null){
            System.out.println("Matrícula mal sucedida: curso não cadastrado");
            return ;
        }
        matrículas.add(new Matrícula(aluno, curso,bolsa, inícioData));
    }
    private static void cadastrarAlunos() {
        inserirAluno(new Aluno("Ana Julia Parra", "31.845.917", "212.234.571-32",
        new Data(15, 10, 1982), 'F',
        new Endereço("Rua Arco Verde", 171, "apto 301","Água Boa", "Dourados", "79810-015")));
        inserirAluno(new Aluno("Ana Ligia Silveira", "32.870.923", "312.434.775-30",
        new Data(8, 8, 1985), 'F',
        new Endereço("Rua Chapéu Velho", 303, null, "Rouxinol", "Glória de Dourados",
        "79820-017")));
        inserirAluno(new Aluno("André Oliveira", "41.825.341", "531.331.740-71",
        new Data(20, 3, 1993), 'M',
        new Endereço("Rua Sino da Mata", 303, null, "Brejão", "Caarapó", "73100-000")));
    }
    private static void cadastrarCursos() {
        inserirCurso(new Curso("Java Básico", 8, 10));
        inserirCurso(new Curso("Java Aplicações Locais", 8, 10));
        inserirCurso(new Curso("Java Aplicações Web", 8, 10));
        inserirCurso(new Curso("Banco de Dados Básico", 8, 8));
        inserirCurso(new Curso("Banco de Dados Avançado", 8, 8));
        Curso curso1 = cursos.get("Java Básico");
        Curso curso2 = cursos.get("Java Aplicações Locais");
        Curso curso3 = cursos.get("Java Aplicações Web");
        Curso curso4 = cursos.get("Banco de Dados Básico");
        Curso curso5 = cursos.get("Banco de Dados Avançado");
        curso2.inserirPréRequisito(curso1);
        curso2.inserirPréRequisito(curso4);
        curso3.inserirPréRequisito(curso2);
        curso5.inserirPréRequisito(curso4);
    }

    private static void inserirCurso(Curso curso) {
        
    }
    
    public static void cadastrarMatrículas() {
        inserirMatrícula("212.234.571-32", "Java Básico", Bolsa.completa, new Data(1, 3, 2013));
        inserirMatrícula("312.434.775-30", "Java Básico", Bolsa.parcial, new Data(1, 3, 2013));
        inserirMatrícula("212.234.571-32", "Java Aplicações Locais", Bolsa.parcial,
        new Data(1, 6, 2013));
        inserirMatrícula("312.434.775-30", "Java Aplicações Locais", Bolsa.nenhuma,
        new Data(1, 6, 2013));
        inserirMatrícula("212.234.571-32", "Java Aplicações Web", Bolsa.parcial,
        new Data(1, 9, 2013));
        inserirMatrícula("312.434.775-30", "Java Aplicações Web", Bolsa.nenhuma,
        new Data(1, 9, 2013));
        inserirMatrícula("212.234.571-32", "Banco de Dados Básico", Bolsa.parcial,
        new Data(1, 3, 2013));
        inserirMatrícula("312.434.775-30", "Banco de Dados Básico", Bolsa.nenhuma,
        new Data(1, 3, 2013));
        inserirMatrícula("531.331.740-71", "Banco de Dados Básico", Bolsa.nenhuma,
        new Data(1, 3, 2013));
        inserirMatrícula("212.234.571-32", "Banco de Dados Avançado", Bolsa.nenhuma,
        new Data(1, 6, 2013));
        inserirMatrícula("531.331.740-71", "Banco de Dados Avançado", Bolsa.nenhuma,
        new Data(1, 6, 2013));
        
    }


   private static void imprimirMatrículas(String cabeçalho, ArrayList<Matrícula> matrículas) {
        System.out.println(cabeçalho);
        int n = 1;
        for (Matrícula matrícula : matrículas) {
            System.out.println(n++ + " - " + matrícula);
        }
   }


    private static ArrayList<Matrícula> selecionarMatrículas(Bolsa bolsa_matrícula, String cidade_aluno, char curso_sem_prérequisitos) {
        System.out.println("\nFiltros:"
        + " bolsa da matrícula = " + bolsa_matrícula
        + " -- cidade do aluno = " + cidade_aluno
        + " -- curso sem prérequisitos = " + curso_sem_prérequisitos);
        ArrayList<Matrícula> matrículas_selecionadas = new ArrayList();
        for (Matrícula matrícula : matrículas) {
        Bolsa bolsa = matrícula.getBolsa();
        String cidade = matrícula.getAluno().getEndereço().getCidade();
        int n_pré_requisitos = matrícula.getCurso().getPréRequisitos().size();
        if ((bolsa_matrícula != null) && (bolsa_matrícula != bolsa)) continue;
        if ((cidade_aluno != null) && !cidade_aluno.equals(cidade)) continue;
        if ((curso_sem_prérequisitos == 'T') && (n_pré_requisitos > 0)) continue;
        if ((curso_sem_prérequisitos == 'F') && (n_pré_requisitos == 0)) continue;
        matrículas_selecionadas.add(matrícula);
        }
        return matrículas_selecionadas;
}

}
