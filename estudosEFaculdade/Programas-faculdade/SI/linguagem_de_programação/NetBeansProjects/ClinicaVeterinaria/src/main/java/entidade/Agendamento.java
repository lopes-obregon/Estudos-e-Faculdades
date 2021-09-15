
package entidade;

import util.Hora;
import util.Data;

/**
 *
 * @author renan
 */
public class Agendamento {

    //data de agendamento
    private Data data_de_agendamento;//filtro
    private Serviço serviço;
    private Animal animal; //filtro
    private Hora hora_do_agendamento;//filtro

    public Agendamento(Data data_de_agendamento,  Hora hora_do_agendamento, Serviço serviço, Animal animal) {
        this.data_de_agendamento = data_de_agendamento;
        this.serviço = serviço;
        this.animal = animal;
        this.hora_do_agendamento = hora_do_agendamento;
    }
    public Data getDataDeAgendamento(){
        return data_de_agendamento;
    }
    public Animal getAnimal(){
        return animal;
    }
    public Serviço getServiço(){
        return serviço;
    }
    @Override
    public String toString() {
        String dados = "Data do agendamento:" + data_de_agendamento + "\tHora agendada:" + hora_do_agendamento + animal+serviço;  
        return dados;
    }
    
}
