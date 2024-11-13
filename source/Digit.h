#ifndef DIGIT_H
#define DIGIT_H

#include <ESP8266WiFi.h>

class Digit {

  static const int SERIAL_PIN = D8;   //pin 14 74HC595
  static const int LATCH_PIN = D9;  //pin 12 74HC595
  static const int SHIFT_PIN = D10; //pin 11 74HC595

  static const int NUM_REGISTER_PINS = 16;

  public:

    void setup();
    void clearRegisters();
    void writeRegisters();
    void setRegisterPin(int index, int value);
    void displayDigit(int digit, int num);
    void displayChar(int digit, String str);
    void displayOff();

  private:

    bool _registers[Digit::NUM_REGISTER_PINS];

};



#endif