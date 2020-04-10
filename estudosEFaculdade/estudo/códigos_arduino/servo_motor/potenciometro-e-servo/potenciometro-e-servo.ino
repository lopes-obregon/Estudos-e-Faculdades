#include <Servo.h>
#define A0 0 //define o pino analogico
Servo s;
int valPot = 0; //variável que armazena o valor da leitura do potenciômetro
const int pinoServo = 6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  s.attach(pinoServo);
  s.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  valPot = analogRead(A0); //faz a leitura do pino analógico
  valPot = map(valPot,0,1023,0,255);//Utilizando a função map() para transformar uma escala de 0-1023 em uma escala 0 a 255
  Serial.println(valPot);
  if(valPot <= 180){
      s.write(valPot);
  }
}
