#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int LM35 = A0;
float temperatura;
float temperatura2 = 50;// variavel para comparar
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  temperatura = (float (analogRead(LM35))*5/(1023))/0.01;
  lcd.setCursor(0,1);
  lcd.print("Temperatura:");
  lcd.print(temperatura);
  Serial.print("Temperatura:");
  Serial.println(temperatura);
  if (temperatura < temperatura2){
    lcd.setCursor(0,0);
    temperatura2 = temperatura;
    lcd.print("Menor:");
    lcd.print(temperatura2);
    Serial.print("Menor Temperatura Registrada:");
    Serial.println(temperatura2);
    
  }
  delay(2000);
  
}
