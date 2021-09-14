
package controle;

import entidade.Agendamento;
import entidade.Animal;
import entidade.Cirurgia;
import entidade.Cirurgia.Anestesia;
import entidade.Hospedagem;
import util.Data;
import util.Endereço;
import util.Hora;
import entidade.Proprietário;
import entidade.Vacinação;
import entidade.Vacinação.Vacina;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author renan
 */
public class ClinicaVeterinaria {
    public static ArrayList<Agendamento> agendamentos = new ArrayList();//ultimo cadastro
    public static void main(String[] args) {
      // cadastrarProprietário();
       //cadastrarAnimal();
       //cadastrarCirurgia();
        cadastrarAgendamento();
        imprimirAgendamentos("Agendamentos Cadastrados", agendamentos);
        /*agendamentos =  selecionarAgendas(null, null, 'X');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendas(new Data(16, 5, 2021), null, 'X');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendas(new Data(16, 5, 2021), "Dourados", 'X');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendas(new Data(16, 5, 2021), "Dourados", 'T');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);*/
    }
    //public Agendamento(Data data_de_agendamento,  Hora hora_do_agendamento, Serviço serviço, Animal animal) {
    private static void cadastrarAgendamento() {
        agendamentos.add(new Agendamento(
        new Data(5, 7, 2021)
        , new Hora(13, 14)
        , new Cirurgia(Anestesia.geral
        , new Hora(13, 20)
        , new Hora(14, 20), false,"Geral","001"
        )
        , new Animal("Lola", "vira lata", "longo","branco"
        ,new Data(15, 8, 2013), 'F'
        , new Proprietário("Carol",  "111.111.111-11"
        ,new Endereço("Casa", "", "Moreninha", "Campo Gradne", "11111-111", 140)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(8, 7, 2021)
        , new Hora(13, 14)
        , new Cirurgia(Anestesia.geral
        , new Hora(13, 20)
        , new Hora(14, 20), true,"Geral","002"
        )
        , new Animal("Banguela", "vira lata", "curto","preto, creme, bege, marrom"
        ,new Data(15, 8, 2013), 'M'
        , new Proprietário("Carol",  "111.111.111-11"
        ,new Endereço("Casa", "", "Moreninha", "Campo Gradne", "11111-111", 140)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(9, 7, 2021)
        , new Hora(13, 14)
        , new Cirurgia(Anestesia.geral
        , new Hora(13, 20)
        , new Hora(14, 20), true,"Geral","003"
        )
        , new Animal("Bolinha", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'M'
        , new Proprietário("Carol",  "222.222.222-22"
        ,new Endereço("Casa", "", "Marcelino", " Dourados", "22222-222", 135)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(9, 7, 2021)
        , new Hora(13, 14)
        , new Vacinação("004", false
        , new Data(10, 9, 2021), Vacina.antirrábica)
        , new Animal("Sorvete", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'M'
        , new Proprietário("Alfredo",  "333.333.333-33"
        ,new Endereço("Casa", "", "Marcelino", " Dourados", "33333-333", 140)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(9, 7, 2021)
        , new Hora(13, 14)
        , new Vacinação("005", false
        , new Data(10, 9, 2021), Vacina.antirrábica)
        , new Animal("Faisca", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'M'
        , new Proprietário("Marcelo",  "444.444.444-44"
        ,new Endereço("Casa", "", "Marcelino", " Dourados", "44444-444", 970)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(9, 7, 2021)
        , new Hora(13, 14)
        , new Vacinação("006", false
        , new Data(10, 9, 2021), Vacina.contra_a_gripe)
        , new Animal("Fumaça", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'M'
        , new Proprietário("Ane",  "555.555.555-55"
        ,new Endereço("Casa", "", "Weimar", " Dourados", "55555-555", 130)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(9, 7, 2021)
        , new Hora(13, 14)
        , new Hospedagem("007", false
        , new Data(14, 4, 2021)
        , new Data(18, 4, 2021))
        , new Animal("Mel", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'F'
        , new Proprietário("izabel",  "666.666.666-66"
        ,new Endereço("Casa", "", "Torres", " Dourados", "66666-666", 235)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(9, 7, 2021)
        , new Hora(13, 14)
        , new Hospedagem("007", false
        , new Data(14, 4, 2021)
        , new Data(18, 4, 2021))
        , new Animal("Nina", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'F'
        , new Proprietário("izabel",  "666.666.666-66"
        ,new Endereço("Casa", "", "Torres", " Dourados", "66666-666", 235)))
        ));
        
        agendamentos.add(new Agendamento(
        new Data(9, 7, 2021)
        , new Hora(13, 14)
        , new Hospedagem("008", false
        , new Data(20, 6, 2021)
        , new Data(26, 6, 2021))
        , new Animal("Amora", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'F'
        , new Proprietário("Marcos",  "777.777.777-77"
        ,new Endereço("Casa", "", "Monte Alegre", " Dourados", "77777-777", 580)))
        ));
    }

    private static void imprimirAgendamentos(String cabeçalho, ArrayList<Agendamento> agendamentos) {
        int n = 1;
        System.out.println(cabeçalho);
        for (Agendamento agendamento : agendamentos) {
            System.out.println(n++ +" - " + agendamento);
            
        }
        System.out.println();
        
    }
    
    private static  ArrayList<Agendamento> selecionarAgendamentos(Vacina vacina_aplicada, String cidade,Data data_minima ,boolean urgente ){
        ArrayList<Agendamento> agendamento_selecionados = new ArrayList();
        System.out.println("Filtros de Obras:"
        + "\n - vacina aplicada: " + vacina_aplicada
        + "\n - Cidade: " + cidade
        + "\n - Data minima de entrada na hospedagem: " + data_minima
        + "\n - urgete: " + urgente
        + "\n");
        
    }
}
