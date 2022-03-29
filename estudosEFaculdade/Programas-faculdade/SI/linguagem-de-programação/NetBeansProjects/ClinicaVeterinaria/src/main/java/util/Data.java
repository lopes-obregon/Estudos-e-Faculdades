
package util;

import java.io.Serializable;
import java.util.Calendar;
import java.util.GregorianCalendar;

/**
 *
 * @author renan
 */
public class Data implements Serializable{

    public static Data toData(String data_string) {
        if(!data_string.matches("\\d{2}/\\d{2}/\\d{4}")){
            
            System.out.println("ERROR na conversão de data  da string :" + data_string);
            return null;
        } 
        String[] partes = data_string.split("/");
        return new Data(Integer.parseInt(partes[0]), Integer.parseInt(partes[1]), Integer.parseInt(partes[2]));
    }
    private int dia, mês, ano;


    public Data(int dia, int mês, int ano) {
        this.dia = dia;
        this.mês = mês;
        this.ano = ano;
    }
    @Override
    public String toString() {
        String data;
        if(dia < 10) data = "0" + dia;
        else data = ""+ dia;
        if(mês < 10)data += "/0" + mês+ "/";
        else data += "/"+mês+"/";
        return  data += ano;
    }
    public int compareTo(Data outra_data){
       
       
        if(dia >= outra_data.getDia())return  -1;
        if(dia < outra_data.getDia()) return  1;
        if(ano >= outra_data.getAno())return  -1;
        if(ano < outra_data.getAno()) return 1;
        if(mês >= outra_data.getMês())return -1;
        if(mês < outra_data.getMês()) return 1;
        return 0;
     
    }

    public int getAno() {
       return ano;
    }

    public int getMês() {
        return mês;
    }

    public int getDia() {
        return dia;
    }
    public int calcularIdade(){
        GregorianCalendar data_atualGregorianCalendar = new GregorianCalendar();
        int dia_atual = data_atualGregorianCalendar.get(Calendar.DAY_OF_MONTH);
        int mês_atual = data_atualGregorianCalendar.get(Calendar.MONTH) + 1;
        int ano_atual = data_atualGregorianCalendar.get(Calendar.YEAR) + 1;
        int idade = ano_atual - ano;
        if((mês_atual < mês) || (mês_atual == mês)&& (dia_atual < dia))idade --;
        return idade;
        
    }
}
