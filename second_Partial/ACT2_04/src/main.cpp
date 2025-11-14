#include <Arduino.h>

// HC-SR04
const int TRIG = 2;
const int ECHO = 3;

// LEDs
const int LED_RED = 4;
const int LED_YELLOW = 5;
const int LED_GREEN = 6;
const int LED_BLUE = 7;

// Buzzer
const int BUZZER = 8;

long getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000); // timeout ~30ms
  long distance = duration / 58;              // convert to cm

  return distance;
}

void showLED(int r, int y, int g, int b) {
  digitalWrite(LED_RED,    r);
  digitalWrite(LED_YELLOW, y);
  digitalWrite(LED_GREEN,  g);
  digitalWrite(LED_BLUE,   b);
}

void beep(int duration) {
  if (duration > 0) {
    digitalWrite(BUZZER, HIGH);
    delay(duration);
    digitalWrite(BUZZER, LOW);
    delay(duration);
  }
}

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  pinMode(BUZZER, OUTPUT);
}

void loop() {
  long cm = getDistance();

  int beepTime = 0;

  if (cm < 10) {
    showLED(1,0,0,0);
    beepTime = 80;    // fast
  } 
  else if (cm < 20) {
    showLED(0,1,0,0);
    beepTime = 150;   // medium
  } 
  else if (cm < 40) {
    showLED(0,0,1,0);
    beepTime = 300;   // slow
  } 
  else {
    showLED(0,0,0,1);
    beepTime = 0;     // silent
  }

  beep(beepTime);
}
