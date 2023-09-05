int red = 8;
int yellow = 7; 
int green = 6; 
int red2 = 5; 
int yellow2 = 4; 
int green2 = 3;
int ped_red = 10; 
int ped_green = 9;
int button = 2;
unsigned long time;

void setup()
{
  time = millis();
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(ped_red, OUTPUT);
  pinMode(ped_green, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(button, INPUT);
  
	
  // Estado inicial dos semaforos
  digitalWrite(red, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(green2, HIGH);
  
  digitalWrite(ped_red, HIGH);
  digitalWrite(ped_green, LOW);
  
  Serial.begin(1000);

}

void loop()
{
  // Apertando o botao de pedestre
  int aperta_button = digitalRead(button);
  delay(50);
  Serial.println(aperta_button);
  
  if (aperta_button == HIGH && (millis() - time) > 5000) {
    walk();
  }

}

// Contagem de 6 segundos (Amarelo)
void contagem()
{
  digitalWrite(A1, HIGH);
  delay(1250);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  delay(1250);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delay(1250);
  digitalWrite(A3, LOW);
  digitalWrite(A4, HIGH);
  delay(1250);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  delay(1250);
  digitalWrite(A5, LOW);
}

// Contagem de 15 segundos (Vermelho e Verde)
void contagem2()
{
  digitalWrite(A1, HIGH);
  delay(3000);
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  delay(3000);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delay(3000);
  digitalWrite(A3, LOW);
  digitalWrite(A4, HIGH);
  delay(3000);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  delay(3000);
  digitalWrite(A5, LOW);
}

void walk() 
{  
  // Contando o tempo para o semaforo ficar amarelo
  contagem2();

  // Semaforo amarelo
  digitalWrite(green, LOW); 
  digitalWrite(green2, LOW);  
  digitalWrite(yellow, HIGH);   
  digitalWrite(yellow2, HIGH);
  contagem();

  // Semaforo vermelho e pedestre verde
  digitalWrite(yellow, LOW); 
  digitalWrite(yellow2, LOW); 
  digitalWrite(red, HIGH);
  digitalWrite(red2, HIGH);
  digitalWrite(ped_red, LOW);
  digitalWrite(ped_green, HIGH);
  contagem2();
  
  // Piscando o pedestre verde para indicar que vai o semaforo para carros vai abrir
  for (int x=0; x<10; x++){
    digitalWrite(ped_green, LOW);
    delay(160);
    digitalWrite(ped_green, HIGH);
    delay(160);
  }

  // De volta ao estado incial
  digitalWrite(red, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(green2, HIGH);
  digitalWrite(ped_red, HIGH);
  digitalWrite(ped_green, LOW);
  
  time = millis();

 }
