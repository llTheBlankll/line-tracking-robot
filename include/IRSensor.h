//
// Created by asharia on 1/28/24.
//

#ifndef IRSENSOR_H
#define IRSENSOR_H

class IRSensor {
  public:
    explicit IRSensor(int pin);
    int getPin() const;
    int getValue() const;
  private:
    int pin;
};

#endif //IRSENSOR_H
