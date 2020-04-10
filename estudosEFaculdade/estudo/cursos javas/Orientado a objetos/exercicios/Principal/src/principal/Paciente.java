/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal;

/*
    Card CRC{
    class name: Paciente
    sabe{
peso
altura <- double
}
faz{calula_imc
da o diagnostico
*/


/**
 *
 * @author renan
 */
public class Paciente {
    double altura;
    double peso;
   //construtor 
    public Paciente(double metros, double kilo){
        altura = metros;
        peso = kilo;
    }
    //métodos
    public double calcularIMC(){
        return peso/(altura * altura);
        
    }
    
    public String diagnostico(){
        String resposta;
        //parte que calcula o vaixo peso;
        if(calcularIMC() <= 18.49){
            if(calcularIMC() < 16){
                resposta = "Baixo peso muito grave";
            }else{
                if(calcularIMC() >= 16 && calcularIMC() <= 16.99){
                    resposta = "Baixo peso grave";
                }else{
                    resposta = "Baixo peso";
                }
            }
    }else{
            if(calcularIMC() <= 24.99){
                resposta = "Peso normal";
            }else{
                if(calcularIMC() <= 29.99){
                    resposta = "Sobrepeso";
                }else{
                    if(calcularIMC() <= 34.99){
                        resposta = "Obesidade grau I";
                    }else{
                        if(calcularIMC() <= 39.99){
                            resposta = "Obesidade grau II";
                        }else{
                            resposta = "Obesidade grau III";
                        }
                    }
                }
            }
        }
    return resposta;
    }
}
/*

Peso normal = IMC entre 18,50 e 24,99 kg/m²
Sobrepeso = IMC entre 25 e 29,99 kg/m²
Obesidade grau I = IMC entre 30 e 34,99 kg/m²
Obesidade grau II = IMC entre 35 e 39,99 kg/m²
Obesidade grau III (obesidade mórbida) = IMC igual ou maior que 40 kg/m²
     
Baixo peso muito grave = IMC abaixo de 16 kg/m²
Baixo peso grave = IMC entre 16 e 16,99 kg/m²
Baixo peso = IMC entre 17 e 18,49 kg/m²
*/