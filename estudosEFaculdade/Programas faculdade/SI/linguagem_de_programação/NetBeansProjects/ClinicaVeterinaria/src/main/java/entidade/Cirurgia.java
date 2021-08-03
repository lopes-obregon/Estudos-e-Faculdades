
package entidade;

/**
 *
 * @author renan
 */
public class Cirurgia {
    public enum Anestesia{geral, inalatória, injetável, local, nem_uma};
    
    Anestesia anestesia;//filtro
    private int hora_entrada;
    private int hora_saida;
    private boolean urgente; //filtro
    private int tempo_internação;  //tempo_minimo_internação

    public boolean isUrgente() {
        return urgente;
    }

    public void setUrgente(boolean urgente) {
        this.urgente = urgente;
    }

    public Cirurgia(Anestesia anestesia, int hora_entrada, int hora_saida, boolean urgente, int tempo_internação) {
        this.anestesia = anestesia;
        this.hora_entrada = hora_entrada;
        this.hora_saida = hora_saida;
        this.urgente = urgente;
        this.tempo_internação = tempo_internação;
    }

    public Anestesia getAnestesia() {
        return anestesia;
    }

    public void setAnestesia(Anestesia anestesia) {
        this.anestesia = anestesia;
    }

    public int getHora_entrada() {
        return hora_entrada;
    }

    public void setHora_entrada(int hora_entrada) {
        this.hora_entrada = hora_entrada;
    }

    public int getHora_saida() {
        return hora_saida;
    }

    public void setHora_saida(int hora_saida) {
        this.hora_saida = hora_saida;
    }

    public int getTempo_internação() {
        return tempo_internação;
    }

    public void setTempo_internação(int tempo_internação) {
        this.tempo_internação = tempo_internação;
    }

    

    @Override
    public String toString() {
        return "Hora De Entrada:" + toStringHora(hora_entrada)+ "Hora De Saida:"+ toStringHora(hora_saida)+ "Tempo De Internação:" + tempo_internação;
    }
    private String toStringHora(int hora){
        if(hora == 0 ){
            return "Meia Noite -";
        }else{
            return Integer.toString(hora) +"h -";
        }
    }
}
