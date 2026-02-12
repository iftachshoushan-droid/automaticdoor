#include "Iftachs.h"

Iftachs::Iftachs(int trigPin, int echoPin) {
  _trig = trigPin;
  _echo = echoPin;
}

void Iftachs::begin() {
  Serial.begin(9600);

  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);

  pinMode(step_pin, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(step2_pin, OUTPUT);
  pinMode(dir2_pin, OUTPUT);

  Serial.println("Setup done!");
}

float Iftachs::getDistance() {
  digitalWrite(_trig, LOW);
  delayMicroseconds(5);
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);

  long duration = pulseIn(_echo, HIGH, 30000);
  return duration * 0.034 / 2;
}

void Iftachs::drive_stepper() {

  const int time_on  = 10;
  const int time_off = 500;

  Serial.println("Starting forward movement...");
  digitalWrite(dir_pin, LOW);
  digitalWrite(dir2_pin, HIGH);

  for (int i = 0; i < steps; i++) {
    digitalWrite(step_pin, HIGH);
    digitalWrite(step2_pin, HIGH);
    delayMicroseconds(time_on);
    digitalWrite(step_pin, LOW);
    digitalWrite(step2_pin, LOW);
    delayMicroseconds(time_off);
  }

  delay(1000);

  Serial.println("Starting backward movement...");
  digitalWrite(dir_pin, HIGH);
  digitalWrite(dir2_pin, LOW);

  for (int i = 0; i < steps; i++) {
    digitalWrite(step_pin, HIGH);
    digitalWrite(step2_pin, HIGH);
    delayMicroseconds(time_on);
    digitalWrite(step_pin, LOW);
    digitalWrite(step2_pin, LOW);
    delayMicroseconds(time_off);
  }

  Serial.println("Cycle done!");
}
