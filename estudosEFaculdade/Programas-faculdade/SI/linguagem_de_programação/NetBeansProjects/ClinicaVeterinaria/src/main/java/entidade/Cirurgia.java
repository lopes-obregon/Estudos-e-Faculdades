package entidade;

/**
 *
 * @author renan
 */
public class Cirurgia {
    public enum Anestesia{geral, inalatória, injetável, local, nenhuma};
    
    Anestesia anestesia;//filtro
    private Hora hora_entrada;
    private Hora hora_saida;
    private boolean urgente; //filtro
    private Hora tempo_internação;  //tempo_minimo_internação
    private String tipo_de_cirurgia;
    private String código_do_animal;
    public boolean isUrgente() {
        return urgente;
    }

    public void setUrgente(boolean urgente) {
        this.urgente = urgente;
    }

    public Cirurgia(Anestesia anestesia, Hora hora_entrada, Hora hora_saida, boolean urgente, Hora tempo_internação, String tipo_de_cirurgia, String código_do_animal) {
        this.anestesia = anestesia;
        this.hora_entrada = hora_entrada;
        this.hora_saida = hora_saida;
        this.urgente = urgente;
        this.tempo_internação = tempo_internação;
        this.tipo_de_cirurgia = tipo_de_cirurgia;
        this.código_do_animal = código_do_animal;
    }

   

    public Anestesia getAnestesia() {
        return anestesia;
    }

    public void setAnestesia(Anestesia anestesia) {
        this.anestesia = anestesia;
    }
    public String getCódigoDoAnimal(){
        return código_do_animal;
    }
    

    @Override
    public String toString() {
        String dados = " \n--Código:"+código_do_animal+" --Hora De Entrada:" + hora_entrada+ " --Hora De Saida:"+ hora_saida+ " --Tempo De Internação:" + tempo_internação + " --- Tipo da cirurgia:" + tipo_de_cirurgia;
        if(urgente == true)dados += " --Urgente: " + "Sim";
        else
            dados += " --Urgente:" + "Não";
        return dados;
    }
   
}
