/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author renan
 */
public class RegistroPontos {
    private CalculadoraBonus bonus;
    public  RegistroPontos(CalculadoraBonus cb){
        bonus = cb;
    }
    public void fazerUmComentario(Usuario u){
        u.pontos +=3 * bonus.bonus(u);
    }
    public void criarUmTopico(Usuario u){
        u.pontos +=5;
    }
    public void darUmLike(Usuario u){
        u.pontos +=1;
    }
}
   
