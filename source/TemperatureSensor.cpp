#include "TemperatureSensor.h"

void TemperatureSensor::setup(Adafruit_AHT10& ahtSensor)
{
  this->_ahtSensor = &ahtSensor;
  if (! this->_ahtSensor->begin())
  {
    //Serial.println("AHT10 not found");
    while (1) delay(10);
  }
  //Serial.println("AHT10 found");
}

void TemperatureSensor::update()
{
  sensors_event_t humidity, temp;
  this->_ahtSensor->getEvent(&humidity, &temp);
  this->_temperature = temp.temperature * 100;
}

int TemperatureSensor::getTemperature()
{
  this->update();
  return this->_temperature;
}