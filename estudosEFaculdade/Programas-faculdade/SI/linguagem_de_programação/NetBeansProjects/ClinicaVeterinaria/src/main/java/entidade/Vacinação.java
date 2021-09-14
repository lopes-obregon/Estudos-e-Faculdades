
package entidade;

import util.Data;

public class Vacinação extends Serviço {
    public enum Vacina{antirrábica, múltipla_ou_polivalente_v8_e_v10, contra_a_giardíase, contra_a_gripe, contra_a_leishmaniose}
    Vacina vacina;
    private Data data_da_vacina;//filtro

    public Vacinação(String código_do_animal, boolean urgente, Data data_da_vacina, Vacina vacina) {
        super(código_do_animal, urgente);
        this.data_da_vacina = data_da_vacina;
        this.vacina = vacina;
    }
    
}
