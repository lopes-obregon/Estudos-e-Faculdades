#include <Servo.h>
const int pinoServo = 6;
Servo s; // Objeto do tipo servo
int pos; // posição do servo motor
void setup() {
  // put your setup code here, to run once:
  s.attach(pinoServo);//associa o pino digital ao objeto do tipo servo
  s.write(0); // seta para a posição zero graus

}

void loop() {
  // put your main code here, to run repeatedly:
  for(pos = 0; pos < 180; pos++){
      s.write(pos);// escreve o valor da posição que o servo deve girar
      delay(15);//intervalo de 15 milissegundo
    }
    delay(1000);//intervalo de 1 segundo
    for(pos = 180; pos >= 0; pos --){
        s.write(pos);
        delay(15);
      }
}
