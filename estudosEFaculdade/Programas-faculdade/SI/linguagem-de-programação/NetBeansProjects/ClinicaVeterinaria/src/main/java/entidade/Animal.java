
package entidade;

import interfaces.InterfaceTextual;
import java.util.HashMap;
import util.Data;

/**
 *
 * @author renan
 */
public class Animal{
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
    public static Animal getAnimal(String código){
        return animais.get(código);
    }
    public static HashMap<String, Animal> getAnimais(){
        return animais;
    }
   public static Animal lerAnimal(){
       String nome_string = InterfaceTextual.lerString("Nome do animal");
       if(nome_string == null) return null;
       
       String raça = InterfaceTextual.lerString("Raça do animal");
       if(raça == null) return null;
       
       String pelagem = InterfaceTextual.lerString("Tipo do pelo do animal");
       if(pelagem == null) return null;
       
       String cor = InterfaceTextual.lerString("Cor dos pelos do animal");
       if(cor == null) return null;
       
       Data data_nascimento = InterfaceTextual.lerData("Digite a data no formato");
       if(data_nascimento == null)return null;
       
       char sexo = InterfaceTextual.lerChar("Digite o sexo do animal");
       String cpf_proprietário = InterfaceTextual.lerString("Cpf do proprietário");
       if(cpf_proprietário == null) return null;
       
       Proprietário  proprietário = Proprietário.getProprietário(cpf_proprietário);
       if(proprietário == null){
           System.out.println("ERROR não existe proprietário com esse cpf");
           return null;
       }
       String código_do_animal = InterfaceTextual.lerString("código do animal formato [A00]");
       if(código_do_animal == null) return null;
       
       return new Animal(nome_string, raça, pelagem, cor, data_nascimento, sexo, proprietário, código_do_animal);
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
