#include <Arduino.h>

/* Using the DHT22 sensor to take temperature
   and humidity readings, then display it on the
   4 digit 7 segment display.

   Components:
                - Arduino Uno
                - DHT22
                - 4 digit 7 segment display
                - 1kOhm resistor (x 4)
                - 10kOhm resistor (act as a Pull-up resistor)

   Libraries:
                - DHT.h
                - Github repository: https://github.com/adafruit/DHT-sensor-library

   Datasheet: https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf

   Created on 9 June 2022 by c010rblind3ngineer
*/


#include "DHT.h"
#define DHTPIN 13
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);   //Initialize DHT sensor

int pinA = 11;
int pinB = 7;
int pinC = 4;
int pinD = 2;
int pinE = 1;
int pinF = 10;
int pinG = 5;
int pinDP = 3;

int D1 = 12;
int D2 = 9;
int D3 = 8;
int D4 = 6;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinA, OUTPUT);  //11
  pinMode(pinB, OUTPUT);  //7
  pinMode(pinC, OUTPUT);  //4
  pinMode(pinD, OUTPUT);  //2
  pinMode(pinE, OUTPUT);  //1
  pinMode(pinF, OUTPUT);  //10
  pinMode(pinG, OUTPUT);  //5
  pinMode(D1, OUTPUT);    //12
  pinMode(D2, OUTPUT);    //9
  pinMode(D3, OUTPUT);    //8
  pinMode(D4, OUTPUT);    //6

  dht.begin();
}

void loop() {
  // Give time for the sensor between measurements
  delay(2000);

  // Read temperature in Celsius
  float tC = dht.readTemperature(false);
  // Read humidity
  float h = dht.readHumidity();

  // Display temperature digits on 4 digit 7 segment display
  int tempd1 = int(tC / 10);
  int tempd2 = int((int)tC % 10);
  // Display humidity digits on 4 digit 7 segment display
  int h1 = int(h / 10);
  int h2 = int((int)h % 10);

  // 'for' loop ensures the display is constantly ON within a period of time (approx. 10s)...
  // ...before sensor takes another reading.
  // Temperature reading
  for (int i = 0; i < 2000; i++) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(tempd1);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(tempd2);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    disp(11);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    disp(10);
    delay(1);
  }
  displayoff();
  delay(1000);

  // Humidity reading
  for (int i = 0; i < 2000; i++) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(h1);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    disp(h2);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    disp(12);
    delay(1);

    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    disp(13);
    delay(1);
  }
  displayoff();

}

void disp(int number) {

  switch (number) {
    case 0 : // display '0' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 1 : // display '1' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 2 : // display '2' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 3 : // display '3' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 4 : // display '4' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 5 : // display '5' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 6 : // display '6' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 7 : // display '7' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 8 : // display '8' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 9 : // display '9' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 10 :  // display 'C' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 11 :  // display 'o' on 7 segment
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 12 : // display 'H' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 13 : // display 'u' on 7 segment
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
  }
}

void displayoff() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}