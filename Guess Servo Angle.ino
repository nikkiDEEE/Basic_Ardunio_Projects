#include <Servo.h>

Servo myServo;
const int button1Pin = 2;
const int button2Pin = 3;
const int ledRPin = 4;
const int ledBPin = 5;
const int ledGPin = 6;

int servoAngle = 90; // Initial angle for the servo
int ledPosition = random(0, 180); // Initial position for the LED
bool isMatch = false;

void setup() {
  Serial.begin(9600);
  
  myServo.attach(9);
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  
  pinMode(ledRPin, OUTPUT);
  pinMode(ledBPin, OUTPUT);
  pinMode(ledGPin, OUTPUT);
  
  digitalWrite(ledRPin, HIGH);
  digitalWrite(ledBPin, LOW);
  digitalWrite(ledGPin, LOW);
  
  randomSeed(analogRead(0));
}

void loop() {
  Serial.println(ledPosition);
  Serial.println(servoAngle);
  
  if (abs(ledPosition - servoAngle) == 10) {
    digitalWrite(ledRPin, LOW);
    digitalWrite(ledBPin, LOW);
    digitalWrite(ledGPin, HIGH);
  } else {
    digitalWrite(ledRPin, HIGH);
    digitalWrite(ledBPin, LOW);
    digitalWrite(ledGPin, LOW);
  }
  
  int player1ButtonState = digitalRead(button1Pin);
  int player2ButtonState = digitalRead(button2Pin);
  
  if (player1ButtonState == LOW) {
    servoAngle += 1; // Player 1 button
  }
  
  if (player2ButtonState == LOW) {
    servoAngle -= 1; // Player 2 button
  }
  
  servoAngle = constrain(servoAngle, 0, 180); // Limit servo angle
  
  myServo.write(servoAngle);
  delay(10);
}
