/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidade;

/**
 *
 * @author renan
 */
import java.sql.ResultSet;
import java.sql.PreparedStatement;
import persistência.BD;
import java.sql.SQLException;
public class Atletismo {
    public static Atletismo buscarAtletismo(String id){
        String sql = "SELECT * FROM Atletismo WHERE Id = ?";
        ResultSet lista_resultados = null;
        Atletismo atletismo = null;
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, id);
            lista_resultados = comando.executeQuery();
            while(lista_resultados.next()){
                atletismo = new Atletismo(lista_resultados.getString("Modalidade"), lista_resultados.getString("Distancia"), id);
            }
            lista_resultados.close();
            comando.close();
            
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
            atletismo = null;
        }
        return atletismo;
    }
    public static String inserirAtletismo(Atletismo atletismo) {
        String sql = "INSERT INTO Atletismo(Id, Modalidade, Distancia) VALUES (?,?,?)";
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, atletismo.getId());
            comando.setString(2, atletismo.getModalidade());
            comando.setString(3, atletismo.getDistância());
            comando.executeUpdate();
            comando.close();
            return null;
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
            return "Error na Inserção do Atletismo no BD";
        }
    }

    public static String alterarAtletismo(Atletismo atletismo) {
        String sql = "UPDATE Atletismo SET Modalidade = ?, Distancia = ? WHERE Id = ?";
        try {
            
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, atletismo.getModalidade());
            comando.setString(2, atletismo.getDistância());
            comando.setString(3, atletismo.getId());
            comando.executeUpdate();
            comando.close();
            return null;
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
            return "Erro na Alteração do Atletismo do BD";
        }
        
    }

    public static String removerAtletismo(String id) {
        String sql = "DELETE FROM Atletismo WHERE Id = ?";
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, id);
            comando.executeUpdate();
            comando.close();
            return null;
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
            return "Erro na Remoção da Modalidade no BD";
            
        }
    }
    private String modalidade, distância, id;

    public Atletismo(String modalidade, String distância, String id) {
        this.modalidade = modalidade;
        this.distância = distância;
        this.id = id;
    }

    public String getModalidade() {
       return modalidade;
    }

    public String getDistância() {
        return distância;
    }
    public String getId(){
        return id;
    }
}
