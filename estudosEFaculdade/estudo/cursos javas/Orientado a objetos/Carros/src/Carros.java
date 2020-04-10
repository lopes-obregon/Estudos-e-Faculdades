/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author renan
 */
public class Carros {
     //atributos
    int potencia;
    int velocidade;
    String nome;
    //métodos do carro
    void acelerar(){
        velocidade += potencia;
    }
    void frear(){
        velocidade /=2;
    }
    int getVelocidade(){
        return velocidade;
    }
    void imprimir(){
        System.out.println("O carro " + nome + " está a velocidade " + getVelocidade() + " km/h");
    }
}
