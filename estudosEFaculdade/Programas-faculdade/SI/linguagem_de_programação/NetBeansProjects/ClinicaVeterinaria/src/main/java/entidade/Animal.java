
package entidade;

/**
 *
 * @author renan
 */
public class Animal {

   private String nome, raça, pelagem;
   private Data data_nascimento;
   private  char sexo;//filtro
   Proprietário proprietário;
   private String código;//código de identificação
    public Animal(String nome, String raça, String pelagem, Data data_nascimento, char sexo, Proprietário proprietário, String código) {
        this.nome = nome;
        this.raça = raça;
        this.pelagem = pelagem;
        this.data_nascimento = data_nascimento;
        this.sexo = sexo;
        this.proprietário = proprietário;
        this.código = código;
    }

    public Proprietário getProprietário(){
        return proprietário;
    }

    public String getCódigo(){
        return código;
    }

    @Override
    public String toString() {
        String dados = " \n Código"+ código  +"--Nome:" + nome + " --Raça:" + raça+ " --Idade:"+ data_nascimento.calcularIdade()+"\n" + "Proprietário:" + proprietário;
        
        return dados;
    }

    
}
