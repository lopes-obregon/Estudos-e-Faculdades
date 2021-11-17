/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author renan
 */
public class InterfaceTextual {
    //método de leitura
    private static String lerString(String dado){
        BufferedReader entrada = new BufferedReader(new InputStreamReader(System.in));
        String string = "";
        System.out.println("-Informe" + dado + ":");;
        try {
            string  = entrada.readLine();
            if(string.isEmpty())return null;
        } catch (IOException exceção) {
            System.out.println("\n ERRO na leitura de: " + dado);
            return null;
        }
        return string;
    }
    //método que lê inteiro positivo
    private static int LerInteiroPositivo(string dado);
    
    public String serviço = lerString("Nome do serviço");
}
