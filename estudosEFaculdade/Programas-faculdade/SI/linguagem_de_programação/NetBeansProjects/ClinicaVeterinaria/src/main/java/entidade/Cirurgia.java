package entidade;

import util.Hora;

/**
 *
 * @author renan
 */
public class Cirurgia extends Serviço {
    public enum Anestesia{geral, inalatória, injetável, local, nenhuma};
    
    Anestesia anestesia;//filtro
    private Hora hora_entrada;
    private Hora hora_saida;
    private String tipo_de_cirurgia;
  
    public Cirurgia(Anestesia anestesia, Hora hora_entrada, Hora hora_saida, boolean urgente, String tipo_de_cirurgia, String código_do_animal) {
        super(código_do_animal, urgente);
        this.anestesia = anestesia;
        this.hora_entrada = hora_entrada;
        this.hora_saida = hora_saida;
        this.tipo_de_cirurgia = tipo_de_cirurgia;
    }

   

    public Anestesia getAnestesia() {
        return anestesia;
    }
    @Override
    public String toString() {
        String dados = "\nCirurgia\t Código do animal"+super.getCódigoDoAnimal()+"\nHora De Entrada:" + hora_entrada+ "\tHora De Saida:"+ hora_saida + "\tTipo da cirurgia:" + tipo_de_cirurgia+"\tAnestesia:"+anestesia ;
        if(super.isUrgente() == true)dados += "\tUrgente: " + "Sim";
        else
            dados += "\tUrgente:" + "Não";
        return dados;
    }
   
}
