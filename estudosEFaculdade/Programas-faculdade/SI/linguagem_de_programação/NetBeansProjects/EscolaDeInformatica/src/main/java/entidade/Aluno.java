
package entidade;

/**
 *
 * @author renan
 */
public class Aluno {
    private String nome, rg, cpf;

    private Data data_nascimento;
    private char sexo;
    private Endereço endereço;


    public Aluno(String nome, String rg, String cpf, Data data_nascimento, char sexo, Endereço endereço) {
        this.nome = nome;
        this.rg = rg;
        this.cpf = cpf;
        this.data_nascimento = data_nascimento;
        this.sexo = sexo;
        this.endereço = endereço;
    }
    
    public String getCpf() {
        return cpf;
    }
    public Endereço getEndereço() {
        return endereço;
    }
}

