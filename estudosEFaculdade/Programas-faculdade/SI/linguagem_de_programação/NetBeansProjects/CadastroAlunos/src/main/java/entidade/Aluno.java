
package entidade;

/**
 *
 * @author renan
 */
public class Aluno {

    
    public enum EstadoCivil {solteiro, casado, separado, viúvo};
    private String nome;
    private int ano_nascimento;
    private char sexo;
    private boolean estrangeiro;
    private EstadoCivil estado_civil;
    public Aluno(String nome, int ano_nascimento, char sexo, EstadoCivil estado_civil, boolean estrangeiro){
        this.nome = nome;
        this.ano_nascimento = ano_nascimento;
        this.sexo = sexo;
        this.estrangeiro = estrangeiro;
        this.estado_civil = estado_civil;
    }
    public Aluno(){
      
    }
    
    public void setEsdatadoCivil(EstadoCivil estado_civil ){
        this.estado_civil = estado_civil;
    }
    public EstadoCivil getEstadiCivil(){
        return estado_civil;
    }
    public void setNome(String nome){
        this.nome = nome;
    }
    public String getNome(){
        return nome;
    }
    public void setAnoNascimento(int ano_nascimento){
        this.ano_nascimento = ano_nascimento;
    }
    public int getAnoNascimento(){
        return ano_nascimento;
    }
    public void setSexo(char sexo){
        this.sexo = sexo;
    }
    public char getSexo(){
        return sexo;
    }
    public void setEstrangeiro(boolean estrangeiro){
        this.estrangeiro = estrangeiro;
    }
    public boolean getEstrangeiro(){
        return estrangeiro;
    }
    @Override
    public String toString(){
        String dados_aluno;
        dados_aluno = "Nome:" + nome + " --Ano de nascimento:" + ano_nascimento + " --Sexo:" + toStringSexo() +" --Estado civil:" + toStringEstadoCivil() + " --Estrangeiro:"+ toStringEstrangeiro();
        return dados_aluno;
    }
    private String toStringEstrangeiro() {
        String sexo_string = toStringSexo();
        if(!estrangeiro) return "";
        if(sexo_string.equals("masculino")) return "estrangeiro";
        if(sexo_string.equals("feminino")) return "estrangeira";
        return "indefinido";
    }

    private String toStringEstadoCivil() {
        String sexo_string = toStringSexo();
        if(sexo_string.equals("nasculino")) return  estado_civil + "";
        if(sexo_string.equals("feminino")){
            switch(estado_civil){
                case solteiro: return "solteira";
                case casado: return "casada";
                case separado: return "separada";
                case viúvo: return "viúva";
                default:return "indefinido";
            }
        }
        return "indefinido";
    }

    private String toStringSexo() {
        if((sexo == 'M') || (sexo == 'm')) return "masculino";
        if((sexo == 'F') || (sexo == 'f')) return "feminino";
        return "indefinido";
    }
}
