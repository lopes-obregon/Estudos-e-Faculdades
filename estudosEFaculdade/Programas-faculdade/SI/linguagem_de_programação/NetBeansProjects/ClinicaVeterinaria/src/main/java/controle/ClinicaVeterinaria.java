
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
import entidade.Serviço;
import entidade.Vacinação;
import entidade.Vacinação.Vacina;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import util.PersistênciaArquivo;

/**
 *
 * @author renan
 */
public class ClinicaVeterinaria {
    //final ->constante
    public static final String arquivo = "dados/ClinicaVeterinária";
    //salva os dados da aplicação
    public static void salvarAplicação(){
        ArrayList objeto_raiz = new ArrayList();
        //adiciona ao objeto raiz os objetos dos serviçõs
        objeto_raiz.add(Cirurgia.getCirurgias());
        objeto_raiz.add(Hospedagem.getHospedagens());
        objeto_raiz.add(Vacinação.getVacinações());
        PersistênciaArquivo.salvar(objeto_raiz, arquivo);
    }
    //recupera os dados da aplicação
    public static void recuperarAplicação(){
        ArrayList objeto_raiz = (ArrayList) PersistênciaArquivo.recuperar(arquivo);
        if(objeto_raiz != null){
            Cirurgia.setCirurgias((HashMap<String, Cirurgia>)objeto_raiz.get(0));
            Hospedagem.setHospedagens((HashMap<String, Hospedagem>)objeto_raiz.get(1));
            Vacinação.setVacinações((HashMap<String, Vacinação>)objeto_raiz.get(2));
            
        }
    }
    public static ArrayList<Agendamento> agendamentos = new ArrayList();//ultimo cadastro
    public static HashMap<String, Proprietário> proprietários = new HashMap();//chave cpf
    public static HashMap<String, Animal> animais = new HashMap();//código sendo a chave
    public static HashMap<String, Serviço> serviços = new HashMap();//iniciais e código como chave 
    public static void main(String[] args) {
       cadastrarProprietário();
       cadastrarAnimal();
       cadastrarServiço();
        cadastrarAgendamento();
        imprimirAgendamentos("Agendamentos Cadastrados", agendamentos);
        agendamentos =  selecionarAgendamentos(null,null, null, null, null, -1, 'X' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendamentos("Dourados",null, null, null, null, -1, 'X' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendamentos("Dourados",Vacina.antirrábica, null, null ,null, -1, 'X' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendamentos("Dourados",Vacina.antirrábica, new Data(15, 4, 2021), null, null, -1, 'X' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendamentos("Dourados",Vacina.antirrábica, new Data(15, 4, 2021), Anestesia.local,null, -1, 'X' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendamentos("Dourados",Vacina.antirrábica, new Data(15, 4, 2021), Anestesia.local, new Hora(15,0), -1,'X' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendamentos("Dourados",Vacina.antirrábica, new Data(15, 4, 2021), Anestesia.local, new Hora(15,0), 8, 'X' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        agendamentos =  selecionarAgendamentos("Dourados",Vacina.antirrábica, new Data(15, 4, 2021), Anestesia.local,  new Hora(15,0), 8, 'T' );
        imprimirAgendamentos("Agendamentos selecionados", agendamentos);
        
    }
    //public Agendamento(Data data_de_agendamento,  Hora hora_do_agendamento, Serviço serviço, Animal animal) {
    private static void cadastrarAgendamento() {
       
        inserirAgendamento(new Data(5, 7, 2021)
        , new Hora(13, 14)
        , "C001", "001");
        
       
        inserirAgendamento(new Data(8, 7, 2021)
                , new Hora(13, 15)
                , "C002"
                , "002");
      
        inserirAgendamento(new Data(9, 7, 2021)
                , new Hora(14, 14)
                , "C003"
                , "003");
     
        inserirAgendamento(new Data(10, 7, 2021)
                , new Hora(15, 14)
                , "V001"
                , "004");
      
        inserirAgendamento(new Data(11, 7, 2021)
                , new Hora(16, 14)
                , "V002", "005");
     
        inserirAgendamento(new Data(12, 7, 2021)
                , new Hora(17, 14)
                , "V003"
                , "006");
      
        inserirAgendamento(new Data(13, 7, 2021)
                , new Hora(18, 14)
                , "H001"
                , "007");
      
        inserirAgendamento(new Data(14, 7, 2021)
                , new Hora(19,14)
                , "H002", "008");
      
        inserirAgendamento(new Data(15, 7, 2021)
                , new Hora(20, 14)
                , "H003", "009");
    }
    
    private static void cadastrarAnimal() {
        inserirAnimal(new Animal("Lola", "vira lata", "longo","branco"
        ,new Data(15, 8, 2013), 'F' ,proprietários.get("111.111.111-11"), "001"));//proprietário fornecido pelo cpf;
        
        inserirAnimal( new Animal("Banguela", "vira lata", "curto","preto, creme, bege, marrom"
        ,new Data(15, 8, 2013), 'M', proprietários.get("222.222.222-22"), "002"));
        
        inserirAnimal( new Animal("Bolinha", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'M', proprietários.get("333.333.333-33"), "003"));
        
        inserirAnimal(new Animal("Sorvete", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2014), 'M', proprietários.get("444.444.444-44"), "004"));
        
        inserirAnimal(new Animal("Faisca", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'M', proprietários.get("555.555.555-55"), "005"));
        
        inserirAnimal( new Animal("Fumaça", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2013), 'M', proprietários.get("666.666.666-66"), "006"));
        
        inserirAnimal( new Animal("Mel", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2015), 'F', proprietários.get("777.777.777-77"), "007"));
        
        inserirAnimal( new Animal("Nina", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2015), 'F', proprietários.get("888.888.888-88"), "008"));
        
        inserirAnimal(new Animal("Amora", "vira lata", "curto", "castanho"
        ,new Data(15, 8, 2015), 'F', proprietários.get("888.888.888-88"), "009"));
    }
    
    private static void imprimirAgendamentos(String cabeçalho, ArrayList<Agendamento> agendamentos) {
        int n = 1;
        System.out.println(cabeçalho);
        for (Agendamento agendamento : agendamentos) {
            System.out.println(n++ +" - " + agendamento);
            
        }
        System.out.println();
        
    }
    //cidade_do_proprietário ->proprietario, vacina_aplicada -> Vacina, data_minima -> Hospedagem, anestesia_aplicada-> Cirurgia, urgente -> serviço, hora_agendada ->Agendamento
    //falta agendamento e animal
    //agendamento hora_agendada
    //animal -> idade
    public  static  ArrayList<Agendamento> selecionarAgendamentos(String cidade_do_proprietário, Vacina vacina_aplicada ,Data data_mínima, Anestesia anestesia_aplicada , Hora hora_mínima_agendada, int idade_mínima_do_animal,char entrada_urgente ){
        ArrayList<Agendamento> agendamento_selecionados = new ArrayList();
      
        for (Agendamento agendamento : Agendamento.getAgendamentos()) {
            Serviço serviço = agendamento.getServiço();
            String cidade = agendamento.getAnimal().getProprietário().getEndereço().getCidade();
            Hora hora_agendada = agendamento.getHoraDoAgendamento();
            int idade_do_animal = agendamento.getAnimal().getDataNascimento().calcularIdade();
            if((idade_mínima_do_animal > -1) && (idade_do_animal < idade_mínima_do_animal) )continue;
            if((hora_mínima_agendada != null) && (hora_agendada.compareTo(hora_mínima_agendada) != -1))continue;
            if((cidade_do_proprietário != null) && (!cidade_do_proprietário.equals(cidade)))continue;
            if((entrada_urgente == 'T') && (!serviço.isUrgente()))continue;
            if((entrada_urgente == 'F') && (serviço.isUrgente()))continue;
            if(serviço instanceof Vacinação){
                Vacinação vacinação = (Vacinação) serviço;
                if((vacina_aplicada != null) &&(vacina_aplicada != vacinação.getVacina())) continue;
            }else if(serviço instanceof  Hospedagem){
                Hospedagem hospedagem = (Hospedagem) serviço;
                Data data_da_hospedagem = hospedagem.getDataDeEntrada();
                if((data_mínima != null) && (data_da_hospedagem.compareTo(data_mínima) != -1)) continue;
            }else if(serviço instanceof Cirurgia){
                Cirurgia cirurgia = (Cirurgia) serviço;
                if((anestesia_aplicada != null) && (anestesia_aplicada != cirurgia.getAnestesia()))continue;
            }
            
            agendamento_selecionados.add(agendamento);
        }
        return agendamento_selecionados;
    }
    private static void cadastrarProprietário() {
        inserirProprietário(new Proprietário("Eva", "111.111.111-11",
        new Endereço("Casa", "", "Moreninha", "Campo Gradne", "11111-111", 140)));
        
        inserirProprietário(new Proprietário("Carol",  "222.222.222-22"
        ,new Endereço("Casa", "", "Marcelino", "Dourados", "22222-222", 135)));
       
        inserirProprietário(new Proprietário("Alfredo",  "333.333.333-33"
        ,new Endereço("Casa", "", "Marcelino", "Dourados", "33333-333", 140)));
        
        inserirProprietário(new Proprietário("Marcelo",  "444.444.444-44"
        ,new Endereço("Casa", "", "Marcelino", "Dourados", "44444-444", 970)));
        
        inserirProprietário( new Proprietário("Ane",  "555.555.555-55"
        ,new Endereço("Casa", "", "Weimar", "Dourados", "55555-555", 130)));
        
        inserirProprietário( new Proprietário("izabel",  "666.666.666-66"
        ,new Endereço("Casa", "", "Torres", "Dourados", "66666-666", 235)));
        
        inserirProprietário(new Proprietário("izabel",  "777.777.777-77"
        ,new Endereço("Casa", "", "Torres", "Dourados", "77777-777", 235)));
        
        inserirProprietário(new Proprietário("Marcos",  "888.888.888-88"
        ,new Endereço("Casa", "", "Monte Alegre", "Dourados", "88888-888", 580)));
        
        inserirProprietário(new Proprietário("Vanessa", "999.999.999-99"
        , new Endereço("Casa", "", "Viscosa", "Dourados", "99999-999", 1580)));
        
        
    }
    private static void inserirProprietário(Proprietário novo_proprietário) {
        String chave_proprietário = novo_proprietário.getCpf();
        //se proprietário não cadastrado então cadastra
        if(proprietários.get(chave_proprietário) == null) proprietários.put(chave_proprietário, novo_proprietário);
        else System.out.println("proprietário já cadastrado!");

    }
    //public Animal(String nome, String raça, String pelagem,String cor_dos_pelos_do_animal ,Data data_nascimento, char sexo, Proprietário proprietário)
    
    private static void inserirAnimal(Animal novo_animal) {
        String chave_animal  = novo_animal.getCódigo();
        if(animais.get(chave_animal) == null) animais.put(chave_animal, novo_animal);
        else System.out.println("Animal já cadastrado!");
    }

    private static void cadastrarServiço() {
       
        inserirServiço(new Cirurgia(Anestesia.geral
                , new Hora(13, 20)
                , new Hora(14, 20)
                , "Geral"
                , false
                , "C001"));
      
        inserirServiço(new Cirurgia(Anestesia.geral
        , new Hora(13, 20)
        , new Hora(14, 20)
        , "Geral"
        ,true
        ,"C002"));
        
        inserirServiço(new Cirurgia(Anestesia.local
                , new Hora(13, 20)
                , new Hora(14, 20)
                , "Remoção de tumores"
                , true
                , "C003"));
       
        inserirServiço(new Vacinação(new Data(28,9, 2021)
                ,Vacina.antirrábica
                , false
                , "V001"));
        
       
        inserirServiço(new Vacinação(new Data(20,9, 2021)
        ,Vacina.antirrábica
        , true
        , "V002"));
     
        inserirServiço(new Vacinação(new Data(15, 9, 2021)
        ,Vacina.contra_a_giardíase
        , true
        ,"V003"));
     
        inserirServiço(new Hospedagem(new Data(14, 4, 2021)
        , new Data(18, 4, 2021)
        ,false
        ,"H001"));

        inserirServiço(new Hospedagem(new Data(15, 4, 2021)
        , new Data(19, 4, 2021)
        , false
        ,"H002"));
   
        inserirServiço(new Hospedagem(new Data(20, 6, 2021)
        ,new Data(26, 6, 2021)
        , false
        ,"H003"));
    }

    private static void inserirServiço(Serviço novo_serviço) {
        String chave_serviço = novo_serviço.getChaveDoServiço();
        if(serviços.get(chave_serviço) == null) serviços.put(chave_serviço, novo_serviço);
        else System.out.println("Serviço já registrado!");
    }

    private static void inserirAgendamento(Data data_agendada, Hora hora_agendada, String código_do_serviço, String código_do_animal) {
        //recupera o objeto
        Serviço serviço = serviços.get(código_do_serviço);
        Animal animal = animais.get(código_do_animal);
        if(serviço == null){
            System.out.println("Serviço não cadastrada");
            return;
        }
        if(animal == null){
            System.out.println("animal  não cadastrado");
            return;
        }
        agendamentos.add(new Agendamento(data_agendada, hora_agendada, serviço, animal));
    }
}
