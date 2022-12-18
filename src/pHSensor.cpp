/**
 * @file pHSensor.cpp
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
#include "pHSensor.h"

/**
 * @brief Construct a new pHSensor Arduino::pHSensor Arduino object
 * 
 * @param Sensor_Type type of sensor : PH4502C
 * @param pin pin number that sensor is connected
 * @param adc 
 * @param logic 
 */
pHSensor::pHSensor(uint8_t Sensor_Type, uint8_t pin, uint16_t adc, float logic)
{
  _pin = pin;
  _type = Sensor_Type;
  _adc = adc;
  _logic = logic;
}

/**
 * @brief begin
 * 
 */
void pHSensor::begin()
{
  pinMode(_pin, INPUT);
}

/**
 * @brief Read Voltage
 * 
 * @param calibration 
 * @return float Voltage
 */
float pHSensor::readVoltage(float calibration)
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

/**
 * @brief Read pH, pH = 0 - 14
 * 
 * @param calibration
 * @return float pH
 */
float pHSensor::readpH(float calibration)
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

/**
 * @brief Read Temperature in C
 * 
 * @param calibration
 * @return float Temp 
 */
float pHSensor::readTemp(float calibration)
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