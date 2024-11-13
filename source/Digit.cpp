#include "Digit.h"


void Digit::setup()
{
  pinMode(Digit::SERIAL_PIN, OUTPUT);
  pinMode(Digit::LATCH_PIN, OUTPUT);
  pinMode(Digit::SHIFT_PIN, OUTPUT);
}


void Digit::clearRegisters()
{
  for(int i = Digit::NUM_REGISTER_PINS - 1; i >=  0; i--){
    this->_registers[i] = LOW;
  }
}


void Digit::writeRegisters()
{
  digitalWrite(Digit::LATCH_PIN, LOW);
  for(int i = Digit::NUM_REGISTER_PINS - 1; i >=  0; i--){
    digitalWrite(Digit::SHIFT_PIN, LOW);
    int val = this->_registers[i];
    digitalWrite(Digit::SERIAL_PIN, val);
    digitalWrite(Digit::SHIFT_PIN, HIGH);
  }
  digitalWrite(Digit::LATCH_PIN, HIGH);
}


void Digit::setRegisterPin(int index, int value)
{
  this->_registers[index] = value;
}


void Digit::displayNumber(int d, int num)
{
  // Digit
  this->setRegisterPin(11, (d == 1) ? LOW : HIGH);
  this->setRegisterPin(8, (d == 2) ? LOW : HIGH);
  this->setRegisterPin(7, (d == 3) ? LOW : HIGH);
  this->setRegisterPin(5, (d == 4) ? LOW : HIGH);
  // Number
  this->setRegisterPin(10, (num == 0 || num == 2 || num == 3 || num >= 5 ) ? HIGH : LOW); // A
  this->setRegisterPin(6, (num <= 4 || num >= 7) ? HIGH : LOW); // B
  this->setRegisterPin(3, (num != 2) ? HIGH : LOW); // C
  this->setRegisterPin(1, (num == 0 || num == 2 || num == 3 || num == 5 || num == 6  || num >= 8) ? HIGH : LOW); // D
  this->setRegisterPin(0, (num == 0 || num == 2 || num == 6 || num == 8) ? HIGH : LOW); // E
  this->setRegisterPin(9, (num == 0 || num == 4 || num == 5 || num == 6 || num >= 8) ? HIGH : LOW); // F
  this->setRegisterPin(4, (num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num >= 8) ? HIGH : LOW); // G
  // Double points
  this->setRegisterPin(2, HIGH);
  this->writeRegisters();
}

// @ŧodo : generic function displayStg ?
void Digit::displayChar(int d, String str)
{
  // Digit
  this->setClkRegisterPin(11, (d == 1) ? LOW : HIGH);
  this->setClkRegisterPin(8, (d == 2) ? LOW : HIGH);
  this->setClkRegisterPin(7, (d == 3) ? LOW : HIGH);
  this->setClkRegisterPin(5, (d == 4) ? LOW : HIGH);
  // Char
  if(str == "-") {
    this->setClkRegisterPin(10, LOW);
    this->setClkRegisterPin(6, LOW);
    this->setClkRegisterPin(3, LOW);
    this->setClkRegisterPin(1, LOW);
    this->setClkRegisterPin(0, LOW);
    this->setClkRegisterPin(9, LOW);
    this->setClkRegisterPin(4, HIGH);   
  }
  // Double points
  this->setRegisterPin(2, HIGH);
  this->writeRegisters();
}


void Digit::displayOff()
{
    for(int i = 0; i <= 12; i++) {
        this->setRegisterPin(i, LOW);
        this->writeRegisters();
    }
}