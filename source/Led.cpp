#include "Led.h"


void Led::setup()
{

  pinMode(Led::SERIAL_LED_PIN, OUTPUT);
  pinMode(Led::LATCH_LED_PIN, OUTPUT);
  pinMode(Led::SHIFT_LED_PIN, OUTPUT);

  this->clearRegisters();
  this->ledUniColor(0);
}


void Led::clearRegisters(){
  for(int i = Electronics::LED_NUM_REGISTER_PINS - 1; i >=  0; i--){
    this->_led_registers[i] = LOW;
  }
}


void Led::writeRegisters(){
  digitalWrite(Led::LATCH_LED_PIN, LOW);
  for(int i = Led::LED_NUM_REGISTER_PINS - 1; i >=  0; i--){
    digitalWrite(Led::SHIFT_LED_PIN, LOW);
    int val = this->_led_registers[i];
    digitalWrite(Led::SERIAL_LED_PIN, val);
    digitalWrite(Led::SHIFT_LED_PIN, HIGH);
  }
  digitalWrite(Led::LATCH_LED_PIN, HIGH);
}


void Led::setRegisterPin(int index, int value){
  this->_led_registers[index] = value;
}


void Led::uniColor(int c)
{
  for(int i = 0; i < 7; i++) {
    this->setRegisterPin(3 * i, (1 & c) == 0 ? HIGH : LOW);
    this->setRegisterPin(3 * i + 1, (2 & c) == 0 ? HIGH : LOW);
    this->setRegisterPin(3 * i + 2, (4 & c) == 0 ? HIGH : LOW);
  }
  this->writeRegisters();
}


void Led::arrayColor(int leds[])
{
  for(int i = 0; i < 7; i++) {
    this->setRegisterPin(3 * i, (1 & leds[i]) == 0 ? HIGH : LOW);
    this->setRegisterPin(3 * i + 1, (2 & leds[i]) == 0 ? HIGH : LOW);
    this->setRegisterPin(3 * i + 2, (4 & leds[i]) == 0 ? HIGH : LOW);
  }
  this->writeRegisters();
}

