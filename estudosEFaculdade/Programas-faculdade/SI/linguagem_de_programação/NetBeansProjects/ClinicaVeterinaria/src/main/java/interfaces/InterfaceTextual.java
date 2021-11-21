/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaces;

import controle.ClinicaVeterinaria;
import entidade.Agendamento;
import entidade.Animal;
import entidade.Cirurgia.Anestesia;
import entidade.Proprietário;
import entidade.Serviço;
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
    public static String lerString(String dado){
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        String string = "";
        System.out.println("-Informe" + dado + ":");;
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
    public static int LerInteiroPositivo(String dado){
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
    
    
    public static boolean lerBoolean(String dado){
        String  string_lido  = lerString(dado + "[S:sim]");
        if(string_lido == null) return false;
        if(string_lido.equalsIgnoreCase("S")) return true;
        return false;
    }
    public static char lerChar(String dado){
        String string = lerString(dado);
        if((string == null ) || (string.length() != 1))return 'X';
        return string.charAt(0);//retorna o caractere somente se estiver tamanho 1;
    }
    public static Data lerData(String dado){
        String data_string = lerString(dado + "[dd/mm/aa]");
        if (data_string == null) return null;
        return Data.toData(data_string);
    }
    public static Hora lerHora(String dado){
        String hora_string = lerString(dado + "[hh:mm]");
        if(hora_string == null) return null;
        return Hora.toHora(hora_string);
    }
    public static Endereço lerEndereço(String dado){
//String logradouro, String complemento, String bairro, String cidade, String cep, int númer 
        String endereço_string = lerString(dado + "[Logradouro,Complemento,Bairro,Cidade,Cep,Número]");
        if(endereço_string == null) return null;
        return Endereço.toEndereço(endereço_string);
    }
    public static Anestesia lerAnestesia(){
        // public enum Anestesia{geral, inalatória, injetável, local, nenhuma};
        String anestesia_string = lerString("G:Geral - I:Inalatória - IJ:Injetável - N:Nenhuma");
        if(anestesia_string == null) return null;
        if(anestesia_string.equalsIgnoreCase("G")) return Anestesia.geral;
        if(anestesia_string.equalsIgnoreCase("I")) return Anestesia.inalatória;
        if(anestesia_string.equalsIgnoreCase("IJ")) return Anestesia.injetável;
        if(anestesia_string.equalsIgnoreCase("N")) return Anestesia.nenhuma;
        else return null;
    }
    public static Vacina lerVacina(){
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
    public static void loopleituraServiço(){
        boolean para_cadastrar = false;
        System.out.println("--- Leitura de Dados  de Serviço");
        while(!para_cadastrar){
            Serviço  serviço = Serviço.lerServiço();
            if(serviço != null){
                boolean sucesso = Serviço.add(serviço);
                if(!sucesso) System.out.println("Já existe serviço com caracteristicas iguais");
                
            }else{
                System.out.println("- ERROR  na leitura do serviço");
            }
            para_cadastrar = lerBoolean("para de cadastrar");
        }
    }
    public static void loopleituraProprietário(){
        boolean para_cadastrar = false;
        System.out.println("--- Leitura de Dados  de Proprietário");
        while(!para_cadastrar){
            Proprietário  proprietário = Proprietário.lerProprietário();
            if(proprietário != null){
                boolean sucesso = Proprietário.addProprietário(proprietário);
                if(!sucesso) System.out.println("Já existe proprietário com caracteristicas iguais");
                
            }else{
                System.out.println("- ERROR  na leitura do Proprietário");
            }
            para_cadastrar = lerBoolean("parar de cadastrar");
        }
      
    }
      public static void loopleituraAnimal(){
            boolean para_cadastrar = false;
            System.out.println("--- Leitura de Dados  de Animal");
            while(!para_cadastrar){

                Animal animal = Animal.lerAnimal();
                if(animal != null){

                    boolean sucesso = Animal.addAnimal(animal);
                    if(!sucesso) System.out.println("Já existe animal com caracteristicas iguais");

                }else{
                    System.out.println("- ERROR  na leitura do Animal");
                }
                para_cadastrar = lerBoolean("para de cadastrar");
            }
        }
       public static void loopleituraAgendamento(){
            boolean para_cadastrar = false;
            System.out.println("--- Leitura de Dados  de Agendamento");
            while(!para_cadastrar){
                Agendamento agendamento = Agendamento.lerAgendamento();
                
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
               System.out.println("1:cadastrar proprietário \t2:cadastrar animal \t3:cadastrar serviço \t4:cadastrar agendamento");
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
               }
           }
       }

    private static void imprimirObjetos(String cabeçalho, Collection objetos) {
        if(objetos.isEmpty()) return;
        System.out.println(cabeçalho);
        for(Object objeto: objetos) System.out.println(objeto);
        System.out.println();
    }
               
    public static ArrayList<Agendamento>selecionarAgendamentos(){
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
