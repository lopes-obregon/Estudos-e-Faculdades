
package entidade;

import java.util.ArrayList;

/**
 *
 * @author renan
 */
public class Curso {

    private String título;
    private int carga_horária_semanal, duração_semanas;
    private ArrayList<Curso> pré_requisitos = new ArrayList();

    public Curso(String título, int carga_horária_semanal, int duração_semanas) {
        this.título = título;
        this.carga_horária_semanal = carga_horária_semanal;
        this.duração_semanas = duração_semanas;
    }
    public boolean inserirPréRequisito(Curso pré_requisito){
        boolean aux;
        if(!pré_requisitos.contains(pré_requisito)){
            pré_requisitos.add(pré_requisito);
            aux = true;
        }else{
            System.out.println("ERRO: pré-requísito já foi inserido no conjunto de pré-requísitos");
            aux = false;
        }
        return aux;
    }

    @Override
    public String toString() {
        int n_pré_requisitos = pré_requisitos.size();
        int i;
        String dados = título + "-" + carga_horária_semanal + " horas semanais - "+ duração_semanas+ " semanas";
        if(n_pré_requisitos > 0){
            dados += "\n pré-requísitos:"+ pré_requisitos.get(0).getTitulo();
            for ( i = 0; i < n_pré_requisitos; i++) {
             dados += " - " + pré_requisitos.get(i).getTitulo();
                
            }
        }
        return dados;
    }
    
    private String getTitulo() {
        return título;
    }
    public ArrayList<Curso> getPré_requisitos() {
        return pré_requisitos;
    }
    
}
