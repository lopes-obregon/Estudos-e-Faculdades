
package controle;

import entidade.Agendamento;
import entidade.Animal;
import entidade.Cirurgia;
import entidade.Cirurgia.Anestesia;
import entidade.Data;
import entidade.Endereço;
import entidade.Hora;
import entidade.Proprietário;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 *
 * @author renan
 */
public class ClinicaVeterinaria {
    public static ArrayList<Agendamento> agendamentos = new ArrayList();//ultimo cadastro
    public static HashMap<String, Cirurgia> cirurgias = new HashMap();//chave nome do animal
    public static HashMap<String, Animal> animais = new HashMap();//nome do proprietário ou um id
    public static HashMap<String, Proprietário> proprietários = new HashMap();//chave cpf
    public static void main(String[] args) {
       cadastrarProprietário();
       cadastrarAnimal();
       cadastrarCirurgia();
        cadastrarAgendamento();
        imprimirAgendamentos("Agendamentos Cadastrados", agendamentos);
        agendamentos =  selecionarAgendas(null, null, 'F');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendas(new Data(15, 5, 2021), null, 'F');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendas(new Data(15, 5, 2021), "Dourados", 'F');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendas(new Data(15, 5, 2021), "Dourados", 'T');
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
    }
    //public Data(int dia, int mês, int ano)
    //public Animal(String nome, String raça, String pelagem, Data data_nascimento, char sexo, Proprietário proprietário, int código)
    // public Proprietário(String nome, String cpf, Endereço endereço)
    private static void cadastrarProprietário() {
        inserirProprietário(new Proprietário("Eva", "111.111.111-11",
        new Endereço("Casa", "", "Moreninha", "Campo Gradne", "11111-111", 140)));
        
        inserirProprietário(new Proprietário("Carlos", "222.222.222-22",
        new Endereço("Casa", "", "Feira", "Campo Grande", "22222-222", 130)));
        
        inserirProprietário(new Proprietário("João", "333.333.333-33",
        new Endereço("Apartamento", "Bloco 2 numéro  45", "Weimar","Campo Grande", "33333-333", 150)));
        
        inserirProprietário(new Proprietário("Alfredo", "444.444.444-44",
        new Endereço("Apartamento", "Bloco 2 numéro  80", "Rua do lago","Campo Grande", "44444-444", 135)));
        
        inserirProprietário(new Proprietário("Luis", "555.555.555-55",
        new Endereço("Casa", "", "Alencar", "Dourados", "55555-555", 120)));
        
        inserirProprietário(new Proprietário("Afonso", "666.666.666-66",
        new Endereço("Casa", "", "Rua dos reis", "Dourados", "66666-666", 650)));
        
        inserirProprietário(new Proprietário("Sofia", "777.777.777-77",
        new Endereço("Casa", "", "Vieira", "Dourados", "77777-777", 680)));
        
        inserirProprietário(new Proprietário("Alison", "888.888.888-88",
        new Endereço("Casa", "", "Rua São Paulo", "Dourados", "88888-888", 790)));
        
        inserirProprietário(new Proprietário("Miguel", "999.999.999-99",
        new Endereço("Casa", "", "Avenida Brasil", "Dourados", "99999-999", 890)));
        
        inserirProprietário(new Proprietário("Theo", "110.111.111-11",
        new Endereço("Casa", "", "Rua Quinze", "Dourados", "11110-111", 1050)));
        
        inserirProprietário(new Proprietário("Alice", "110.110.111-11",
        new Endereço("Casa", "", "Rua Quinze De Novembro", "Dourados", "10110-111", 1095)));
    }
    private static void inserirProprietário(Proprietário novo_proprietário) {
        String chave_proprietário = novo_proprietário.getCpf();
        //se proprietário não cadastrado então cadastra
        if(proprietários.get(chave_proprietário) == null) proprietários.put(chave_proprietário, novo_proprietário);
        else System.out.println("proprietário já cadastrado!");
    }
    
