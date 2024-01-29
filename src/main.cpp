#include <Arduino.h>
#include <neotimer.h>
#include <IRSensor.h>
#include <pins.h>
#include <Motor.h>

Neotimer sensorTimer = Neotimer(50);

IRSensor leftIRSensor(LEFT_IR_SENSOR_PIN);
IRSensor rightIRSensor(RIGHT_IR_SENSOR_PIN);
Motor leftMotor(LEFT_MOTOR_PIN);
Motor rightMotor(RIGHT_MOTOR_PIN);

void setup() {
  Serial.begin(9600);

  leftMotor.turnOff();
  rightMotor.turnOff();
}

void checkLeftIRSensor() {

  // Check the value of the left IR sensor, if it is HIGH, then turn the right motor on
  const int leftIRSensorValue = leftIRSensor.getValue();
  if (leftIRSensorValue == HIGH) {
    leftMotor.turnOn();
    rightMotor.turnOff();
  }

  Serial.println("Left IR Sensor Status: "  + String(leftIRSensorValue));
}

void checkRightIRSensor() {
  // Check the value of the right IR sensor, if it is HIGH, then turn the left motor on
  const int rightIRSensorValue = rightIRSensor.getValue();
  if (rightIRSensorValue == HIGH) {
    leftMotor.turnOff();
    rightMotor.turnOn();
  }

  Serial.println("Right IR Sensor Status: "  + String(rightIRSensorValue));
}

// TODO: Implement this function
void rotateServoMotor() {
}

void checkIRSensors() {
  // Checks the value of the IR sensors
  checkLeftIRSensor();
  checkRightIRSensor();
}

void loop() {
  if (sensorTimer.repeat()) {
    checkIRSensors();
  }
}
