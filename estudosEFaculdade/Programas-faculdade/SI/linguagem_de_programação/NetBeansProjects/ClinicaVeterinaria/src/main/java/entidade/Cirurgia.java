package entidade;

import java.util.HashMap;
import util.Hora;

/**
 *
 * @author renan
 */
public class Cirurgia extends Serviço {
    //parte do conjunto dos objetos
    public static HashMap<String, Cirurgia> cirurgias = new HashMap();
    
    public static boolean addCirurgia(Cirurgia cirurgia){
        //String código = vacinação.getChaveDoServiço();
        String código = cirurgia.getChaveDoServiço();

        if(cirurgias.get(código) == null){
            cirurgias.put(código, cirurgia);
            return true;
        }else return false;
    }
    public static Cirurgia getCirurgia(String código){
        return cirurgias.get(código);
    }
    public static HashMap<String, Cirurgia> getCirurgias(){
        return cirurgias;
    }
   
    
//parte dos métodos especifico de cada objeto
    
    public enum Anestesia{geral, inalatória, injetável, local, nenhuma};
    
    Anestesia anestesia;//filtro
    private Hora hora_entrada;
    private Hora hora_saida;
    private String tipo_de_cirurgia;
  
    public Cirurgia(Anestesia anestesia, Hora hora_entrada, Hora hora_saida, String tipo_de_cirurgia, boolean urgente, String código_do_serviço) {
        super(urgente, código_do_serviço);
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
       
        String dados = "\nCirurgia";
        dados += "\tCódigo do serviço: " + super.getChaveDoServiço();
        dados += "\n Hora De Entrada:" + hora_entrada + "\tHora De Saida:"+ hora_saida + "\tTipo da cirurgia:" + tipo_de_cirurgia+"\tAnestesia:"+anestesia ;
        if(super.isUrgente() == true)dados += "\t Entrada urgente: " + "Sim";
        else
            dados += "\tEntrada Urgente:" + "Não";
        return dados;
    }
   
}
