/**
 * @file pHSensor.h
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

#ifndef pHSensor_h
#define pHSensor_h

#include "Arduino.h"

static const uint8_t PH4502C{1};

static const uint16_t ADC10BIT{1023};
static const uint16_t ADC12BIT{4095};

static const float LOGIC5V(5.0);
static const float LOGIC3V3(3.3);

/**
 * @brief Class that stores state and functions for pH Meter
 * 
 */
class pHSensor
{
private:
  uint8_t _type;
  uint8_t _pin;
  uint16_t _adc;
  int _adcValue;
  float _logic;
  float _Voltage;
  float _Temp;
  float _pH;
public:
  /**
   * @brief Construct a new pHMeter Arduino::pHMeter Arduino object
   * 
   * @param Sensor_Type type of sensor : PH4502C
   * @param pin pin number that sensor is connected
   */
  pHSensor(uint8_t Sensor_Type, uint8_t pin, uint16_t adc = ADC10BIT, float logic = LOGIC5V);

  void begin();

  float readVoltage(float calibration = 0);

  float readpH(float calibration = 0);
  
  float readTemp(float calibration = 0);
};

#endif