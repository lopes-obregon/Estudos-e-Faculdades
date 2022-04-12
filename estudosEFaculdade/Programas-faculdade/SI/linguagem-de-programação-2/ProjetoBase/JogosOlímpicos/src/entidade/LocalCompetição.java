/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidade;

/**
 *
 * @author renan
 */
public class LocalCompetição {
    public enum Esporte {atletismo, cerimônias, handebol, box, tênis_de_mesa, esgrima, badminton, caratê, judô, halterofilismo, futbool, outros}
    
    private int sequencial;
    private int capacidade;
    private String nome_da_arena;
    private Esporte esporte;
    private String endereço;

    @Override
    public String toString() {
        return "[" + sequencial + "] " + nome_da_arena;
    }
    
}
