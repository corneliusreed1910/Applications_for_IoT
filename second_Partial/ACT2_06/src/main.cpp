//  Eduardo Peinado
//  https://github.com/corneliusreed1910
//  Student number: 22073
//  TIADSM05A
//  Friday, October 24th, 2025
//  Subject: Applications for Internet of Things (AIoT)
//  ACT2_06: making a servo motor turn with HC-SR04 ultrasonic sensor and LEDs indicators 
//  Profe. Rocío del Carmen Martínez Luna
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Universidad Tecnológica Santa Catarina
//  Santa Catarina, Nuevo León, México

#include <Servo.h>

// Pin definitions
const int reds[]    = {6, 7, 8};
const int yellows[] = {9, 10, 11};
const int greens[]  = {12, 13, 14};
const int blues[]   = {15, 16, 17};
const int motor = 18;
const int echo = 4;
const int trigger = 5;

Servo servoMotor;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(motor);

  // Set LED pins as output
  for (int i = 0; i < 3; i++) {
    pinMode(reds[i], OUTPUT);
    pinMode(yellows[i], OUTPUT);
    pinMode(greens[i], OUTPUT);
    pinMode(blues[i], OUTPUT);
  }

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  servoMotor.write(0);  // initial position
}

// Function to measure distance
long getDistance() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  long duration = pulseIn(echo, HIGH);
  long distance = duration * 0.034 / 2;  // cm
  return distance;
}

// Turn off all LEDs
void clearLEDs() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(reds[i], LOW);
    digitalWrite(yellows[i], LOW);
    digitalWrite(greens[i], LOW);
    digitalWrite(blues[i], LOW);
  }
}

void loop() {
  long distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  clearLEDs();

  // Display LEDs and move servo based on distance
  if (distance < 10) {
    // Very close — red LEDs on
    for (int i = 0; i < 3; i++) digitalWrite(reds[i], HIGH);
    servoMotor.write(180);
  }
  else if (distance < 20) {
    // Moderate — yellow LEDs
    for (int i = 0; i < 3; i++) digitalWrite(yellows[i], HIGH);
    servoMotor.write(135);
  }
  else if (distance < 30) {
    // Safe — green LEDs
    for (int i = 0; i < 3; i++) digitalWrite(greens[i], HIGH);
    servoMotor.write(90);
  }
  else {
    // Far — blue LEDs
    for (int i = 0; i < 3; i++) digitalWrite(blues[i], HIGH);
    servoMotor.write(0);
  }

  delay(300);
}
