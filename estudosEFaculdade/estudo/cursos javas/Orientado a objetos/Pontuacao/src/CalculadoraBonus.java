/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author renan
 */
public class CalculadoraBonus {
     public int bonusDoDia = 1;
     public int bonus(Usuario u){
         int multiplicador = bonusDoDia;
         if(u.vip){
            multiplicador = 5;
            return multiplicador;
         }
     }
}
