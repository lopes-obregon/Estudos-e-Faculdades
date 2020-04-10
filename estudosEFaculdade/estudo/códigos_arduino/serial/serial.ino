String nome;
bool imprimeif = false;
void setup() {
  Serial.begin(9600); // abre para a porta serial de comunicação
  Serial.println("Imprimindo caracteres");
}

void loop() {
  if(imprimeif == false){
    for(int i = 33; i < 130; ++i){
        Serial.write(i);
        delay(1000);
        if(i == 129 and imprimeif == false){
            Serial.println("A impressão já terminou");
           imprimeif = true;
          }
      }
  }else{
      Serial.println("ja foi impresso todos os caracteres");
      delay(1000);
    } 
}
