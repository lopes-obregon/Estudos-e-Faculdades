/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaces;

import controle.ClinicaVeterinaria;
import entidade.Agendamento;
import entidade.Animal;
import entidade.Cirurgia;
import entidade.Cirurgia.Anestesia;
import entidade.Hospedagem;
import entidade.Proprietário;
import entidade.Serviço;
import entidade.Vacinação;
import entidade.Vacinação.Vacina;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import util.Data;
import util.Endereço;
import util.Hora;

/**
 *
 * @author renan
 */
public class InterfaceTextual {
    //método de leitura
    private static String lerString(String dado){
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        String string = "";
        System.out.println("-Informe " + dado + ":");;
        try {
            string  = entrada.readLine();
            if(string.isEmpty())return null;
        } catch (IOException exceção) {
            System.out.println("\n ERRO na leitura de: " + dado);
            return null;
        }
        return string;
    }
    //método que lê inteiro positivo
    private static int LerInteiroPositivo(String dado){
        String inteiro_positivo_string = lerString(dado);
        if(inteiro_positivo_string == null) return -1;
        int inteiro_positivo  = 0;
        try{
            inteiro_positivo = Integer.valueOf(inteiro_positivo_string).intValue();
        }catch (NumberFormatException exceção){
        System.out.println("-ERRO na conversão do dado: " + dado  +" para inteiro");
        return -1;   
        }
        if(inteiro_positivo > 0 ){
            return inteiro_positivo;
        }else{
            return -1;
        }
    }
    
    
    private static boolean lerBoolean(String dado){
        String  string_lido  = lerString(dado + "[S:sim]");
        if(string_lido == null) return false;
        if(string_lido.equalsIgnoreCase("S")) return true;
        return false;
    }
    private static char lerChar(String dado){
        String string = lerString(dado);
        if((string == null ) || (string.length() != 1))return 'X';
        return string.charAt(0);//retorna o caractere somente se estiver tamanho 1;
    }
    private static Data lerData(String dado){
        String data_string = lerString(dado + "[dd/mm/aa]");
        if (data_string == null) return null;
        return Data.toData(data_string);
    }
    private static Hora lerHora(String dado){
        String hora_string = lerString(dado + "[hh:mm]");
        if(hora_string == null) return null;
        return Hora.toHora(hora_string);
    }
    private static Endereço lerEndereço(String dado){
//String logradouro, String complemento, String bairro, String cidade, String cep, int númer 
        String endereço_string = lerString(dado + "[Logradouro,Complemento,Bairro,Cidade,Cep,Número]");
        if(endereço_string == null) return null;
        return Endereço.toEndereço(endereço_string);
    }
    private static Anestesia lerAnestesia(){
        // public enum Anestesia{geral, inalatória, injetável, local, nenhuma};
        String anestesia_string = lerString(" Anestesia G:Geral - I:Inalatória - IJ:Injetável - N:Nenhuma");
        if(anestesia_string == null) return null;
        if(anestesia_string.equalsIgnoreCase("G")) return Anestesia.geral;
        if(anestesia_string.equalsIgnoreCase("I")) return Anestesia.inalatória;
        if(anestesia_string.equalsIgnoreCase("IJ")) return Anestesia.injetável;
        if(anestesia_string.equalsIgnoreCase("N")) return Anestesia.nenhuma;
        else return null;
    }
    private static Vacina lerVacina(){
//Vacina{antirrábica, múltipla_ou_polivalente_v8_e_v10, contra_a_giardíase, contra_a_gripe, contra_a_leishmaniose}
        String vacina_string = lerString("A:Antirrábica - M:Múltipla ou polivalente v8 e v10 - C:Contra a giardíase - CG:Contra a gripe - CL:Contra a leishmaniose");
        if(vacina_string == null) return null;
        if(vacina_string.equalsIgnoreCase("A")) return Vacina.antirrábica;
        if(vacina_string.equalsIgnoreCase("M")) return Vacina.múltipla_ou_polivalente_v8_e_v10;
        if(vacina_string.equalsIgnoreCase("C")) return Vacina.contra_a_giardíase;
        if(vacina_string.equalsIgnoreCase("CG")) return Vacina.contra_a_gripe;
        if(vacina_string.equalsIgnoreCase("CL")) return Vacina.contra_a_leishmaniose;
        else return null;
    }
     private static Serviço lerServiço(){
        String tipo_do_serviço = lerString("C:Cirurgia - H:Hospedagem - V:Vacinação");
        if(tipo_do_serviço == null) return null;
        if(tipo_do_serviço.equalsIgnoreCase("C")){
//public Cirurgia(Anestesia anestesia, Hora hora_entrada, Hora hora_saida, String tipo_de_cirurgia, boolean urgente, String código_do_serviço) {
            Anestesia anestesia = lerAnestesia();
            if(anestesia == null) return null;
            
            Hora hora_de_entrada = lerHora("Hora  de entrada no formato");
            if(hora_de_entrada == null) return null;
            
            Hora hora_de_saida = lerHora("Hora  de saida no formato");
            if(hora_de_saida == null) return null;
            
            String tipo_de_cirurgia = lerString("qual tipo de cirurgia a ser realizada");
            if(tipo_de_cirurgia == null) return null;
            
            boolean é_urgente = lerBoolean("é urgente?");
            String código_do_serviço = lerString(" código do serviço [C00]");
            if(código_do_serviço == null) return null;
            
            return new Cirurgia(anestesia, hora_de_entrada, hora_de_saida, tipo_de_cirurgia, é_urgente, código_do_serviço);
        }
        if(tipo_do_serviço.equalsIgnoreCase("H")){
//Hospedagem(Data data_de_entrada, Data data_de_saida, boolean urgente, String código_do_serviço )  
            Data data_de_entrada = lerData(" data de entrada na hospedagem");
            if(data_de_entrada == null)return null;
            
            Data data_de_saída = lerData(" data de saída da hospedagem");
            if(data_de_saída == null)return null;
            
            boolean entrada_urgente = lerBoolean(" se entrada é urgente");
            String código_do_serviço = lerString(" o código do serviço [C00]");
            if(código_do_serviço == null) return null;
            
            return new Hospedagem(data_de_entrada, data_de_saída, entrada_urgente, código_do_serviço);
        }
        if(tipo_do_serviço.equalsIgnoreCase("V")){
//Vacinação( Data data_da_vacina, Vacina vacina, boolean urgente, String código_do_serviço)            
            Data data_da_vacina = lerData(" a data da vacina");
            if(data_da_vacina == null) return null;
            
            Vacina vacina = InterfaceTextual.lerVacina();
            if(vacina == null) return null;
            
            boolean é_vacina_urgente = lerBoolean(" se a vacina é urgente");
            String código_do_serviço = lerString(" o código do serviço [C00]");
            if(código_do_serviço == null) return null;
            return new Vacinação(data_da_vacina, vacina, é_vacina_urgente, código_do_serviço);
        }
        return null;
    }
    public static void loopleituraServiço(){
        boolean para_cadastrar = false;
        System.out.println("--- Leitura de Dados  de Serviço");
        while(!para_cadastrar){
            Serviço  serviço = lerServiço();
            if(serviço != null){
                boolean sucesso = Serviço.add(serviço);
                if(!sucesso) System.out.println("Já existe serviço com caracteristicas iguais");
                
            }else{
                System.out.println("- ERROR  na leitura do serviço");
            }
            para_cadastrar = lerBoolean("parar de cadastrar");
        }
    }
     private static Proprietário lerProprietário(){
        String nome_do_proprietário = lerString(" o nome do proprietário");
        if(nome_do_proprietário == null) return null;
        
        String cpf_proprietário = lerString(" o cpf do proprietário");
        if(cpf_proprietário == null) return null;
        
        Endereço endereço = lerEndereço(" o endereço no formato");
        if(endereço == null) return null;
        
        return new Proprietário(nome_do_proprietário, cpf_proprietário, endereço);
    }
    public static void loopleituraProprietário(){
        boolean para_cadastrar = false;
        System.out.println("--- Leitura de Dados  de Proprietário");
        while(!para_cadastrar){
            Proprietário  proprietário = lerProprietário();
            if(proprietário != null){
                boolean sucesso = Proprietário.addProprietário(proprietário);
                if(!sucesso) System.out.println("Já existe proprietário com caracteristicas iguais");
                
            }else{
                System.out.println("- ERROR  na leitura do Proprietário");
            }
            para_cadastrar = lerBoolean("parar de cadastrar");
        }
      
    }
     private static Animal lerAnimal(){
       String nome_string = lerString("Nome do animal");
       if(nome_string == null) return null;
       
       String raça = lerString("Raça do animal");
       if(raça == null) return null;
       
       String pelagem = lerString("Tipo do pelo do animal");
       if(pelagem == null) return null;
       
       String cor = lerString("Cor dos pelos do animal");
       if(cor == null) return null;
       
       Data data_nascimento = lerData("data de nascimento no formato");
       if(data_nascimento == null)return null;
       
       char sexo = lerChar(" o sexo do animal");
       String cpf_proprietário = InterfaceTextual.lerString("Cpf do proprietário");
       if(cpf_proprietário == null) return null;
       
       Proprietário  proprietário = Proprietário.getProprietário(cpf_proprietário);
       if(proprietário == null){
           System.out.println("ERROR não existe proprietário com esse cpf");
           return null;
       }
       String código_do_animal = lerString("código do animal formato [A00]");
       if(código_do_animal == null) return null;
       
       return new Animal(nome_string, raça, pelagem, cor, data_nascimento, sexo, proprietário, código_do_animal);
   } 
     public static void loopleituraAnimal(){
        boolean para_cadastrar = false;
        System.out.println("--- Leitura de Dados  de Animal");
        while(!para_cadastrar){

            Animal animal = lerAnimal();
            if(animal != null){

                boolean sucesso = Animal.addAnimal(animal);
                if(!sucesso) System.out.println("Já existe animal com caracteristicas iguais");

            }else{
                System.out.println("- ERROR  na leitura do Animal");
            }
            para_cadastrar = lerBoolean("para de cadastrar");
            }
        }
      private static Agendamento lerAgendamento(){
        Data data_agendada = lerData("Entre com uma  data no formato");
        if(data_agendada == null) return null;
        
        Hora hora_agendada = lerHora("Hora do agendamento no formato ");
        if(hora_agendada == null) return null;
        
        String código_do_serviço = lerString("Entre com o código do serviço");
        Serviço serviço_realizado = Serviço.getServiço(código_do_serviço);
        if(serviço_realizado == null) return null;
        
        String código_do_animal = lerString("Entre com o código do animal");
        Animal animal  =  Animal.getAnimal(código_do_animal);
        if(animal == null) return null;
        return new Agendamento(código_do_animal, data_agendada, hora_agendada, serviço_realizado, animal);
    }
       public static void loopleituraAgendamento(){
            boolean para_cadastrar = false;
            System.out.println("--- Leitura de Dados  de Agendamento");
            while(!para_cadastrar){
                Agendamento agendamento = lerAgendamento();
                
                if(agendamento != null){

                    boolean sucesso = Agendamento.addAgendamento(agendamento);
                    if(!sucesso) System.out.println("Já existe Agendamento com  alguma caracteristica igual caracteristicas iguais");

                }else{
                    System.out.println("- ERROR  na leitura do Agendamento");
                }
                para_cadastrar = lerBoolean("para de cadastrar");
            }
        }
       public static void loopOpçãoExecução(){
           int opção = 0;
           while(opção != -1){
               System.out.println("1:cadastrar proprietário \t2:cadastrar animal \t3:cadastrar serviço \t4:cadastrar agendamento \t5:selecionar agendamentos");
               opção = LerInteiroPositivo("opção de execução");
               switch(opção){
                   case 1:
                       loopleituraProprietário();
                       imprimirObjetos("Proprietários cadastrados", Proprietário.getProprietários().values());
                      break;
                   case 2:
                       loopleituraAnimal();
                       imprimirObjetos("Animais cadastrados", Animal.getAnimais().values());
                       break;
                   case 3:
                       loopleituraServiço();
                       imprimirObjetos("Serviços cadastrados", Serviço.getServiços().values());
                       break;
                   case 4:
                        loopleituraAgendamento();
                        imprimirObjetos("Agendamentos cadastrados ", Agendamento.getAgendamentos());
                        break;
                   case 5:
                       imprimirObjetos("Agendamentos selecionados", selecionarAgendamentos());
                       break;
               }
           }
       }

