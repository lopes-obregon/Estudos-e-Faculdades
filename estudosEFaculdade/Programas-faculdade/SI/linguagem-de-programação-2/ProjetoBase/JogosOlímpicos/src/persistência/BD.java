/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package persistência;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
/**
 *
 * @author renan
 */
public class BD {
    static final String URL_BD= "jdbc:mysql://localhost/jogosOlimpicos";
    static final String USUÁRIO = "root";
    static final String SENHA = "admin";
    public static Connection conexão = null;
    public static void criarConexeão(){
        try {
            conexão = DriverManager.getConnection(URL_BD, USUÁRIO, SENHA);
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
        }
    }
    public static void fechaConexão(){
        try {
            conexão.close();
        } catch (SQLException exceção_sql) {
            exceção_sql.printStackTrace();
        }
    }
}
