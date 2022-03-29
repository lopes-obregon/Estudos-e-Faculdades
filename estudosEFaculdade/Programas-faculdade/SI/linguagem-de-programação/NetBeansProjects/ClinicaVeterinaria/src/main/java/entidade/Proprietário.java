
package entidade;

import interfaces.InterfaceTextual;
import java.io.Serializable;
import java.util.HashMap;
import util.Endereço;

/**
 *
 * @author renan
 */
public class Proprietário  implements  Serializable{
    private String nome, cpf;
    private  Endereço endereço;
   
    public static HashMap<String, Proprietário> proprietários = new HashMap();
    public static boolean  addProprietário(Proprietário proprietário){
        String cpf = proprietário.getCpf();
        if(proprietários.get(cpf) == null){
            proprietários.put(cpf, proprietário);
            return true;
        }else{
            return false;
        }
    }
    public static void setProprietários(HashMap<String, Proprietário> proprietários){
        Proprietário.proprietários = proprietários;
    }
    public static HashMap<String, Proprietário> getProprietários(){
        return proprietários;
    }
    public static Proprietário getProprietário(String cpf){
        return proprietários.get(cpf);
    }
    public Proprietário(String nome, String cpf, Endereço endereço) {
        this.nome = nome;
        this.cpf = cpf;
        this.endereço = endereço;
    }
    public String getCpf(){
        return cpf;
    }
    public Endereço getEndereço(){
        return endereço;
    }
    @Override
    public String toString() {
        String dados = " \nNome:"+nome + "\tCpf:" + cpf +  "\nEndereço:\n" + endereço;
        return dados;
    }
    
}
