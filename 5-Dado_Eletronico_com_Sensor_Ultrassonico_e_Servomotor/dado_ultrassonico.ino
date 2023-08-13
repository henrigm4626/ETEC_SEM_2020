#include <Servo.h> 

Servo servo;

int pos;
int Num = 0;
long cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // Porta de saída
  digitalWrite(triggerPin, LOW); // Declarando a saída como BAIXO	
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); // Declarando a saída como ALTO
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT); // Porta de entrada do sinal
  return (pulseIn(echoPin, HIGH)*0.01723); //Verificando se houve entrada de sinal, efetuando o retorno
  
}

void setup()
{
  
  // Colocando o servomotor na posição inicial  
  servo.attach(6);  
  servo.write(0);  
  delay(1000);
  
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  cm = readUltrasonicDistance(A0, A0);

  Serial.print(cm);
  Serial.println("cm");
  
  // Condição para que as luzes acendam conforme a distância de um objeto em relação ao sensor
  if (cm < 30) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    delay(600);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(600);
    
    Num = random(1, 6 + 1);
    
    if (Num == 1) {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      
      // Movimentação até 0
    	for(pos = 180; pos >= 0; pos--){ 
      		servo.write(pos);
      		delay(0);  
    	}
    }
    
    delay(1000);
    
    if (Num == 2) {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      
      // Movimentação até 90 
      for(pos = 0; pos < 90; pos++){ 
   		servo.write(pos);
   		delay(0);
      }
    }
    
    delay(1000);
    
    if (Num == 3) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      
      // Movimentação até 0
    	for(pos = 180; pos >= 0; pos--){ 
      		servo.write(pos);
      		delay(0);  
    	}
    }
    
    delay(1000);
    
    if (Num == 4) {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      
      // Movimentação até 90 
      for(pos = 0; pos < 90; pos++){ 
   		servo.write(pos);
   		delay(0);
      }
    }
    
    delay(1000);
    
    if (Num == 5) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      
      // Movimentação até 0
    	for(pos = 180; pos >= 0; pos--){ 
      		servo.write(pos);
      		delay(0);  
    	}
    }
    
    delay(1000);
    
    if (Num == 6) {
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      
      // Movimentação até 90 
      for(pos = 0; pos < 90; pos++){ 
   		servo.write(pos);
   		delay(0);
      }  
    }
    
    delay(1000);
    
  }
  
  if (cm >= 30){
  	digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    
    // Movimentação até 0
    for(pos = 180; pos >= 0; pos--){ 
   		servo.write(pos);
      	delay(0);  
    }
  }
      
  Num == 1;

  delay(1000);
      
}
