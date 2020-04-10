/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package vetor;

import java.util.Arrays;

/**
 *
 * @author renan
 */
public class Vetor {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
       // int n[] = new int[4];
       /*int n[] = {3, 2, 8, 7, 5, 4};
        System.out.println("Tamanho vetor é " + n.length);
        for (int i = 0; i < n.length; i++) {
            System.out.println(n[i]);
        }
       String mes[] = {"Jan", "Fev", "Mar", "Abr", "Maio", "Jun", "Jul", "Ago", "Set", "Out", "Nov", "Dez"};
       int tot [] = {31, 29, 30, 31, 30, 31 , 30, 31, 30, 31, 30, 31};
        for (int i = 0; i < mes.length; i++) {
            System.out.println("O mês de" + mes[i] + " tem " + tot[i] + " ao todo");
            
        }*/
        int num[] = new int[20];
        Arrays.fill(num, 0);
        for(int valor: num){
            System.out.println(valor);
        }
        // ordena Arrays.sort(num);
       //int pos = Arrays.binarySearch(num,8);
        //System.out.println(pos);
       /*for(int valor: num){
            System.out.println(valor);
        } jova o valor do vetor dentro da variavel valor*/
        
    }
    
}
