
package entidade;

import util.Data;

/**
 *
 * @author renan
 */
public class Animal{

   private String nome, raça, pelagem, cor_dos_pelos_do_animal;
   private Data data_nascimento;
   private  char sexo;//filtro
   private Proprietário proprietário;
    public Animal(String nome, String raça, String pelagem,String cor_dos_pelos_do_animal ,Data data_nascimento, char sexo, Proprietário proprietário) {
        this.nome = nome;
        this.raça = raça;
        this.pelagem = pelagem;
        this.data_nascimento = data_nascimento;
        this.sexo = sexo;
        this.proprietário = proprietário;
        this.cor_dos_pelos_do_animal = cor_dos_pelos_do_animal;
    }

    public Proprietário getProprietário(){
        return proprietário;
    }

   

    @Override
    public String toString() {
        String dados ="\nAnimal:\nNome: " + nome + "\tRaça: " + raça+ "\tCor: "+ cor_dos_pelos_do_animal +"\tIdade: "+ data_nascimento.calcularIdade()+"\n" + "Proprietário:" + proprietário;
        
        return dados;
    }

    
}
