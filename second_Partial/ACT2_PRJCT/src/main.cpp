//  Eduardo Peinado
//  https://github.com/corneliusreed1910
//  Student number: 22073
//  TIADSM05A
//  Tuesday, October 21th, 2025
//  Subject: Applications for Internet of Things (AIoT)
//  ACT_PRJCT: Bluetooth module controlling a buzzer, two LEDs and a DHT11 temperature/himidity sensor through "Serial Bluetooth Terminal" app
//  Profe. Rocío del Carmen Martínez Luna
//  TIADSM (Tecnologías de la Información Área Desarrollo Software Multiplataforma)
//  Universidad Tecnológica Santa Catarina
//  Santa Catarina, Nuevo León, México

#include <Arduino.h>
#include <DHT.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(7, 6); // RX, TX pins
#define DHTTYPE DHT11

const int red_LED = 9;
const int green_LED = 12;
const int buzzer = 13;
const int dht11_Sensor = 8;
//const int bluetooth_RX = 7;
//const int bluetooth_TX = 6;

DHT dht (dht11_Sensor, DHTTYPE);

void setup()
{
    mySerial.begin(9600); // For Bluetooth communication, match with module's baud rate
    Serial.begin(9600);
    pinMode(red_LED, OUTPUT);
    pinMode(green_LED, OUTPUT);
    pinMode(buzzer, OUTPUT);
    Serial.println("Iniciando...");
    dht.begin();
}

void loop()
{
    delay(5000);
    float humidity = dht.readHumidity();
    float temperature =  dht.readTemperature();
      if (mySerial.available()) {
        char receivedChar = mySerial.read();
        Serial.print("Received: ");
        Serial.println(receivedChar);
        // Process the received character (e.g., control an LED)
      }
      if (Serial.available()) {
        char sentChar = Serial.read();
        mySerial.print(sentChar); // Send data from Arduino Serial Monitor to Bluetooth
      }
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C ");
}