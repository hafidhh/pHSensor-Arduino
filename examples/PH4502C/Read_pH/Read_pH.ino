/**
 * @file Read_pH.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example Read pH
 * @version 1.0.0
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/pHMeter-Arduino
 */

#include <Arduino.h>
#include <pHSensor.h>

// pin = PO pin
uint8_t pin = A0;
pHSensor pH(PH4502C, pin);
float pHValue;

void setup() {
  Serial.begin(115200);
  pH.begin();
}

void loop() {
  pHValue = pH.readpH();
  Serial.print("\npH = ");
  Serial.println(pHValue);
  delay(1000);
}