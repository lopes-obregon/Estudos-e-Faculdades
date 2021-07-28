
package entidade;

/**
 *
 * @author renan
 */
public class Cirurgia {
    public enum tipoAnestesia{geral, inalatória, injetável, local, nada};
    private String nome_do_paciente;
    private int idade_paciente;
    tipoAnestesia anestesia;
    private int hora_entrada;
    private int hora_saida;
    private boolean aplicou_anestesia;

    public boolean isAplicouAnestesia() {
        return aplicou_anestesia;
    }

    public void setAplicouAnestesia(boolean aplicou_anestesia) {
        this.aplicou_anestesia = aplicou_anestesia;
    }

    public Cirurgia(String nome_do_paciente, int idade_paciente, tipoAnestesia anestesia, int hora_entrada, int hora_saida, boolean aplicou_anestesia) {
        this.nome_do_paciente = nome_do_paciente;
        this.idade_paciente = idade_paciente;
        this.anestesia = anestesia;
        this.hora_entrada = hora_entrada;
        this.hora_saida = hora_saida;
        this.aplicou_anestesia = aplicou_anestesia;
    }

    public String getNomeDoPaciente() {
        return nome_do_paciente;
    }

    public void setNomeDoPaciente(String nome_do_paciente) {
        this.nome_do_paciente = nome_do_paciente;
    }

    public int getIdadePaciente() {
        return idade_paciente;
    }

    public void setIdadePaciente(int idade_paciente) {
        this.idade_paciente = idade_paciente;
    }

    public tipoAnestesia getAnestesia() {
        return anestesia;
    }

    public void setAnestesia(tipoAnestesia anestesia) {
        this.anestesia = anestesia;
    }

    public int getHoraEntrada() {
        return hora_entrada;
    }

    public void setHoraEntrada(int hora_entrada) {
        this.hora_entrada = hora_entrada;
    }

    public int getHoraSaida() {
        return hora_saida;
    }

    public void setHoraSaida(int hora_saida) {
        this.hora_saida = hora_saida;
    }

    @Override
    public String toString() {
        return "Cirurgia{" + "Nome Do Paciente=" + nome_do_paciente + ", Idade Paciente=" + idade_paciente + ", Anestesia=" + anestesia + ", Hora Entrada=" + hora_entrada + ", Hora Saida=" + hora_saida + '}';
    }
    
}
