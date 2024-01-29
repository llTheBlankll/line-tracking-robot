//
// Created by asharia on 1/29/24.
//

#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

class Motor {
public:
  explicit Motor(int pin);
  int getPin() const;
  int getStatus() const;
  int getSpeed() const;
  int setSpeed(int speed);
  void turnOn() const;
  void turnOff() const;
private:
  int pin;
  int speed;
};

#endif //MOTORCONTROLLER_H
