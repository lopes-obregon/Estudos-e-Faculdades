
package entidade;

/**
 *
 * @author renan
 */
public class Proprietário {
    String nome, cpf;
    Endereço endereço;

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
        String dados = " \n--Nome:"+nome + " --Cpf:" + cpf +  "\nEndereço:\n" + endereço;
        return dados;
    }
    
}
