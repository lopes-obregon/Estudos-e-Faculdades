
package entidade;

import util.Data;


public class Hospedagem extends Serviço{
    private Data data_de_entrada;
    private Data data_de_saida;
    private int tempo_de_hospedagem_em_dias;
    public Hospedagem(String código_do_animal, boolean urgente, Data data_de_entrada, Data data_de_saida ){
        super(código_do_animal, urgente);
        this.data_de_entrada = data_de_entrada;
        this.data_de_saida = data_de_saida;
    }

    @Override
    public String toString() {
        tempo_de_hospedagem_em_dias = data_de_saida.getDia() - data_de_entrada.getDia();
        String dado = "\nHospedagem\tCódigo do animal:"+super.getCódigoDoAnimal()+"\nTempo de hospedagem:";
        if(tempo_de_hospedagem_em_dias == 1) dado += tempo_de_hospedagem_em_dias + " dia";
        else
            dado += tempo_de_hospedagem_em_dias +" dias";
        dado += "\tData da entrada:"+ data_de_entrada + "\tData de saida:" + data_de_saida;
        return  dado;
    }
}
