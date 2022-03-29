
package entidade;

import java.util.HashMap;
import util.Data;

public class Vacinação extends Serviço {
    //parte do conjunto dos objetos
    public static HashMap<String, Vacinação> vacinações = new HashMap();
    
    public static boolean addVacinação(Vacinação vacinação){
        String código = vacinação.getChaveDoServiço();

        if(vacinações.get(código) == null){
            vacinações.put(código, vacinação);
            return true;
        }else return false;
    }
    public static Vacinação getVacinação(String código){
        return vacinações.get(código);
    }
    public static HashMap<String, Vacinação> getVacinações(){
        return vacinações;
    }
    
//parte dos métodos especifico de cada objeto
    public enum Vacina{antirrábica, múltipla_ou_polivalente_v8_e_v10, contra_a_giardíase, contra_a_gripe, contra_a_leishmaniose}
    Vacina vacina; //filtro
    private Data data_da_vacina;//filtro

    public Vacinação( Data data_da_vacina, Vacina vacina, boolean urgente, String código_do_serviço) {
        super(urgente, código_do_serviço);
        this.data_da_vacina = data_da_vacina;
        this.vacina = vacina;
    }
    public Vacina getVacina(){
        return vacina;
    }
    @Override
    public String toString() {
        //String dados = "\nVacina\n\tVacina:" + vacina + "\t Data da vacina:" + data_da_vacina + "\t Urgente:";
        String dados = "\nVacina"+"\tCódigo do serviço:"+super.getChaveDoServiço()+"\nVacina: ";
        if(vacina == Vacina.múltipla_ou_polivalente_v8_e_v10) dados += "múltipla ou polivalente v8 e v10";
        if(vacina == Vacina.contra_a_gripe) dados += "contra a giardíase";
        if(vacina == Vacina.contra_a_leishmaniose) dados += "contra a leishmaniose";
        if(vacina == Vacina.contra_a_giardíase) dados += "contra a giardíase";
        else dados += vacina;
        dados += "\t Data da vacina:" + data_da_vacina + "\t Entrada urgente:";
        if(super.isUrgente() == true) dados += "True";
        else dados += "False";
        return dados;
    }
    
}
