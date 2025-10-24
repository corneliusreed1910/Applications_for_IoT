//  Eduardo Peinado
//  https://github.com/corneliusreed1910
//  Student number: 22073
//  TIADSM05A
//  Friday, October 24th, 2025
//  Subject: Applications for Internet of Things (AIoT)
//  ACT_05: controlling a DC motor's direction with pulsating switches through an H-bridge (L293D)
//  Profe. Rocío del Carmen Martínez Luna
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Universidad Tecnológica Santa Catarina
//  Santa Catarina, Nuevo León, México

#include <Arduino.h>

int speed1=0, speed2=0, x=0, pwm=0;

void setup(){
  pinMode(3,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,INPUT);
  digitalWrite(4,HIGH);
  pinMode(5,INPUT);
  digitalWrite(5,HIGH);
}

void loop(){
  speed1=digitalRead(4);
  speed2=digitalRead(5);

if(speed1==LOW){
  x=3;
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
}
if(speed2==LOW){
  x=5;
  digitalWrite(7,HIGH);
  digitalWrite(6,LOW);
}
  pwm=map(x,0,5,0,255);
  analogWrite(3,pwm);
}
