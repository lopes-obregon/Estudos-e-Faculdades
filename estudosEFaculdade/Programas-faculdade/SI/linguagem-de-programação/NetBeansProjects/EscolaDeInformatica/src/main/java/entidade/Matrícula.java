
package entidade;

/**
 *
 * @author renan
 */
public class Matrícula {



   
    public enum Bolsa{completa, parcial, nenhuma};
    private Aluno aluno;
    private Curso curso;
    private Bolsa bolsa;
    private Data data_início;
    private float nota_final;

    public Matrícula(Aluno aluno, Curso curso, Bolsa bolsa, Data data_início) {
        this.aluno = aluno;
        this.curso = curso;
        this.bolsa = bolsa;
        this.data_início = data_início;
        nota_final = -1.0f;
    }

    @Override
    public String toString() {
        String dados = "Aluno:" + aluno+ "\n Curso:" + curso+ "\n Data início:"+ data_início;
        if(bolsa != Bolsa.nenhuma) dados += "- bolsa:"+ bolsa;
        if(nota_final >= 0)dados += "- nota final:" + nota_final;
        return dados;
    }
    
    public Bolsa getBolsa() {
        return bolsa;
    }
    public Object getAluno() {
        return aluno;
    }

    public Object getCurso() {
        return curso;
    }
}
