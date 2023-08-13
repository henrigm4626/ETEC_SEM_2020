#include <Servo.h> 

Servo servo; 

int pos; 
long cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); // Declarando a porta de saída
  digitalWrite(triggerPin, LOW);// Declarando a saída como BAIXO	
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); // Declara a saída como ALTO
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
}

void loop()
{
  cm = readUltrasonicDistance(A0, A0);

  Serial.print(cm);
  Serial.println("cm");
  
  
  // Condição para que as luzes acendam conforme a distância de um objeto em relação ao sensor
  // LED Azul
  if (cm < 40) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  
  // LED Verde
  if (cm >= 40 && cm < 60) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  
  // LED Amarelo
  if (cm >= 60 && cm < 80) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    
  }
  
  // Todos os LEDS
  if (cm >= 80 && cm < 100) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    
    // Movimentação até 90 
    for(pos=0; pos<90; pos++){ 
      servo.write(pos);
      delay(0);
    } 
  }
  
  if (cm >= 100) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    
    // Movimentação até 0
    for(pos=180; pos>=0; pos--){ 
      servo.write(pos);
      delay(0);  
    }
  }

  delay(100);
  
}
