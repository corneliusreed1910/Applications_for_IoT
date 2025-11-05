//  Eduardo Peinado
//  https://github.com/corneliusreed1910
//  Student number: 22073
//  TIADSM05A
//  Tuesday, October 21th, 2025
//  Subject: Applications for Internet of Things (AIoT)
//  ACT_PRJCT: Bluetooth module controlling a buzzer, two LEDs and a DHT11 temperature/humidity sensor through "Serial Bluetooth Terminal" app
//  Profe. Rocío del Carmen Martínez Luna
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Universidad Tecnológica Santa Catarina
//  Santa Catarina, Nuevo León, México

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11

#define RED_LED 9
#define GREEN_LED 12
#define BUZZER 13

SoftwareSerial BT(3, 2); // RX, TX
DHT dht(DHTPIN, DHTTYPE);

unsigned long lastBuzz = 0;
const unsigned long buzzCooldown = 3000; // 3 seconds

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.begin(9600);
  BT.begin(9600);
  dht.begin();

  Serial.println("Bluetooth Control + DHT11 Ready!");
  BT.println("Arduino Bluetooth Ready! Type commands:");
  BT.println("'R ON', 'R OFF', 'G ON', 'G OFF', 'BUZZ', or 'DHT'");
}

void loop() {
  if (BT.available()) {
    String command = BT.readStringUntil('\n');
    command.trim();
    command.toUpperCase();
    Serial.println("Received: " + command);

    if (command == "R ON") {
      digitalWrite(RED_LED, HIGH);
      BT.println("Red LED ON");
    } 
    else if (command == "R OFF") {
      digitalWrite(RED_LED, LOW);
      BT.println("Red LED OFF");
    } 
    else if (command == "G ON") {
      digitalWrite(GREEN_LED, HIGH);
      BT.println("Green LED ON");
    } 
    else if (command == "G OFF") {
      digitalWrite(GREEN_LED, LOW);
      BT.println("Green LED OFF");
    } 
    else if (command == "BUZZ") {
      unsigned long now = millis();
      if (now - lastBuzz >= buzzCooldown) {
        tone(BUZZER, 1000, 500); // Buzz for 0.5s
        lastBuzz = now;
        BT.println("Buzzer Activated!");
      } else {
        BT.println("Wait for cooldown!");
      }
    } 
    else if (command == "DHT") {
      float h = dht.readHumidity();
      float t = dht.readTemperature();

      if (isnan(h) || isnan(t)) {
        BT.println("Sensor error!");
      } else {
        BT.print("Temp: "); BT.print(t); BT.print(" °C | Hum: "); BT.print(h); BT.println(" %");
      }
    } 
    else {
      BT.println("Unknown command!");
    }
  }
}

