/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidade;

/**
 *
 * @author renan
 */
public class Funcionario {
    private String Nome, Cpf, Datanasc, Endereco;
    private char Sexo;
    private double Salario;
    private Departamento departamento;
 

    public Funcionario(String Nome, String Cpf, String Datanasc, String Endereco, char Sexo, double Salario) {
        this.Nome = Nome;
        this.Cpf = Cpf;
        this.Datanasc = Datanasc;
        this.Endereco = Endereco;
        this.Sexo = Sexo;
        this.Salario = Salario;
    }
    
       public String getNome() {
        return Nome;
    }

    public String getCpf() {
        return Cpf;
    }

    public String getDatanasc() {
        return Datanasc;
    }

    public String getEndereco() {
        return Endereco;
    }

    public char getSexo() {
        return Sexo;
    }

    public double getSalario() {
        return Salario;
    }

    public void setNome(String Nome) {
        this.Nome = Nome;
    }

    public void setCpf(String Cpf) {
        this.Cpf = Cpf;
    }

    public void setDatanasc(String Datanasc) {
        this.Datanasc = Datanasc;
    }

    public void setEndereco(String Endereco) {
        this.Endereco = Endereco;
    }

    public void setSexo(char Sexo) {
        this.Sexo = Sexo;
    }

    public void setSalario(double Salario) {
        this.Salario = Salario;
    }
    public Departamento getDepartamento(){
        return departamento;
    }
    public void setDepartamento(Departamento departamento){
        this.departamento = departamento;
    }
    public String toString(){
        return "Funcionario\nNome:" + Nome + "\tCpf:" + Cpf + "\tData de nascimento:" +Datanasc+"\t Endereco:" +Endereco+"\tSexo:" + Sexo + "\n"+ departamento; 
    }
          
}
