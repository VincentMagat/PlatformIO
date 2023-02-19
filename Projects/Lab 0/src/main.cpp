#include <Arduino.h>
#include <Servo.h>
Servo myservo; // creating object for servo


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  myservo.attach(2);

}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;

  while (i <=10){
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    i++;
  }
  delay(4000);
  myservo.write(50);
  delay(4000);


}