
package entidade;

import util.Data;


public class Hospedagem extends Serviço{
    private Data data_de_entrada;//filtro
    private Data data_de_saida;
    private int tempo_de_hospedagem_em_dias;//filtro
    public Hospedagem(Data data_de_entrada, Data data_de_saida, boolean urgente, String código_do_serviço ){
        super(urgente, código_do_serviço);
        this.data_de_entrada = data_de_entrada;
        this.data_de_saida = data_de_saida;
    }
    public Data getDataDeEntrada(){
        return data_de_entrada;
    }
    @Override
    public String toString() {
        tempo_de_hospedagem_em_dias = data_de_saida.getDia() - data_de_entrada.getDia();
        String dados = "\nHospedagem"+"\tCódigo do serviço:"+super.getChaveDoServiço()+"\nTempo de hospedagem:";
        if(tempo_de_hospedagem_em_dias == 1) dados += tempo_de_hospedagem_em_dias + " dia";
        else
            dados += tempo_de_hospedagem_em_dias +" dias";
        dados += "\tData da entrada:"+ data_de_entrada + "\tData de saida:" + data_de_saida;
        if(super.isUrgente() == true) dados +="\t Entrada Urgente:True";
        else dados +="\t Entrada urgente:False";
        return  dados;
    }
}
