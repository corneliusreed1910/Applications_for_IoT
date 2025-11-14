//  Eduardo Peinado
//  https://github.com/corneliusreed1910
//  Student number: 22073
//  TIADSM05A
//  Friday, October 24th, 2025
//  Subject: Applications for Internet of Things (AIoT)
//  ACT2_02: simple piano with pulsating switches
//  Profe. Rocío del Carmen Martínez Luna
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Universidad Tecnológica Santa Catarina
//  Santa Catarina, Nuevo León, México


#include <Arduino.h>
#define BUZZER 9

int keys[] = {2, 3, 4, 5}; // however many buttons you want

void setup() {
  for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
    pinMode(keys[i], INPUT_PULLUP);
  }
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  bool pressed = false;

  for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
    if (!digitalRead(keys[i])) {  // button pressed (active-low)
      digitalWrite(BUZZER, HIGH); // buzzer ON
      pressed = true;
      break;
    }
  }

  if (!pressed) {
    digitalWrite(BUZZER, LOW); // buzzer OFF
  }
}
