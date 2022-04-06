/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package controle;

import entidade.Atletismo;
import interfaces.JanelaCadastroAtletismo;

/**
 *
 * @author renan
 */
public class ControladorCadastroAtletismo {

    public ControladorCadastroAtletismo() {
        new JanelaCadastroAtletismo(this).setVisible(true);
    }

    public String inserirAtletismo(Atletismo atletismo) {
        Atletismo atletismo1 = Atletismo.buscarAtletismo(atletismo.getId());
        if(atletismo1 == null) return Atletismo.inserirAtletismo(atletismo);
        else return "Nome do atletismo já cadastrado";
    }

    public String alterarAtletismo(Atletismo atletismo) {
        Atletismo atletismo1 = Atletismo.buscarAtletismo(atletismo.getId());
        if(atletismo1 != null) return Atletismo.alterarAtletismo(atletismo);
        else return "Modalidade de atletismo não encontrado";
        
    }

    public String removerAtletismo(String modalidade) {
        Atletismo atletismo1 = Atletismo.buscarAtletismo(modalidade);
        if(atletismo1 != null) return Atletismo.removerAtletismo(modalidade);
        else return "Modalidade de atletismo não cadastrado";
        
    }
   
}
