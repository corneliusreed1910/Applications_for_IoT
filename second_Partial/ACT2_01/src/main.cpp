//  Eduardo Peinado
//  https://github.com/corneliusreed1910
//  Student number: 22073
//  TIADSM05A
//  Friday, October 24th, 2025
//  Subject: Applications for Internet of Things (AIoT)
//  ACT2_01: simple switching with pulsating switch
//  Profe. Rocío del Carmen Martínez Luna
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Universidad Tecnológica Santa Catarina
//  Santa Catarina, Nuevo León, México

#include <Arduino.h>

const int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
}