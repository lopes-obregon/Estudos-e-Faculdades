/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal;

/**
 *
 * @author renan
 */
public class Principal {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
            Paciente pessoa1 = new Paciente(1.35, 60.0);
            Paciente pessoa2 = new Paciente(1.50, 75.0);
            Paciente pessoa3 = new Paciente(1.80, 85.0);
            System.out.println(pessoa1.diagnostico());
            //System.out.println(pessoa2.diagnostico());
            System.out.println(pessoa3.diagnostico());
    }
    
}