package controle;

import entidade.Disciplina;
import java.util.ArrayList;

/**
 *
 * @author renan
 */
public class CadastroDiciplina {
    static ArrayList<Disciplina> disciplina_cadastradas = new ArrayList();
    static ArrayList<Disciplina> disciplina_selecionadas = new ArrayList();
    public static void main(String[] args) {
        //Disciplina dis = new Disciplina("Programação", 72, 36, true);
        cadastroDisciplina();
        imprimeDisciplina("-----Disciplina Cadastradas----", disciplina_cadastradas);
        disciplina_selecionadas = selecionarDisciplina(36, 'F');
        imprimeDisciplina("\n----Discuplina Selecionadas---", disciplina_selecionadas);
    }

    private static void cadastroDisciplina() {
        disciplina_cadastradas.add(new Disciplina("Programação", 72, 36, true));
        disciplina_cadastradas.add(new Disciplina("Calculo 2", 36, 36, true));
        disciplina_cadastradas.add(new Disciplina("Administração", 120, 50, false));
        disciplina_cadastradas.add(new Disciplina("Processos de Empressas", 240, 120, false));


    }

    private static void imprimeDisciplina(String disciplina_Cadastradas, ArrayList<Disciplina> disciplina_selecionadas1) {
        System.out.println(disciplina_Cadastradas);
        for (Disciplina disciplina : disciplina_selecionadas1) {
            System.out.println(disciplina); 
        }
    }

    private static ArrayList<Disciplina> selecionarDisciplina(int carga_teórica_mínima, char reuni) {
        ArrayList<Disciplina> disciplina_selecionadas_com_filtro = new ArrayList();
        for (Disciplina disciplina : disciplina_cadastradas) {
            
            if((disciplina.getCarga_horária_total() - disciplina.getCarga_horária_prática()) < carga_teórica_mínima) continue;
            if((reuni == 'T') &&  !disciplina.isReuni()) continue;
            if((reuni == 'F') &&  disciplina.isReuni()) continue;
            disciplina_selecionadas_com_filtro.add(disciplina);
            
        }
        return disciplina_selecionadas_com_filtro;
    }
}
