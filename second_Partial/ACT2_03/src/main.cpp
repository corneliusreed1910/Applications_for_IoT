#include <Arduino.h>

// Segment pins
const int segPins[7] = {2,3,4,5,6,7,8};

// Button pins
const int START_BTN = 9;
const int RESET_BTN = 10;

// LEDs
const int POWER_LED = 11;
const int WORK_LED  = 12;

// Buzzer
const int BUZZER = 13;

// Display patterns for 0–9 (common cathode)
// a b c d e f g (1 = on)
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int currentNum = 9;
bool running = false;
bool frozen = false;

void showDigit(int n) {
  for(int i=0; i<7; i++) {
    digitalWrite(segPins[i], digits[n][i]);
  }
}

void beep() {
  digitalWrite(BUZZER, HIGH);
  delay(150);
  digitalWrite(BUZZER, LOW);
}

void setup() {
  // Segments
  for(int i=0; i<7; i++) pinMode(segPins[i], OUTPUT);

  // Buttons
  pinMode(START_BTN, INPUT_PULLUP);
  pinMode(RESET_BTN, INPUT_PULLUP);

  // LEDs
  pinMode(POWER_LED, OUTPUT);
  pinMode(WORK_LED,  OUTPUT);

  // Buzzer
  pinMode(BUZZER, OUTPUT);

  // Power LED on
  digitalWrite(POWER_LED, HIGH);

  // Initial display
  showDigit(currentNum);
}

void loop() {

  // START BUTTON
  if (!digitalRead(START_BTN) && !running) {
    running = true;
    frozen = false;
    digitalWrite(WORK_LED, HIGH);
    beep(); // start beep
    delay(300);
  }

  // RESET BUTTON
  if (!digitalRead(RESET_BTN)) {
    if (running && !frozen) {
      // Freeze
      frozen = true;
      running = false;
      digitalWrite(WORK_LED, LOW);
    } else if (frozen) {
      // Reset to 9
      currentNum = 9;
      showDigit(currentNum);
      frozen = false;
    }
    delay(300); // debounce / avoid double-press
  }

  // COUNTDOWN
  if (running) {
    delay(1000);
    currentNum--;
    showDigit(currentNum);

    if (currentNum <= 0) {
      running = false;
      digitalWrite(WORK_LED, LOW);
      beep(); // end beep
    }
  }
}
