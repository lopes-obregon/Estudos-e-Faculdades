
package entidade;

import interfaces.InterfaceTextual;
import java.util.ArrayList;
import util.Hora;
import util.Data;

/**
 *
 * @author renan
 */
public class Agendamento {
    //private static HashMap<String, Agendamento> agendamentos = new HashMap();
    private static ArrayList<Agendamento> agendamentos = new ArrayList();
    public static boolean addAgendamento(Agendamento agendamento){
       return agendamentos.add(agendamento);
        
    }
    public static ArrayList<Agendamento> getAgendamentos(){
        return agendamentos;
    }
    public static Agendamento lerAgendamento(){
        Data data_agendada = InterfaceTextual.lerData("Entre com uma  data no formato");
        if(data_agendada == null) return null;
        
        Hora hora_agendada = InterfaceTextual.lerHora("Hora do agendamento no formato ");
        if(hora_agendada == null) return null;
        
        String código_do_serviço = InterfaceTextual.lerString("Entre com o código do serviço");
        Serviço serviço_realizado = Serviço.getServiço(código_do_serviço);
        if(serviço_realizado == null) return null;
        
        String código_do_animal = InterfaceTextual.lerString("Entre com o código do animal");
        Animal animal  =  Animal.getAnimal(código_do_animal);
        if(animal == null) return null;
        return new Agendamento(código_do_animal, data_agendada, hora_agendada, serviço_realizado, animal);
    }
    //data de agendamento
    private Data data_de_agendamento;//filtro
    private Serviço serviço;
    private Animal animal;
    private Hora hora_do_agendamento;//filtro
    private String chave_do_agendamento;
    public Agendamento(String código_do_agendamento, Data data_de_agendamento,  Hora hora_do_agendamento, Serviço serviço, Animal animal) {
        this.data_de_agendamento = data_de_agendamento;
        this.serviço = serviço;
        this.animal = animal;
        this.hora_do_agendamento = hora_do_agendamento;
        this.chave_do_agendamento = código_do_agendamento;
    }
    public Data getDataDeAgendamento(){
        return data_de_agendamento;
    }
    public Animal getAnimal(){
        return animal;
    }
    public Hora getHoraDoAgendamento(){
        return hora_do_agendamento;
    }
    public Serviço getServiço(){
        return serviço;
    }
    public String getChaveDoAgendamento(){
        return chave_do_agendamento;
    }
    @Override
    public String toString() {
        String dados = "Código do agendamento:"+chave_do_agendamento +"\nData do agendamento:" + data_de_agendamento + "\tHora agendada:" + hora_do_agendamento + animal+serviço;  
        return dados;
    }
    
}
