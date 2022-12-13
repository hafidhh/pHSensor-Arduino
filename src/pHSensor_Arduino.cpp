/**
 * @file pHSensor_Arduino.cpp
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2022-12-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/pHSensor-Arduino
 */

#include "Arduino.h"
#include "pHSensor_Arduino.h"

pHSensor_Arduino::pHSensor_Arduino(uint8_t Sensor_Type, uint8_t pin, uint16_t adc, float logic)
{
  _pin = pin;
  _type = Sensor_Type;
  _adc = adc;
  _logic = logic;
}

void pHSensor_Arduino::begin()
{
  pinMode(_pin, INPUT);
}

float pHSensor_Arduino::ReadVoltage(float calibration)
{
  switch (_type)
  {
  case PH4502C:
    _adcValue = analogRead(_pin);
    _Voltage = (_adcValue*_logic/_adc)+calibration;
    return _Voltage;
    break;
  
  default:
    Serial.println("Sensor Type?");
    return 0;
    break;
  }
}

float pHSensor_Arduino::ReadpH(float calibration)
{ 
  switch (_type)
  {
  case PH4502C:
    _adcValue = analogRead(_pin);
    _Voltage = (_adcValue*_logic/_adc+calibration);
    _pH = 14-(_Voltage*14/5);
    return _pH;
    break;
    
  default:
    Serial.println("Sensor Type?");
    return 0;
    break;
  }
}

float pHSensor_Arduino::ReadTemp(float calibration)
{
  switch (_type)
  {
  case PH4502C:
    _adcValue = analogRead(_pin);
    _Voltage = (_adcValue*_logic/_adc+calibration);
    _Temp = _Voltage*80/5;
    return _Temp;
    break;
  
  default:
    Serial.println("Sensor Type?");
    return 0;
    break;
  }
}