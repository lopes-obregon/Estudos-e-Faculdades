
package entidade;

/**
 *
 * @author renan
 */
public class Serviço {
    protected boolean urgente;//filtro
    protected  String chave_do_serviço; //chave
    public Serviço( boolean urgente, String chave_do_serviço){
        this.urgente = urgente;
        this.chave_do_serviço = chave_do_serviço;
    }
    public boolean isUrgente(){
        return urgente;
    }
    public String getChaveDoServiço(){
        return chave_do_serviço;
    }
    @Override
    public String toString() {
        String dados = "\n Urgente:" + isUrgente() + "Código ou chave do Serviço" + chave_do_serviço;
        return dados;
    }
    
}
