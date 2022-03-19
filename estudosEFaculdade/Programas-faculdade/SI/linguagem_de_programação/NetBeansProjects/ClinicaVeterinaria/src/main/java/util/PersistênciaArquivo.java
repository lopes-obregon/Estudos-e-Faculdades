/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package util;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

/**
 *
 * @author renan
 */
public class PersistênciaArquivo {
    //salva o arquivo
    public static void salvar(Object objeto_raiz, String arquivo){
        if(objeto_raiz == null)return;
        try{
            
            ObjectOutputStream saída = new ObjectOutputStream(new FileOutputStream( arquivo));
            saída.writeObject(objeto_raiz);
            saída.close();
        }catch(Exception exceção){
            System.out.println("Falha ao salvar no arquivo:" + arquivo + "\n");
            
        }
    }
    //recupera os dados salvo no arquivo
    public static Object recuperar(String arquivo){
        try {
            ObjectInputStream entrada = new ObjectInputStream(new FileInputStream(arquivo));
            Object objeto_raiz = entrada.readObject();
            return objeto_raiz;
        } catch (Exception exceção) {
            System.out.println("Falha na recuperação do arquivo:" + arquivo + "\n");
            
            return null;
        }
    }
}
