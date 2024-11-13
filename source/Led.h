#ifndef LED_H
#define LED_H

#include <ESP8266WiFi.h>

class Led {
  
  static const int SERIAL_LED_PIN = D13;   //pin 14 74HC595
  static const int LATCH_LED_PIN = D12;  //pin 12 74HC595
  static const int SHIFT_LED_PIN = D11; //pin 11 74HC595

  static const int LED_NUM_REGISTER_PINS = 24;

  // Colors
  static const int C_RED = 4;
  static const int C_GREEN = 2;
  static const int C_BLUE = 1;
  static const int C_WHITE = 7;
  static const int C_PURPLE = 5;
  static const int C_CYAN = 3;
  static const int C_YELLOW = 6;
  static const int C_OFF = 0;

  public:
    void setup();
    void clearRegisters();
    void writeRegisters();
    void setRegisterPin(int index, int value);
    void uniColor(int color);
    void arrayColor(int colors[]);


  private:
    bool _led_registers[Electronics::LED_NUM_REGISTER_PINS];

};



#endif