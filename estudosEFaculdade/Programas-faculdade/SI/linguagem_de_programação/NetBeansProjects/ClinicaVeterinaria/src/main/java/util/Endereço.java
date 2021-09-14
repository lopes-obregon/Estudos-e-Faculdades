
package util;

/**
 *
 * @author renan
 */
public class Endereço {
    private String logradouro, complemento, bairro, cidade, cep;

    private int número;

    public Endereço(String logradouro, String complemento, String bairro, String cidade, String cep, int número) {
        this.logradouro = logradouro;
        this.complemento = complemento;
        this.bairro = bairro;
        this.cidade = cidade;
        this.cep = cep;
        this.número = número;
    }
    public String getCidade(){
        return cidade;
    }
    @Override
    public String toString() {
        String dados  = "Logradouro: " + logradouro + "\tComplemento: " + complemento + "\tBairro: " + bairro + "\tCidade:" + cidade + "\tCep:" + cep;
        
        return dados;
    }

   
   
}