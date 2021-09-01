
package entidade;

/**
 *
 * @author renan
 */
public class Hora {
    private int hora, minuto;

    public Hora(int hora, int minuto) {
        this.hora = hora;
        this.minuto = minuto;
    }

    @Override
    public String toString() {
        String hora_formatada = "";
        if(hora < 10) hora_formatada += "0" + hora;
        else if(hora >= 10) hora_formatada += hora;
        if(minuto < 10) hora_formatada += ":0" + minuto;
        else if(minuto >= 10) hora_formatada += ":" + minuto;
        return hora_formatada;
    }
    
}
