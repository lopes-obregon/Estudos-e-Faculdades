
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
import interfaces.InterfaceTextual;


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
    public static final String arquivo = "dados/ClinicaVeterinária.bds";
    //salva os dados da aplicação
    public static void salvarAplicação(){
        ArrayList objeto_raiz = new ArrayList();
        //adiciona ao objeto raiz os objetos dos serviçõs
        objeto_raiz.add(Proprietário.getProprietários());
        objeto_raiz.add(Animal.getAnimais());
        objeto_raiz.add(Serviço.getServiços());
        objeto_raiz.add(Agendamento.getAgendamentos());
        PersistênciaArquivo.salvar(objeto_raiz, arquivo);
    }
    //recupera os dados da aplicação
    public static void recuperarAplicação(){
        ArrayList objeto_raiz = (ArrayList) PersistênciaArquivo.recuperar(arquivo);
        if(objeto_raiz != null){
            Proprietário.setProprietários((HashMap<String, Proprietário>) objeto_raiz.get(0));
            Animal.setAnimais((HashMap<String, Animal>) objeto_raiz.get(1));
           Serviço.setServiços((HashMap<String, Serviço>) objeto_raiz.get(2));
            Agendamento.setAgendamentos((ArrayList<Agendamento>) objeto_raiz.get(3));
            
        }
    }
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
   
    public static void main(String[] args) {
      recuperarAplicação();
      InterfaceTextual.loopOpçãoExecução();
      salvarAplicação();
        
        
    }
   
    
    
}
