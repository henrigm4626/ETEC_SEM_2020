const int buzzerPin = 6;
const int ldrPin = 0;
const int ledPin = 10;

int ldrValue = 0; // Valor lido do LDR

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  
  if (ldrValue>930){
  	digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
  else{
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin,450);
  }
}
