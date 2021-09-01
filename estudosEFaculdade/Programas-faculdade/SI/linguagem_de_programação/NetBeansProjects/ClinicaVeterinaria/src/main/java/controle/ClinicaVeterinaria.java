
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
    }
    //public Data(int dia, int mês, int ano)
    // public Cirurgia(Anestesia anestesia, Hora hora_entrada, Hora hora_saida, boolean urgente, Hora tempo_internação)
    //public Animal(String nome, String raça, String pelagem, Data data_nascimento, char sexo, Proprietário proprietário, int código)
    // public Proprietário(String nome, String cpf, Endereço endereço)
    private static void cadastrarProprietário() {
        inserirProprietário(new Proprietário("Eva", "111.111.111-11",
        new Endereço("Casa", "", "Moreninha", "Campo grande", "11111-111", 140)));
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
    }

    private static void inserirAnimal(Animal novo_animal) {
        String chave_animal  = novo_animal.getCódigo();
        if(animais.get(chave_animal) == null) animais.put(chave_animal, novo_animal);
        else System.out.println("Animal já cadastrado!");
    }
   
    private static void cadastrarCirurgia() {
        inserirCirurgia(new Cirurgia(Anestesia.nenhuma,
                new Hora(7, 15), 
                new Hora(8, 0), false,
                new Hora(0, 45), "Geral"));
    }
    private static void inserirCirurgia(Cirurgia nova_cirurgia) {
        String chave_cirurgia = nova_cirurgia.getNomeDoAnimal();
        if(cirurgias.get(chave_cirurgia) == null) cirurgias.put(chave_cirurgia, nova_cirurgia);
        else System.out.println("Cirurgia já cadastrada!");
    }
    // public Agendamento(Data data_de_agendamento, Cirurgia cirurgia, Animal animal, Hora hora_do_agendamento) 
    private static void cadastrarAgendamento() {
       inserirAgendamento(new Data(15, 5, 2021),
               "Geral", "001", new Hora(7, 0));
       
    }
    private static void inserirAgendamento(Data data, String tipo_de_cirurgia, String código_do_animal, Hora hora_do_agendamento) {
        Cirurgia cirurgia = cirurgias.get(tipo_de_cirurgia);
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


}
