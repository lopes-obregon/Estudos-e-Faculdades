/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidade;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import persistência.BD;

/**
 *
 * @author renan
 */
public class LocalCompetição {

    public static int últimoSequencial() {
        String sql = "SELECT MAX(Sequencial) FROM LocalCompeticao";
        ResultSet lista_resultados = null;
        int sequencial = 0;
        try {
            
        } catch (Exception e) {
        }
        
    }

    public void setSequencial(int sequencial) {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

    public Object getVisão() {
        throw new UnsupportedOperationException("Not supported yet."); // Generated from nbfs://nbhost/SystemFileSystem/Templates/Classes/Code/GeneratedMethodBody
    }

     public enum Esporte {atletismo, cerimônias, handebol, box, tênis_de_mesa, esgrima, badminton, caratê, judô, halterofilismo, futbool, outros}
    
    private int sequencial;
    private int capacidade;
    private String nome_da_arena;
    private Esporte esporte;
    private String endereço;
    public static LocalCompetição[] getVisões() {
        String sql = "SELECT Sequencial, Nome_da_arena FROM LocalCompeticao";
        ResultSet lista_de_resultados = null;
        ArrayList<LocalCompetição> visões = new ArrayList();
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            lista_de_resultados = comando.executeQuery();
            while(lista_de_resultados.next()){
                String sequencial = lista_de_resultados.getString("Sequencial");
                String nome_da_arena = lista_de_resultados.getString("Nome_da_arena");
                visões.add(new LocalCompetição(Integer.parseInt(sequencial), nome_da_arena));
            }
            lista_de_resultados.close();
            comando.close();
        } catch (SQLException exceção_sql) { 
            exceção_sql.printStackTrace();
        }
        return visões.toArray(new LocalCompetição[visões.size()]);
    }

    private LocalCompetição(int sequencial, String nome_da_arena) {
        this.sequencial = sequencial;
        this.nome_da_arena = nome_da_arena;
    }
   

    @Override
    public String toString() {
        return "[" + sequencial + "] " + nome_da_arena;
    }
    
}
