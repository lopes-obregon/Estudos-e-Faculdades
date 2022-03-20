/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controle;

/**
 *
 * @author renan
 */
import com.db4o.Db4oEmbedded;
import com.db4o.ObjectContainer;
import com.db4o.ObjectSet;
import entidade.Departamento;
import entidade.Funcionario;
import java.util.HashMap;
import com.db4o.query.Query;

public class EmpresaControle {
    public static HashMap<String, Funcionario> funcionarios = new HashMap();
    public static HashMap<Integer, Departamento> departamentos = new HashMap();
    public static void main(String[] args) {
        ObjectContainer db = Db4oEmbedded.openFile("C:\\Users\\renan\\Documents\\GitHub\\Estudos-e-Faculdades\\estudosEFaculdade\\Programas-faculdade\\SI\\banco-de-dados-2/BD.yap");
        try {
            addFuncionarios();
            addDepartamento();
            funcionarios.get("743.213.132-44").setDepartamento(departamentos.get(1));
            funcionarios.get("232.546.744-85").setDepartamento(departamentos.get(1));
            funcionarios.get("464.134.763-25").setDepartamento(departamentos.get(2));
            funcionarios.get("653.749.798-15").setDepartamento(departamentos.get(2));
            funcionarios.get("891.436.876-46").setDepartamento(departamentos.get(3));
           //registra dados
            for(String i: funcionarios.keySet()){
               
               db.store(funcionarios.get(i));
           }
          
           Funcionario funcionario_recuperado = (Funcionario) recuperaFuncionario("464.134.763-25", db);
          
            funcionario_recuperado.setEndereco("Rua Hayel Bom Faker, 873");
            db.store(funcionario_recuperado);
            
            //deletando
            Funcionario funcionario_recuperado2 = (Funcionario) recuperaFuncionario("232.546.744-85", db);
            db.delete(funcionario_recuperado2); 
            //imprime o banco de dados
          // printBd(db);
          //reupera o departamento.
            Departamento departamento =  recuperaDepartamento("891.436.876-46", db);
            System.out.println(departamento);
          
        } finally {
            db.close();
        }
        
    }
    private static Departamento recuperaDepartamento(String cpf, ObjectContainer db){
        Query query = db.query();
        query.constrain(Funcionario.class);
        query.descend("Cpf").constrain(cpf);
        Funcionario funcionario = (Funcionario) query.execute().next();
        return (Departamento) funcionario.getDepartamento();
        
        
    }
    private static Funcionario recuperaFuncionario(String cpf, ObjectContainer db){
        Query query = db.query();
        query.constrain(Funcionario.class);
        query.descend("Cpf").constrain(cpf);
        return (Funcionario) query.execute().next();
        
    }

    private static void addFuncionarios() {
        
        criarFuncionario("Anderson Pereira", "743.213.132-44", "14/09/1970", "Rua Ponta Grossa, 421", 'M', 4500);
        criarFuncionario("Caroline Machado", "232.546.744-85", "23/11/1984", "Rua Cuiabá, 521", 'F', 3000);
        criarFuncionario("Fernando da Costa", "464.134.763-25", "17/04/1980", "Rua Mato Grosso, 2385", 'F', 8000);
        criarFuncionario("Milena Fernandes", "653.749.798-15", "08/07/1978", "Rua Iguaçu, 329", 'F', 6500);
        criarFuncionario("Renato Melo", "891.436.876-46", "29/03/1965", "Rua Ivinhema, 621", 'M', 5500);
        
    }

    private static void criarFuncionario(String nome, String cpf, String data_nasc, String endereço, char sexo, int salario) {
        Funcionario funcionario = new Funcionario(nome, cpf, data_nasc, endereço, sexo, salario);
        if(funcionarios.get(funcionario.getCpf()) == null){ 
            funcionarios.put(cpf, funcionario);
           
        }
        else System.out.println("Funcionario já cadastrado");
    }

    private static void addDepartamento() {
        criarDepartamento("Pesquisa", 1, "464.134.763.25", "24/03/2006");
        criarDepartamento("Financeiro", 2, "653.749.798-15", "17/07/2004");
        criarDepartamento("RH", 3, "891.436.876-46", "05/10/2009");
    }

    private static void criarDepartamento(String d_nome, int d_número, String cpf_gerente, String data_inicio_gerente) {
        Departamento departamento = new Departamento(d_nome,cpf_gerente , data_inicio_gerente, d_número);
        if(departamentos.get(departamento.getDnúmero()) == null){
            departamentos.put(departamento.getDnúmero(), departamento);
        }else{
            System.out.println("Departamento já existe");
        }
    }

    private static void printBd(ObjectContainer db) {
        ObjectSet<Funcionario> lista_funcionarios = db.queryByExample(Funcionario.class);
        while(lista_funcionarios.hasNext()){
            System.out.println(lista_funcionarios.next());
        }
    }
}
