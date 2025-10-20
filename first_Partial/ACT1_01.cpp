//  Eduardo Peinado
//  Student number: 22073
//  Subject: Application for Internet of Things
//  ACT1_01: turning a LED on
//  Fifth term
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Profe. Rocío del Carmen Martínez Luna
//  Universidad Tecnológica Santa Catarina
//  DATE  DATE  DATE
//  Santa Catarina, Nuevo León, México

#include <Arduino.h>

const int led = 2;

void setup()
{
    pinMode(led, OUTPUT);
}

void loop()
{
    digitalWrite(led, HIGH);
}