    private static void imprimirObjetos(String cabeçalho, Collection objetos) {
        int n = 0;
        if(objetos.isEmpty()) return;
        System.out.println(cabeçalho);
        for(Object objeto: objetos){
            n = n +1;
            System.out.println(n +" - "+objeto);
        }
        System.out.println();
    }
               
    private static ArrayList<Agendamento>selecionarAgendamentos(){
        System.out.println("--- Leitura de Filtros de Seleção de Agendamentos");
        String cidade_do_proprietário = lerString("Cidade do proprietário");
        Vacina vacina_aplicada = lerVacina();
        Data data_mínima_de_hospedagem = lerData("Ente com a data no formato");
        Anestesia anestesia_aplicada = lerAnestesia();
        Hora hora_mínima_agendada = lerHora("Ente com a hora no formato");
        int idade_mínima_do_animal = LerInteiroPositivo("idade mínima do animal");
        char entrada_urgente = lerChar("Entra urgente [S:sim - N:não");
         System.out.println("Filtros de Obras:"
        + "\n - Cidade do proprietário:" + cidade_do_proprietário
        + "\n - vacina aplicada:" + vacina_aplicada
        + "\n - Data minima de hospedagem: " + data_mínima_de_hospedagem
        +"\n - Anestesia aplicada:" + anestesia_aplicada
        + "\n - Hora  mínima agendada: " + hora_mínima_agendada
        + "\n - Idade mínima  do animal: " + idade_mínima_do_animal
        + "\n - Entrada urgente: " + entrada_urgente
        + "\n");
        return ClinicaVeterinaria.selecionarAgendamentos(cidade_do_proprietário, vacina_aplicada, data_mínima_de_hospedagem, anestesia_aplicada, hora_mínima_agendada, idade_mínima_do_animal, entrada_urgente);
    }
       
}
