#include <Servo.h>

Servo myservo;

int potpin = 0;
int val1;
int val2;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  val1 = analogRead (potpin);
  val2 = map(val1, 0, 1023, 0, 180);
  myservo.write(val2);
  Serial.print ("Potenciometro: ");
  Serial.print(val1);
  Serial.print(" - Angulo: ");
  Serial.print(val2);
  delay(15);
}
  
