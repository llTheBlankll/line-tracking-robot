//
// Created by asharia on 1/28/24.
//

#include <IRSensor.h>
#include <Arduino.h>

IRSensor::IRSensor(int pin) {
  this->pin = pin;
  pinMode(pin, INPUT);
}

int IRSensor::getPin() const {
  return this->pin;
}

int IRSensor::getValue() const {
  return digitalRead(this->pin);
}
