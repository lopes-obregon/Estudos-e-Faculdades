/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidade;

/**
 *
 * @author renan
 */
public class Departamento {

    private String Dnome, Cpf_gerente, Data_inicio_gerente;
    private int Dnúmero;

    public Departamento(String Dnome, String Cpf_gerente, String Data_inicio_gerente, int Dnúmero) {
        this.Dnome = Dnome;
        this.Cpf_gerente = Cpf_gerente;
        this.Data_inicio_gerente = Data_inicio_gerente;
        this.Dnúmero = Dnúmero;
    }

    public void setDnome(String Dnome) {
        this.Dnome = Dnome;
    }

    public void setCpf_gerente(String Cpf_gerente) {
        this.Cpf_gerente = Cpf_gerente;
    }

    public void setData_inicio_gerente(String Data_inicio_gerente) {
        this.Data_inicio_gerente = Data_inicio_gerente;
    }

    public void setDnúmero(int Dnúmero) {
        this.Dnúmero = Dnúmero;
    }
    public String getDnome() {
        return Dnome;
    }

    public String getCpf_gerente() {
        return Cpf_gerente;
    }

    public String getData_inicio_gerente() {
        return Data_inicio_gerente;
    }

    public int getDnúmero() {
        return Dnúmero;
    }
    public String toString(){
        return "Departamento\n Nome do departamento:"+Dnome+"\tDepartamento número:"+Dnúmero+ "\tCpf gerente:"+Cpf_gerente+"\tData inicio gerente:"+Data_inicio_gerente;
    }
}
