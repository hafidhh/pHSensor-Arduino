# PH Sensor Arduino Library
Arduino library for pH Sensor

## Usages
See [all axemples](https://github.com/hafidhh/pHSensor-Arduino/blob/master/examples)

### initialization
```cpp
#include <pHSensor_Arduino.h>

uint8_t type = PH4502C; // type : Sensor type
uint8_t pin = A1; // pin : interrupt pin

pHSensor_Arduino pH(type, pin);
```

### Sensor begin
```cpp
void begin()
```

### Sensor Read
param **`calibration`** Voltage  
return **`Voltage`**
```cpp
float readVoltage(float calibration)
```

### Count Pulse
param **`calibration`** Voltage  
return **`pH`**
```cpp
float readpH(float calibration)
```

### Get Total Pulse
param **`calibration`**  
return **`Temperatur`**
```cpp
float readTemp(float calibration)
```