/**
 * @file Read_Voltage.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example Read Voltage
 * @version 0.0.1
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 */
#include <Arduino.h>
#include <pHMeter_Arduino.h>

// pin = PO pin
uint8_t pin = A0;

pHMeter_Arduino pH(PH4502C, pin);
float volt;

void setup() {
  Serial.begin(115200);
  pH.begin();
}

void loop() {
  volt = pH.ReadVoltage();
  Serial.print("\nVoltage = ");
  Serial.println(volt);
  delay(1000);
}