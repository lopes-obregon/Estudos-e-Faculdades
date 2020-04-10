/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.comercio.compra;

/**
 *
 * @author renan
 */
public class Compra {
    int valorTotal;
    int numeroParcelas;
    
    //construtor
    //a vista
    public Compra( int valor){
        valorTotal = valor;
        numeroParcelas = 1;
    }
    //construtor
    //parcelado
    public Compra(int qtdParcelas, int valorParcela){
        numeroParcelas = qtdParcelas;
        valorTotal = valorParcela * qtdParcelas; 
    }

    public int getValorTotal() {
        return valorTotal;
    }

    public int getNumeroParcelas() {
        return numeroParcelas;
    }
    public int getValorParcela(){
      return valorTotal/numeroParcelas;  
    }
}
