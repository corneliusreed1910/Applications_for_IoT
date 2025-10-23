//  Eduardo Peinado
//  https://github.com/corneliusreed1910
//  Student number: 22073
//  TIADSM05A
//  Tuesday, October 21th, 2025
//  Subject: Applications for Internet of Things (AIoT)
//  ACT1_05: streetlight
//  Profe. Rocío del Carmen Martínez Luna
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Universidad Tecnológica Santa Catarina
//  Santa Catarina, Nuevo León, México

#include <Arduino.h>

const int green_LED = 2;
const int yellow_LED = 3;
const int red_LED = 4;
const int buzzer = 5;

void setup() {
  pinMode(green_LED, OUTPUT);
  pinMode(yellow_LED, OUTPUT);
  pinMode(red_LED, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  digitalWrite(green_LED, HIGH);
  delay(15000);
  digitalWrite(green_LED, LOW);
  delay(1000);
  digitalWrite(green_LED, HIGH);
  delay(1000);
  digitalWrite(green_LED, LOW);
  delay(1000);
  digitalWrite(green_LED, HIGH);
  delay(1000);
  digitalWrite(green_LED, LOW);
  delay(1000);
  digitalWrite(green_LED, HIGH);
  delay(1000);
  digitalWrite(green_LED, LOW);
  digitalWrite(yellow_LED, HIGH);
  delay(5000);
  digitalWrite(yellow_LED, LOW);
  digitalWrite(red_LED, HIGH);
  delay(10000);
  digitalWrite(red_LED, LOW);
}




