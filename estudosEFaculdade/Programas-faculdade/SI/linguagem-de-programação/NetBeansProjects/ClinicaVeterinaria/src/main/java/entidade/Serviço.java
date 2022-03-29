
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
