
package entidade;

/**
 *
 * @author renan
 */
public class Curso {
    private String título;
    private int carga_horária_semanal, duração_semanas;
    private ArrayList<Curso> pré_requisitos = new ArrayList();
}
