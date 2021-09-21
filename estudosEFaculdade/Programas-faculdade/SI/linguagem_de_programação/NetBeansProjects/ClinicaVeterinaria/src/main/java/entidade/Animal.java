
package entidade;

import util.Data;

/**
 *
 * @author renan
 */
public class Animal{

   private String nome, raça, pelagem, cor_dos_pelos_do_animal, código_do_animal;
   private Data data_nascimento;//filtro
   private  char sexo;
   private Proprietário proprietário;
  // código_do_animal chave
    public Animal(String nome, String raça, String pelagem,String cor_dos_pelos_do_animal ,Data data_nascimento, char sexo, Proprietário proprietário, String código_do_animal) {
        this.nome = nome;
        this.raça = raça;
        this.pelagem = pelagem;
        this.data_nascimento = data_nascimento;
        this.sexo = sexo;
        this.proprietário = proprietário;
        this.cor_dos_pelos_do_animal = cor_dos_pelos_do_animal;
        this.código_do_animal = código_do_animal;
    }

    public Proprietário getProprietário(){
        return proprietário;
    }
    public Data getDataNascimento(){
        return data_nascimento;
    }
   public String getCódigo(){
       return código_do_animal;
   }

    @Override
    public String toString() {
        String dados ="\nAnimal\t Código do animal: "+código_do_animal +"\nNome: " + nome + "\tRaça: " + raça+ "\tCor: "+ cor_dos_pelos_do_animal +"\tIdade: "+ data_nascimento.calcularIdade()+"\tSexo: "+ sexo+"\n" + "Proprietário:" + proprietário;
        
        return dados;
    }

    
}
