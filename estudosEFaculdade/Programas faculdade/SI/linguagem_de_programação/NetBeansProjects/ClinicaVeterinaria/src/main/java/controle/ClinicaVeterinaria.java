
package controle;

import entidade.Cirurgia;
import entidade.Cirurgia.Anestesia;

import java.util.ArrayList;

/**
 *
 * @author renan
 */
public class ClinicaVeterinaria {
    static ArrayList<Cirurgia> cirurgia_cadastrados = new ArrayList();
    static ArrayList<Cirurgia> cirurgia_selecionadas = new ArrayList();
    public static void main(String[] args) {
        cadastrarCirurgia();
        imprime("-----Cirurgias Cadastradas-------", cirurgia_cadastrados);
        cirurgia_selecionadas = filtro(-1, 'x',null);
        imprime("\n----Cirurgias Filtradas----", cirurgia_selecionadas);
        cirurgia_selecionadas = filtro(2, 'x',null);
        imprime("\n----Cirurgias Filtradas----", cirurgia_selecionadas);
        cirurgia_selecionadas = filtro(2, 'T',Anestesia.local);
        imprime("\n----Cirurgias Filtradas----", cirurgia_selecionadas);
    }
// public Cirurgia(Anestesia anestesia, int hora_entrada, int hora_saida, boolean urgente, int tempo_internação)
    private static void cadastrarCirurgia() {
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.nem_uma,15, 16, false,1 ));
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.geral,7, 8, false,1 ));
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.geral,8, 9, false,1 ));
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.inalatória,10, 13, false,3 ));
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.inalatória,14, 17, true,3 ));
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.local,17, 19, true,2 ));
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.injetável,20, 0, true,4 ));
        cirurgia_cadastrados.add(new Cirurgia(Anestesia.local,6, 11, true,5 ));
       
    }

    private static void imprime(String mensagem, ArrayList<Cirurgia> lista_cirurgia) {
        System.out.println(mensagem);
        int n = 0;
        for (Cirurgia cirurgia : lista_cirurgia) {
            System.out.println(++n +"-"+cirurgia);
        }
// int tempo_minimo_de_internação  boolean urgente  anestesia
    }

    private static ArrayList<Cirurgia> filtro(int tempo_minimo_de_internação, char urgente, Anestesia anestesia) {
        ArrayList<Cirurgia> cirurgia_filtrado = new ArrayList();
        System.out.println("Tempo minimo de Internação:" + tempo_minimo_de_internação + " --Urgente:" +urgente+ " --Anestesia:"+ anestesia );
        for (Cirurgia cirurgia : cirurgia_cadastrados) {
            if((tempo_minimo_de_internação != -1) && (cirurgia.getTempo_internação() < tempo_minimo_de_internação)) continue;
            if((anestesia != null) && (anestesia != cirurgia.getAnestesia())) continue;
            if((urgente == 'T') && (!cirurgia.isUrgente())) continue;
            if((urgente == 'F') && (cirurgia.isUrgente()) ) continue;
            cirurgia_filtrado.add(cirurgia);
        }
        return cirurgia_filtrado;
    }

    
    

    
}
