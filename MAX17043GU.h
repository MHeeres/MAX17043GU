/*
  MAX17043GU.h - Library for MAX17043G+U
  As used on Sparkfun's LiPo Fuel Gauge (TOL-10617 | https://www.sparkfun.com/products/10617).
  And SparkFun's LiPower Shield (DEV-10711 | https://www.sparkfun.com/products/10711).
  Created by M. Heeres, June 19, 2015.
  Adapted from Sparkfun' example code, all credits go to Sparkfun Electronics (www.sparkfun.com).
  Released into the public domain.
*/
#ifndef MAX17043GU_H
#define MAX17043GU_H

#include "Arduino.h"


// Address
const uint8_t MAX17043GU_ADDRESS = 0x36;
// Registers
const uint8_t MAX17043GU_REG_VOLTAGE = 0x02;
const uint8_t MAX17043GU_REG_STATEOFCHARGE = 0x04;
const uint8_t MAX17043GU_REG_MODE = 0x06;
const uint8_t MAX17043GU_REG_CONFIG = 0x0C;
// Modes
#define MAX17043GU_MODE_RESTART 0x4000

// Constants
#define MAX17043GU_VOLTAGE_INCEMENTS 0.00125

class MAX17043GU {
  public:
  MAX17043GU(int address=MAX17043GU_ADDRESS);
  void setLowBattery(byte percent);
  void restart();
  float voltageLevel();
  float fuelLevel();

  private:
  int _MAX17043_ADDRESS;
  unsigned int i2cRead16(unsigned char address);
  void i2cWrite16(unsigned int data, unsigned char address);
  
};

#endif

