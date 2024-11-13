#ifndef CLOCK_H
#define CLOCK_H

/**
 * Third party libraries
 */
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "NTP.h"
#include <Adafruit_AHT10.h>

/**
 * User libraries
 */
#include "WifiParams.h"
#include "TimeFunctions.h"
#include "TemperatureSensor.h"
#include "Led.h"
#include "Digit.h"
#include "Network.h"


class Clock {

    // Button pins
    static const int SET_BUTTON_PIN = D1;
    static const int MINUTE_BUTTON_PIN  = D5;
    static const int HOUR_BUTTON_PIN = D2;
    static const int ALARM_BUTTON_PIN = D6;

    // Modes
    static const int MODE_TIME = 1;
    static const int MODE_DATE = 2;
    static const int MODE_TEMPERATURE = 4;
    static const int MODE_ALARM = 8;

    // Params
    static const int TEMPERATURE_MIN = 1000;
    static const int TEMPERATURE_MAX = 4500;
    static const long SET_MODE_DURATION = 15000;
    static const long UPDATE_TIME_DURATION = 60000;

  public:
  
    void setup();
    void loop();
    int getMode();
    void setMode(int mode);


  private:

    int _mode;
    unsigned long _previousUpdate = 0;
    unsigned long _updateTime = 60000;
    unsigned long _previousSet = 0;
    unsigned long _previousSetMode = 0;


    WiFiUDP _ntpUDP;
    //NTP ntp(ntpUDP);
    WiFiClient _wifiClient;
    Adafruit_AHT10 _ahtSensor;
    TemperatureSensor _temperature;
    TimeFunctions _timeFunctions;
    Led _led;
    Digit _digit;
    Network _network;

    void _doActionByMode();
    void _displayTime();
    void _displayDate();
    void _displayTemperature();
    void _displayAlarm();
    bool _hasToReturnToTimeMode();
};


#endifClock