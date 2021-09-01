
package entidade;

/**
 *
 * @author renan
 */
public class Agendamento {

    //data de agendamento
    Data data_de_agendamento;
    Cirurgia cirurgia;
    Animal animal;
    Hora hora_do_agendamento;

    public Agendamento(Data data_de_agendamento, Cirurgia cirurgia, Animal animal, Hora hora_do_agendamento) {
        this.data_de_agendamento = data_de_agendamento;
        this.cirurgia = cirurgia;
        this.animal = animal;
        this.hora_do_agendamento = hora_do_agendamento;
    }

    @Override
    public String toString() {
        String dados = "Data do agendamento:" + data_de_agendamento + "\nCirurgia:" + cirurgia + "\nAnimal:"+animal + "\n Hora do agendamento:" + hora_do_agendamento;
        return dados;
    }
    
}
