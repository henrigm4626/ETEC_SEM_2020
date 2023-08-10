void setup()
{
  pinMode(11, OUTPUT); // Vermelho Pedestre
  pinMode(10, OUTPUT); // Verde Pedestre
  pinMode(8, OUTPUT); // Verde
  pinMode(7, OUTPUT); // Amarelo
  pinMode(6, OUTPUT); // Vermelho
}

void loop()
{
  // Semaforo Verde
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
  delay(5000); 
  // Semaforo Amarelo
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  delay(3000); 
  digitalWrite(7, LOW);
  digitalWrite(11, LOW);
  // Semaforo Vermelho
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  delay(5000); 
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
}
