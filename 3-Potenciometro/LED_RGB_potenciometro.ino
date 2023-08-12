const int A = 6;
const int B = 4;
const int C = 2;
int sensorValue = 0;

void setup(){
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(A0, INPUT);
}

void loop(){
  sensorValue = analogRead (A0);
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
  delay (sensorValue);
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
  delay (sensorValue);
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
  delay (sensorValue);        
}
