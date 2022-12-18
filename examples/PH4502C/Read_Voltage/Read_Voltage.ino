/**
 * @file Read_Voltage.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example Read Voltage
 * @version 1.0.0
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/pHSensor-Arduino
 */
#include <Arduino.h>
#include <pHSensor.h>

// pin = PO pin
uint8_t pin = A0;

pHSensor pH(PH4502C, pin);
float volt;

void setup() {
  Serial.begin(115200);
  pH.begin();
}

void loop() {
  volt = pH.readVoltage();
  Serial.print("\nVoltage = ");
  Serial.println(volt);
  delay(1000);
}