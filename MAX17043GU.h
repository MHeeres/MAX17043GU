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

class MAX17043GU {
  public:
  MAX17043GU(int address);
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

