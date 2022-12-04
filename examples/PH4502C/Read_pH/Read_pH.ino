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
 */

#include <Arduino.h>
#include <pHMeter_Arduino.h>

// pin = PO pin
uint8_t pin = A0;
pHMeter_Arduino pH(PH4502C, pin);
float pHValue;

void setup() {
  Serial.begin(115200);
  pH.begin();
}

void loop() {
  pHValue = pH.ReadpH();
  Serial.print("pH = ");
  Serial.println(pHValue);
  delay(1000);
}