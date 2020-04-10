/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package estruturaderepeticao;

/**
 *
 * @author renan
 */
public class EstruturaDeRepeticao {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int count = 0;
        //while
        System.out.println("Com while");
        while(count < 10){
            count ++;
            if(count == 5 || count == 9){
                continue;
            }else{
                if(count == 3 || count == 2){
                    System.out.println("Saiu em " + count);
                    break;//sai de todo o laço.
                }
            }
            System.out.println("Salto: " +count);
        }
        System.out.println("Com repita");
        count = 0;
        do{
            count++;
            if(count%10 == 0){
                continue;
            }
            System.out.println("Salto: " + count);
        }while(count < 100);
        System.out.println("Com para");
        for (int i = 0; i < 10; i++) {
            if(i == 0){
                i = 1;
            }else{
                if(i == 9){
                    System.out.println("Salto: " + i);
                    i++;
                }
            }
            System.out.println("Salto : " + i);
        }
        System.out.println("Contando de 10 em 10");
        for (int i = 0; i < 100; i++) {
            if(i%10 == 0){
                System.out.println("Valor : " + i);
            }
        }
 
    }
}
