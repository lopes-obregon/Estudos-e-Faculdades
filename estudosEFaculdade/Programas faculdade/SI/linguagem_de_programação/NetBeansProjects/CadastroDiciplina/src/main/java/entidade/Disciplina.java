
package entidade;

/**
 *
 * @author renan
 */
public class Disciplina {

    private String titulo;
    private int carga_horária_total;
    private int carga_horária_prática;
    public enum Tipo{obrigatória, optativa, eletiva};
    private boolean reuni;

    public Disciplina(String titulo, int carga_horária_total, int carga_horária_prática, boolean reuni) {
        this.titulo = titulo;
        this.carga_horária_total = carga_horária_total;
        this.carga_horária_prática = carga_horária_prática;
        this.reuni = reuni;
    }
    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getCarga_horária_total() {
        return carga_horária_total;
    }

    public void setCarga_horária_total(int carga_horária_total) {
        this.carga_horária_total = carga_horária_total;
    }

    public int getCarga_horária_prática() {
        return carga_horária_prática;
    }

    public void setCarga_horária_prática(int carga_horária_prática) {
        this.carga_horária_prática = carga_horária_prática;
    }

    public boolean isReuni() {
        return reuni;
    }

    public void setReuni(boolean reuni) {
        this.reuni = reuni;
    }

    @Override
    public String toString() {
        return "Disciplina{" + "titulo=" + titulo + ", carga horária total=" + carga_horária_total + ", carga_horária prática=" + carga_horária_prática + ", reuni=" + reuni + '}';
    }
    
}
