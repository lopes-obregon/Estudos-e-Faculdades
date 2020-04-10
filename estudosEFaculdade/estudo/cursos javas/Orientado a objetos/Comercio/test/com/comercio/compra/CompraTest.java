/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.comercio.compra;


import static org.junit.Assert.*;
import org.junit.Test;

/**
 *
 * @author renan
 */
public class CompraTest {
    @Test
    public  void compraAvista() {
        Compra c = new Compra(500);
        asserEquals(1, c.getNumeroParcelas());
        assertEquals(500, c.getValorTotal());
        assertEquals(500, c.getValorParcela());
        Assert.
    }

    private void asserEquals(int i, int numeroParcelas) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    
}
