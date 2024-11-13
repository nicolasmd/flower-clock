#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <Adafruit_AHT10.h>

class TemperatureSensor {
  
  public:
  
    void setup(Adafruit_AHT10& ahtSensor);
    void update();
    int getTemperature();
    
  private:

    int _temperature;
    Adafruit_AHT10 *_ahtSensor;

};


#endif