     private static void cadastrarAnimal() {
        inserirAnimal(new Animal("Lola", "vira lata", "branca",
        new Data(15, 5, 2011),'F',
         proprietários.get("111.111.111-11"), "001"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Lambe lambe", "vira lata", "branca",
        new Data(15, 5, 2011),'F',
         proprietários.get("111.111.111-11"), "002"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Velma", "vira lata", "caramelo",
        new Data(15, 5, 2011),'F',
         proprietários.get("222.222.222-22"), "003"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Acerola", "vira lata", "caramelo",
        new Data(15, 5, 2011),'F',
         proprietários.get( "333.333.333-33"), "004"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Tequila", "vira lata", "tigrado",
        new Data(15, 5, 2011),'F',
         proprietários.get( "444.444.444-44"), "005"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Nutella", "vira lata", "tigrado",
        new Data(15, 5, 2011),'F',
         proprietários.get("555.555.555-55"), "006"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Amendoim", "vira lata", "marrom",
        new Data(15, 5, 2011),'F',
         proprietários.get("666.666.666-66"), "007"));//proprietário fornecido pelo cpf;
       
        inserirAnimal(new Animal("Biscoito", "vira lata", "marrom",
        new Data(15, 5, 2011),'F',
         proprietários.get("777.777.777-77"), "008"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Amora", "vira lata", "preto",
    
        new Data(15, 5, 2011),'F',
         proprietários.get("888.888.888-88"), "009"));//proprietário fornecido pelo cpf;
        
        inserirAnimal(new Animal("Bacon", "vira lata", "preto",
        new Data(15, 5, 2011),'F',
         proprietários.get( "999.999.999-99"), "010"));//proprietário fornecido pelo cpf;
       
        inserirAnimal(new Animal("Batata", "vira lata", "branca",
        new Data(15, 5, 2011),'F',
         proprietários.get( "110.111.111-11"), "011"));//proprietário fornecido pelo cpf;
    }

