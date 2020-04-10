int ledRed = 13;

int ledGreen = 12;
long randNumber;
int ledBlue = 11;
void setup()
{
  Serial.begin(9600);
  for( int i = 11; i < 14; i++){
  	pinMode(i, OUTPUT);
  }
	
}

void loop()
{
  randNumber = random(ledBlue,ledRed+1);
  Serial.println(randNumber);
  if (randNumber == 13){
    digitalWrite(ledRed, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(ledRed, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }else{
    if(randNumber == 12){
      digitalWrite(ledGreen, HIGH);
      delay(1000);
      digitalWrite(ledGreen, LOW);
      delay(1000);
    }else{
    	if(randNumber == 11){
 			digitalWrite(ledBlue, HIGH);   	
    		delay(1000);
          	digitalWrite(ledBlue, LOW);
          	delay(1000);
        }
    }
  }
 
}