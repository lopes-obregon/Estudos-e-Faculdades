
package util;

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
    public int getHora(){
        return hora;
    }
    public int getMinuto(){
        return minuto;
    }
    public int compareTo(Hora outra_hora){
        if(hora >= outra_hora.getHora()) return -1;
        if(hora < outra_hora.getHora()) return 1;
        if(minuto >= outra_hora.getMinuto()) return -1;
        if(minuto < outra_hora.getMinuto()) return 1;
        return 0;
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
