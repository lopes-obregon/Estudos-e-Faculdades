
package entidade;

import interfaces.InterfaceTextual;
import java.io.Serializable;
import java.util.HashMap;
import util.Data;

/**
 *
 * @author renan
 */
public class Animal implements  Serializable{
    private static HashMap<String, Animal>  animais = new HashMap();
    public static  boolean addAnimal(Animal animal){
        String código_do_animal = animal.getCódigo();
        if(animais.get(código_do_animal) == null){
            animais.put(código_do_animal, animal);
            return true;
        }else{
            return false;
        }
    }
    public static void setAnimais(HashMap<String, Animal> animais){
        Animal.animais = animais;
    }
    public static Animal getAnimal(String código){
        return animais.get(código);
    }
    public static HashMap<String, Animal> getAnimais(){
        return animais;
    }
  
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
