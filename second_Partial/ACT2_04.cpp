//  Eduardo Peinado
//  Student number: 22073
//  Subject: Application for Internet of Things
//  ACT2_04: HC sensor with LEDs and buzzer
//  Fifth term
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Profe. Rocío del Carmen Martínez Luna
//  Universidad Tecnológica Santa Catarina
//  DATE  DATE  DATE
//  Santa Catarina, Nuevo León, México

#include <Arduino.h>

const int reds = 2;
const int yellows = 3;
const int greens = 4;
const int echo = 5;
const int trigger = 6;
const int buzzer = 7;

void setup()
{
    pinMode(reds, OUTPUT);
    pinMode(yellows, OUTPUT);
    pinMode(greens, OUTPUT);
    pinMode(trigger, OUTPUT); //I don't know which one is the INPUT at the moment
    pinMode(echo, OUTPUT); //I don't know which one is the INPUT at the moment
    pinMode(buzzer, OUTPUT);
}

void loop()
{
    
}