//
// Created by asharia on 1/29/24.
//

#include <Motor.h>
#include <Arduino.h>

Motor::Motor(const int pin) {
  this->pin = pin;
  this->speed = 150;

  pinMode(pin, OUTPUT);
}

int Motor::getPin() const {
  return this->pin;
}

int Motor::getSpeed() const {
  return this->speed;
}

int Motor::setSpeed(const int speed) {
  this->speed = speed;
  return this->speed;
}

void Motor::turnOn() const {
  if (getStatus() == LOW) {
    digitalWrite(this->pin, HIGH);
  }
}

void Motor::turnOff() const {
  if (getStatus() == HIGH) {
    digitalWrite(this->pin, LOW);
  }
}

int Motor::getStatus() const {
  return digitalRead(this->pin);
}
