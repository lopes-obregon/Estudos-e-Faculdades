/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package entidade;

/**
 *
 * @author renan
 */
public class Serviço {
    protected String código_do_animal;
    protected boolean urgente;
    public Serviço(String código_do_animal, boolean urgente){
        this.código_do_animal = código_do_animal;
        this.urgente = urgente;
    }
    public String getCódigoDoAnimal(){
        return código_do_animal;
    }
    public boolean isUrgente(){
        return urgente;
    }
    @Override
    public String toString() {
        String dado = "\n Código do animal:" + código_do_animal;
        return dado;
    }
    
}
