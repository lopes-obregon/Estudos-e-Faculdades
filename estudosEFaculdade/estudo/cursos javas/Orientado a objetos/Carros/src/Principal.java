/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author renan
 */
public class Principal {
    public static void main(String[] args) {
        Carros c1 = new Carros();
        c1.potencia = 10;
        c1.nome = "Corcel";
        c1.velocidade = 0;
        Carros c2 = new Carros();
        c2.potencia = 15;
        c2.nome = "Carango";
        c2.velocidade = 0;
        for (int i = 0; i < 3; i++) {
            c1.acelerar();
            if(i <= 1){
                c2.acelerar();
            }
        }
        c1.frear();
        c1.imprimir();
        c2.imprimir();
    }
}