    private static void inserirAnimal(Animal novo_animal) {
        String chave_animal  = novo_animal.getCódigo();
        if(animais.get(chave_animal) == null) animais.put(chave_animal, novo_animal);
        else System.out.println("Animal já cadastrado!");
    }
   // public Cirurgia(Anestesia anestesia, Hora hora_entrada, Hora hora_saida, boolean urgente, Hora tempo_internação)
    private static void cadastrarCirurgia() {
        inserirCirurgia(new Cirurgia(Anestesia.nenhuma,
                new Hora(7, 15), 
                new Hora(8, 0), false,
                new Hora(0, 45), "Geral", "001"));
        inserirCirurgia(new Cirurgia(Anestesia.nenhuma,
                new Hora(8, 15), 
                new Hora(9, 0), false,
                new Hora(0, 45), "Geral", "002"));
        inserirCirurgia(new Cirurgia(Anestesia.nenhuma,
                new Hora(9, 15), 
                new Hora(10, 0), true,
                new Hora(0, 45), "Geral", "003"));
        inserirCirurgia(new Cirurgia(Anestesia.geral,
                new Hora(11, 15), 
                new Hora(12, 0), false,
                new Hora(0, 45), "Ortopédica", "004"));
        inserirCirurgia(new Cirurgia(Anestesia.geral,
                new Hora(7, 15), 
                new Hora(8, 0), false,
                new Hora(0, 45), "Ortopédica", "005"));
        inserirCirurgia(new Cirurgia(Anestesia.geral,
                new Hora(7, 15), 
                new Hora(8, 0), false,
                new Hora(0, 45), "Oncológica", "006"));
        inserirCirurgia(new Cirurgia(Anestesia.geral,
                new Hora(7, 15), 
                new Hora(8, 0), true,
                new Hora(0, 45), "Oncológica", "007"));
        inserirCirurgia(new Cirurgia(Anestesia.inalatória,
                new Hora(15, 15), 
                new Hora(16, 0), true,
                new Hora(0, 45), "Oncológica", "008"));
        inserirCirurgia(new Cirurgia(Anestesia.inalatória,
                new Hora(18, 15), 
                new Hora(19, 0), true,
                new Hora(0, 45), "Neurocirurgia", "009"));
        inserirCirurgia(new Cirurgia(Anestesia.inalatória,
                new Hora(20, 15), 
                new Hora(21, 0), true,
                new Hora(0, 45), "Neurocirurgia", "010"));
        inserirCirurgia(new Cirurgia(Anestesia.injetável,
                new Hora(22, 15), 
                new Hora(23, 0), true,
                new Hora(0, 45), "Neurocirurgia", "011"));
        
    }
    private static void inserirCirurgia(Cirurgia nova_cirurgia) {
        String chave_cirurgia = nova_cirurgia.getCódigoDoAnimal();
        if(cirurgias.get(chave_cirurgia) == null) cirurgias.put(chave_cirurgia, nova_cirurgia);
        else System.out.println("Cirurgia já cadastrada!");
    }
    // public Agendamento(Data data_de_agendamento, Cirurgia cirurgia, Animal animal, Hora hora_do_agendamento) 
    private static void cadastrarAgendamento() {
       //mesmo dia
        inserirAgendamento(new Data(15, 5, 2021),"001", new Hora(7, 0));
       //mesmo dia
        inserirAgendamento(new Data(15, 5, 2021), "002", new Hora(8, 0));
       //mesmo dia
        inserirAgendamento(new Data(15, 5, 2021), "003", new Hora(9, 0));
       inserirAgendamento(new Data(16, 5, 2021), "004", new Hora(11, 0));
       
       inserirAgendamento(new Data(16, 5, 2021), "005", new Hora(7, 0));
       
       inserirAgendamento(new Data(17, 5, 2021), "006", new Hora(7, 0));
       
       inserirAgendamento(new Data(18, 5, 2021), "007", new Hora(7, 0));
       
       inserirAgendamento(new Data(19, 5, 2021), "008", new Hora(7, 0));
       
       inserirAgendamento(new Data(20, 5, 2021), "009", new Hora(7, 0));
       
       inserirAgendamento(new Data(21, 5, 2021), "010", new Hora(15, 0));
       
       inserirAgendamento(new Data(21, 5, 2021), "011", new Hora(18, 0));
       
    }
    private static void inserirAgendamento(Data data, String código_do_animal, Hora hora_do_agendamento) {
        Cirurgia cirurgia = cirurgias.get(código_do_animal);
         Animal animal = animais.get(código_do_animal);
          if(cirurgia == null){
             System.out.println("cirurgia não cadastrada");
             return;
          }
          if(animal == null){
            System.out.println("animal  não cadastrado");
            return;
          }
          agendamentos.add(new Agendamento(data, cirurgia, animal, hora_do_agendamento));
        }
   
        //imprime mensagem
    private static void imprimirAgendamentos(String cabeçalho, ArrayList<Agendamento> agendamentos) {
        int n = 1;
        System.out.println(cabeçalho);
        for (Agendamento agendamento : agendamentos) {
            System.out.println(n++ +" - " + agendamento );
            
        }
    }

    private static ArrayList<Agendamento> selecionarAgendas(Data data_agendada, String cidade_do_proprietário, char é_urgente) {
        ArrayList<Agendamento> agendas_selecionadas = new ArrayList();
        System.out.println("\nFiltros:"
        + "data agendada:" + data_agendada
        +" --cidade do proprietário:" + cidade_do_proprietário
        +" --urgencia:" + é_urgente
        );
        for (Agendamento agendamento : agendamentos) {
            Data data_do_agendamento = agendamento.getDataAgendada();
            String cidade = agendamento.getAnimal().getProprietário().getEndereço().getCidade();
            boolean com_urgencia = agendamento.getCirurgia().isUrgente();
            if((data_agendada != null) && (data_agendada.compareTo(data_do_agendamento) != 1)) continue;
            if((cidade_do_proprietário != null) && (!cidade_do_proprietário.equals(cidade)))continue;
            if((é_urgente == 'T') && (!com_urgencia)) continue;
            if((é_urgente == 'F') && com_urgencia)continue;
            agendas_selecionadas.add(agendamento);
            
        }
        return agendas_selecionadas;
    }


}
