
package util;

import java.io.Serializable;

/**
 *
 * @author renan
 */
public class Endereço implements Serializable{

    public static Endereço toEndereço(String endereço_string) {
        //[a-z A-Z 0-9]+ -> aceita caracteres de a-z  e números espaço para considerar o espaço da string sem ele acaba considerando errado
        if(!endereço_string.matches("\\D+,[a-z A-Z 0-9]+,\\D+,\\D+,\\d{5}-\\d{3},\\d+")){
            System.out.println("ERROR na conversão do dado:" + endereço_string);
            return null;
        }
        String[] partes = endereço_string.split(",");
        return new Endereço(partes[0], partes[1], partes[2], partes[3], partes[4], Integer.parseInt(partes[5]));
    }
    private String logradouro, complemento, bairro, cidade, cep;

    private int número;

    public Endereço(String logradouro, String complemento, String bairro, String cidade, String cep, int número) {
        this.logradouro = logradouro;
        this.complemento = complemento;
        this.bairro = bairro;
        this.cidade = cidade;//filtro
        this.cep = cep;
        this.número = número;
    }
    public String getCidade(){
        return cidade;
    }
    @Override
    public String toString() {
        String dados  = "Logradouro: " + logradouro + "\tComplemento: " + complemento + "\tBairro: " + bairro + "\tCidade:" + cidade + "\tCep:" + cep+ "\tNúmero:"+ número;
        
        return dados;
    }

   
   
}