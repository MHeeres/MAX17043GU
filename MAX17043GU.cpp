#include "MAX17043GU.h"
#include <Wire.h>

MAX17043GU::MAX17043GU(int address) {
  _MAX17043_ADDRESS = address;
}

void MAX17043GU::setLowBattery(byte percent) {
  if ((percent >= 32)||(percent == 0))  // Anything 32 or greater will set to 32%
    i2cWrite16(0x9700, MAX17043GU_REG_CONFIG);
  else
  {
    byte percentBits = 32 - percent;
    i2cWrite16((0x9700 | percentBits), MAX17043GU_REG_CONFIG);
  }
}

void MAX17043GU::restart() {
  i2cWrite16(MAX17043GU_MODE_RESTART, MAX17043GU_REG_MODE);  // Write a 0x4000 to the MODE register
}

float MAX17043GU::voltageLevel() {
  unsigned int vcell;
  
  vcell = i2cRead16(MAX17043GU_REG_VOLTAGE);
  vcell = vcell >> 4;  // last 4 bits of vcell are nothing
  
  return (float)vcell * MAX17043GU_VOLTAGE_INCEMENTS;
}

float MAX17043GU::fuelLevel() {
  unsigned int soc;
  float percent;
  
  soc = i2cRead16(MAX17043GU_REG_STATEOFCHARGE);  // Read SOC register of MAX17043
  percent = (byte) (soc >> 8);  // High byte of SOC is percentage
  percent += ((float)((byte)soc))/256;  // Low byte is 1/256%
  
  return percent;
}

void MAX17043GU::i2cWrite16(unsigned int data, unsigned char address)
{
  Wire.beginTransmission(_MAX17043_ADDRESS);
  Wire.write(address);
  Wire.write((byte)((data >> 8) & 0x00FF));
  Wire.write((byte)(data & 0x00FF));
  Wire.endTransmission();
}

unsigned int  MAX17043GU::i2cRead16(unsigned char address)
{
  int data = 0;
  
  Wire.beginTransmission(_MAX17043_ADDRESS);
  Wire.write(address);
  Wire.endTransmission();
  
  Wire.requestFrom(_MAX17043_ADDRESS, 2);
  while (Wire.available() < 2)
    ;
  data = ((int) Wire.read()) << 8;
  data |= Wire.read();
  
  return data;
}

