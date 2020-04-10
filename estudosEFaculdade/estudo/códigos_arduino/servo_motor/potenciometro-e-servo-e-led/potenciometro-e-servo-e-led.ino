#include <Servo.h>
#define A0 0//pino do potenciometro
#define ledPin 13//pino do led
#define tempo 10
Servo s;
int valPot = 0; // variavel que armazena o valor da leitura do potenciometro
const int pinoServo = 6;
const int pinBuzzer = 2;
int som =  262;
//função que faz o som da cirene
void cirene(){
  for (int frequencia = 150; frequencia < 1800; frequencia +=1){
    tone(pinBuzzer, frequencia, tempo);
    delay(1);
  }
  for(int frequencia = 1800; frequencia > 150; frequencia -=1){
    tone(pinBuzzer, frequencia, tempo);
    delay(1);
  }
}
void setup() {
  // put your setup code here, to run once:
  s.attach(pinoServo);
  s.write(0);
  pinMode(ledPin, OUTPUT); //configura o lad como saida no caso a porta
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valPot = analogRead(A0); // faz a leitura do potenciometro
  valPot = map(valPot,0,1023, 0,255); // converte de 1023 para 255
  //analogWrite(ledPin, valPot);//aciona o lad
  if(valPot <= 180){
      s.write(valPot);
      if(valPot >= 20){
        digitalWrite(ledPin, HIGH);
        tone(pinBuzzer, som, 200);
      }else{
        digitalWrite(ledPin, LOW);
      }
    }else{
      digitalWrite(ledPin, HIGH);
      delay(1000);
      cirene();
      digitalWrite(ledPin, LOW);
      delay(1000);
    }
    
}
