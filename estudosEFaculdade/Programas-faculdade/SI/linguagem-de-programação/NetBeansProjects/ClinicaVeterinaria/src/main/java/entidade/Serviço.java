
package entidade;

import entidade.Cirurgia.Anestesia;
import entidade.Vacinação.Vacina;
import java.io.Serializable;
import java.util.HashMap;
import interfaces.InterfaceTextual;
import util.Data;
import util.Hora;

/**
 *
 * @author renan
 */
public class Serviço implements Serializable {//para armazenar e recuperar objetos do arquivo
    // região estática : para manipular conjunto de objetos como dados globais
    private static HashMap<String, Serviço> serviços = new HashMap();
    
    public static boolean add(Serviço serviço){
        String chave = serviço.getChaveDoServiço();
        if(serviços.get(chave) == null){
            serviços.put(chave, serviço);
            return true;
        }else return false;
    }
    public static Serviço getServiço(String código){
        return serviços.get(código);
    }
    public static HashMap<String, Serviço> getServiços(){
        return serviços;
    }
    public static void setServiços(HashMap<String, Serviço> serviços){
        Serviço.serviços = serviços;
    }
    public static Serviço lerServiço(){
        String tipo_do_serviço = InterfaceTextual.lerString("C:Cirurgia - H:Hospedagem - V:Vacinação");
        if(tipo_do_serviço == null) return null;
        if(tipo_do_serviço.equalsIgnoreCase("C")){
//public Cirurgia(Anestesia anestesia, Hora hora_entrada, Hora hora_saida, String tipo_de_cirurgia, boolean urgente, String código_do_serviço) {
            Anestesia anestesia = InterfaceTextual.lerAnestesia();
            if(anestesia == null) return null;
            
            Hora hora_de_entrada = InterfaceTextual.lerHora("Hora formato");
            if(hora_de_entrada == null) return null;
            
            Hora hora_de_saida = InterfaceTextual.lerHora("Hora formato");
            if(hora_de_saida == null) return null;
            
            String tipo_de_cirurgia = InterfaceTextual.lerString("Digite qual tipo de cirurgia a ser realizada");
            if(tipo_de_cirurgia == null) return null;
            
            boolean é_urgente = InterfaceTextual.lerBoolean("é urgente?");
            String código_do_serviço = InterfaceTextual.lerString("Insira código do serviço [C00]");
            if(código_do_serviço == null) return null;
            
            return new Cirurgia(anestesia, hora_de_entrada, hora_de_saida, tipo_de_cirurgia, é_urgente, código_do_serviço);
        }
        if(tipo_do_serviço.equalsIgnoreCase("H")){
//Hospedagem(Data data_de_entrada, Data data_de_saida, boolean urgente, String código_do_serviço )  
            Data data_de_entrada = InterfaceTextual.lerData("Digite data de entrada na hospedagem");
            if(data_de_entrada == null)return null;
            
            Data data_de_saída = InterfaceTextual.lerData("Digite data de saída da hospedagem");
            if(data_de_saída == null)return null;
            
            boolean entrada_urgente = InterfaceTextual.lerBoolean("Digite se entrada é urgente");
            String código_do_serviço = InterfaceTextual.lerString("Digite o código do serviço [C00]");
            if(código_do_serviço == null) return null;
            
            return new Hospedagem(data_de_entrada, data_de_saída, entrada_urgente, código_do_serviço);
        }
        if(tipo_do_serviço.equalsIgnoreCase("V")){
//Vacinação( Data data_da_vacina, Vacina vacina, boolean urgente, String código_do_serviço)            
            Data data_da_vacina = InterfaceTextual.lerData("Digite a data da vacina");
            if(data_da_vacina == null) return null;
            
            Vacina vacina = InterfaceTextual.lerVacina();
            if(vacina == null) return null;
            
            boolean é_vacina_urgente = InterfaceTextual.lerBoolean("Digite se a vacina é urgente");
            String código_do_serviço = InterfaceTextual.lerString("Digite o código do serviço [C00]");
            if(código_do_serviço == null) return null;
            return new Vacinação(data_da_vacina, vacina, é_vacina_urgente, código_do_serviço);
        }
        return null;
    }
    // região orientada a objetos : para criar e manipular dados específicos de um dado objeto
    protected boolean urgente;//filtro
    protected  String chave_do_serviço; //chave
    public Serviço( boolean urgente, String chave_do_serviço){
        this.urgente = urgente;
        this.chave_do_serviço = chave_do_serviço;
    }
    public boolean isUrgente(){
        return urgente;
    }
    public String getChaveDoServiço(){
        return chave_do_serviço;
    }
    @Override
    public String toString() {
        String dados = "\n Urgente:" + isUrgente() + "Código ou chave do Serviço" + chave_do_serviço;
        return dados;
    }
    
}
