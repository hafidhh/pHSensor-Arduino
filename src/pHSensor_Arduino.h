/**
 * @file pHSensor_Arduino.h
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

#ifndef pHSensor_Arduino_h
#define pHSensor_Arduino_h

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
class pHSensor_Arduino
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
  pHSensor_Arduino(uint8_t Sensor_Type, uint8_t pin, uint16_t adc = ADC10BIT, float logic = LOGIC5V);
  /**
   * @brief begin
   * 
   */
  void begin();
  /**
   * @brief Read Voltage
   * 
   * @param calibration 
   * @return float Voltage
   */
  float ReadVoltage(float calibration = 0);
  /**
   * @brief Read pH, pH = 0 - 14
   * 
   * @param calibration
   * @return float pH
   */
  float ReadpH(float calibration = 0);
  /**
   * @brief Read Temperature in C
   * 
   * @param calibration
   * @return float Temp 
   */
  float ReadTemp(float calibration = 0);
};

#endif