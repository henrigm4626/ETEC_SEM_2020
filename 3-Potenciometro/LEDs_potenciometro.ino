#define PinPotenciometro 0
#define PinLed1 1
#define PinLed2 2
#define PinLed3 3

int Pot = 0;

void setup()
{
  pinMode(PinLed1, OUTPUT);
  pinMode(PinLed2, OUTPUT);
  pinMode(PinLed3, OUTPUT);
}

void loop()
{
  Pot = analogRead(PinPotenciometro);
  
  if (Pot < 300) {
    digitalWrite (PinLed1, HIGH);
  }
  
  if (Pot > 300 && Pot < 900) {
    digitalWrite(PinLed1,HIGH);
    digitalWrite(PinLed2,HIGH);
  }
  
  else{
    digitalWrite(PinLed2,LOW);
  }
  
  if (Pot > 900){
    digitalWrite(PinLed1,HIGH);
    digitalWrite(PinLed2,HIGH);
    digitalWrite(PinLed3,HIGH);
  }
  
  else{
    digitalWrite(PinLed3,LOW);
  }
    
}
