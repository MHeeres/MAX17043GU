/*
  MAX17043GU Example
  Created by M. Heeres, June 21, 2015.
  http://mheeres.com
*/

#include <Wire.h>
#include <MAX17043GU.h>

#define MAX17043_ADDRESS 0x36

float voltage;
float percentage;

MAX17043GU battery;

void setup() 
{
  // Start serial
  Serial.begin(9600);
  // Start I2C
  Wire.begin();
  delay(100);
  battery.restart();
}

void loop() 
{
  // Get the values
  voltage = battery.voltageLevel();
  percentage = battery.fuelLevel();
  
  // Print
  Serial.print("Battery voltage: ");
  Serial.print(voltage, 2);
  Serial.println("V");
  Serial.print("Battery level: ");
  Serial.print(percentage, 2);
  Serial.println("%");
  
  // Wait
  delay(3000);
}
