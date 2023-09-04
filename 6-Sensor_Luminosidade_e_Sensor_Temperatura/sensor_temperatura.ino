const int led = 10;
const int buzzer = 6;
const int sensor = A0; 
int tempValue;
int temp_limite = 25.0;


void setup()
{
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}
  
void loop()
{
  tempValue = analogRead(sensor);
  float tensao = (tempValue/1023.0)*5.0;
  float temp = (tensao-0.5)*100;
  delay(200);
  
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" *C");
  
  
  if(temp >= temp_limite){
  	digitalWrite(led, HIGH);
    tone(buzzer,450);
  }
  else{
  	digitalWrite(led, LOW);
    noTone(buzzer);
  }
}
