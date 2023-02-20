#include <Arduino.h>
#include <Servo.h>
Servo myservo; // creating object for servo

int lightIn;
int lightMax;
int lightCurrent;

int servo_out; //currebnt value output to servo
int convert = 22; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9102);
  pinMode(13, OUTPUT);
  myservo.attach(2);

  int i = 0;

  while (i <=10){
    Serial.println(i);
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);
    i++;
  }

  lightIn = analogRead(15);

  delay(4000);
  Serial.print("Callibration complete \n");

}

void loop() {
  // put your main code here, to run repeatedly:

  lightCurrent = analogRead(15); // takes in inout value from photosensor
  if (lightCurrent > lightIn) {
    servo_out = lightCurrent/22;
    myservo.write(servo_out);
  }

}