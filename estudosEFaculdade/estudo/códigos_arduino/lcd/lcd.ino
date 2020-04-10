#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char caractere;
String msg = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Favor lavar a lousa");
}

void loop() {
 delay(1000);
 lcd.scrollDisplayLeft();
 
  
}
