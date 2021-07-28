
package controle;

import entidade.Cirurgia;
import entidade.Cirurgia.tipoAnestesia;
import java.util.ArrayList;

/**
 *
 * @author renan
 */
public class ClinicaVeterinaria {
    static ArrayList<Cirurgia> paciente_cadastrados = new ArrayList();
    static ArrayList<Cirurgia> paciente_cadastrados_com_filtro;
    public static void main(String[] args) {
        cadastraPaciente();
        imprimePaciente("-----Paciente cadastrados-------", paciente_cadastrados);
        paciente_cadastrados_com_filtro = filtro(-1, 'x', -1,15);
        imprimePaciente("\n----Paciente Filtrados----", paciente_cadastrados_com_filtro);
    }
//Cirurgia(String nome_do_paciente, int idade_paciente, tipoAnestesia anestesia, int hora_entrada, int hora_saida) 
    private static void cadastraPaciente() {
        paciente_cadastrados.add(new Cirurgia("Sofia", 3, tipoAnestesia.inalatória, 12, 15, true));
        paciente_cadastrados.add(new Cirurgia("Morgana", 3, tipoAnestesia.inalatória, 12, 16, true));
        paciente_cadastrados.add(new Cirurgia("Lola", 3, tipoAnestesia.geral, 19, 20, true));
        paciente_cadastrados.add(new Cirurgia("Lambe coça", 2, tipoAnestesia.nada, 10, 15, false));
        paciente_cadastrados.add(new Cirurgia("Faisca", 1, tipoAnestesia.nada, 9, 10, false));
    }

    private static void imprimePaciente(String mensagem, ArrayList<Cirurgia> paciente_cadastrados0) {
        System.out.println(mensagem);
        int n = 0;
        for (Cirurgia paciente : paciente_cadastrados0) {
            System.out.println(++n +"-"+paciente);
        }
    }

    private static ArrayList<Cirurgia> filtro(int idade, char aplicou_anestesia, int hora_entrada, int hora_saida) {
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
    }

    
}
