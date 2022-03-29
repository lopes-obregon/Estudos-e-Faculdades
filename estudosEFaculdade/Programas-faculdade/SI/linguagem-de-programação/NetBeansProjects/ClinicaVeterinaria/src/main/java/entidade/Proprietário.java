
package entidade;

import interfaces.InterfaceTextual;
import java.util.HashMap;
import util.Endereço;

/**
 *
 * @author renan
 */
public class Proprietário {
    private String nome, cpf;
    private  Endereço endereço;
    public static Proprietário lerProprietário(){
        String nome_do_proprietário = InterfaceTextual.lerString(" o nome do proprietário");
        if(nome_do_proprietário == null) return null;
        
        String cpf_proprietário = InterfaceTextual.lerString(" o cpf do proprietário");
        if(cpf_proprietário == null) return null;
        
        Endereço endereço = InterfaceTextual.lerEndereço(" o endereço no formato");
        if(endereço == null) return null;
        
        return new Proprietário(nome_do_proprietário, cpf_proprietário, endereço);
    }
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
