#include <Servo.h>
const int buttonPin = 2;
const int ledPin = 13;
int buttonState = 0; // variavel que le o estado do botão
int aperto = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);//define o pino como saida
  pinMode(buttonPin, INPUT); // define o pino como entrada

}
//funções
//funções arduino
void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin); // faz a leitura do valor do botao;
 
  if(buttonState == HIGH){
      aperto += 1;
    
    }
  if(aperto == 1){
    digitalWrite(ledPin, HIGH);
    //delay(1000);
    //digitalWrite(ledPin, LOW);
    //delay(1000);
  }else{
    if(aperto >= 2){
      digitalWrite(ledPin, LOW);
      aperto = 0;
      //delay(1000);
    }
  }
}
