
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
    private Data data_inicio;
    private float nota_final;
}
