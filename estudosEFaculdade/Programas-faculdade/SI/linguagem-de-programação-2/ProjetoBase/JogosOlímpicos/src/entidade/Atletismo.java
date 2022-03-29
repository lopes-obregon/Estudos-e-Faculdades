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
    public static Atletismo buscarAtletismo(String modalidade){
        String sql = "SELECT * FROM Atletismo WHERE Modalidade = ?";
        ResultSet lista_resultados = null;
        Atletismo atletismo = null;
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, modalidade);
            lista_resultados = comando.executeQuery();
            while(lista_resultados.next()){
                atletismo = new Atletismo(modalidade, lista_resultados.getString("Distancia"));
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
        String sql = "INSERT INTO Atletismo(Modalidade, Distancia) VALUES (?,?)";
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, atletismo.getModalidade());
            comando.setString(2, atletismo.getDistância());
            comando.executeUpdate();
            comando.close();
            return null;
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
            return "Error na Inserção do Atletismo no BD";
        }
    }

    public static String alterarAtletismo(Atletismo atletismo) {
        String sql = "UPDATE Atletismo SET Distancia = ? WHERE Modalidade = ?";
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, atletismo.getDistância());
            comando.setString(2, atletismo.getModalidade());
            comando.executeUpdate();
            comando.close();
            return null;
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
            return "Erro na Alteração do Atletismo do BD";
        }
        
    }

    public static String removerAtletismo(String modalidade) {
        String sql = "DELETE FROM Atletismo WHERE Modalidade = ?";
        try {
            PreparedStatement comando = BD.conexão.prepareStatement(sql);
            comando.setString(1, modalidade);
            comando.executeUpdate();
            comando.close();
            return null;
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
            return "Erro na Remoção da Modalidade no BD";
            
        }
    }
    private String modalidade, distância;

    public Atletismo(String modalidade, String distância) {
        this.modalidade = modalidade;
        this.distância = distância;
    }

    public String getModalidade() {
       return modalidade;
    }

    public String getDistância() {
        return distância;
    }
}
