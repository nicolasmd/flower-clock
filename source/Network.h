#ifndef NETWORK_H
#define NETWORK_H

#include <ESP8266WiFi.h>

class Network {
  
  static const int SET_BUTTON_PIN = D1;
  static const int MINUTE_BUTTON_PIN  = D5;
  static const int HOUR_BUTTON_PIN = D2;
  static const int ALARM_BUTTON_PIN = D6;

  public:
  
    void connect();
    int getMode();
    void setMode(int mode);


  private:

    int _mode;
    String _getExplodedValue(String data, char separator, int index);

};


#endifClock