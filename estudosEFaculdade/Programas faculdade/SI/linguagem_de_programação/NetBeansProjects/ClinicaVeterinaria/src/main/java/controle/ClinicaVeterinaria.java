
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
        imprime("-----Cirurgia Cadastrados-------", cirurgia_cadastrados);
        /*cirurgia_selecionadas = filtro(-1, 'x', -1,15);
        imprimePaciente("\n----Paciente Filtrados----", cirurgia_selecionadas);*/
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
    }

    /*private static ArrayList<Cirurgia> filtro(int idade, char aplicou_anestesia, int hora_entrada, int hora_saida) {
        ArrayList<Cirurgia> filtros = new ArrayList();

        for (Cirurgia paciente : paciente_cadastrados) {
            if((idade != -1) && (paciente.getIdadePaciente() < idade)) continue;
            if((hora_entrada != -1) &&(paciente.getHoraEntrada() < hora_entrada))continue;
            if((hora_saida != -1) && (paciente.getHoraSaida() < hora_saida) ) continue;
            if((aplicou_anestesia == 'T') && !paciente.isAplicouAnestesia())continue;
            if((aplicou_anestesia == 'F') && paciente.isAplicouAnestesia()) continue;
            filtros.add(paciente);
        }
        return filtros;
    }*/

    
}
