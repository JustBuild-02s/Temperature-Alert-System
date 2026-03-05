#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11   // or DHT22
DHT dht(DHTPIN, DHTTYPE);

const int ledPins[3] = {8, 9, 10};
const int buzzerPin = 11;

const float T1 = 30.0;  // threshold for 2 LEDs
const float T2 = 35.0;  // threshold for 3 LEDs + buzzer
const float HYST = 0.5; // hysteresis to prevent flicker

int lastLevel = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();

  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("Sensor read failed");
    return;
  }

  // decide level
  int level = lastLevel;
  if      (t >= T2 + HYST) level = 3;
  else if (t <= T2 - HYST && t >= T1 + HYST) level = 2;
  else if (t <= T1 - HYST) level = 1;

  // update LEDs
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], (i < level) ? HIGH : LOW);
  }

  // buzzer at high temp
  if (t >= T2) {
    digitalWrite(buzzerPin, HIGH);   // continuous beep
    // OR use tone(buzzerPin, 1000); // beep at 1kHz if passive buzzer
  } else {
    digitalWrite(buzzerPin, LOW);
    // noTone(buzzerPin);
  }

  // Serial monitor
  Serial.print("Temperature: ");
  Serial.print(t, 1);
  Serial.print(" °C  | LEDs: ");
  Serial.print(level);
  Serial.print("  | Buzzer: ");
  Serial.println(t >= T2 ? "ON" : "OFF");

  lastLevel = level;
  delay(1500);
}
