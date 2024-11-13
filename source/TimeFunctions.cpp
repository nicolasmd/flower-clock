#include "TimeFunctions.h"


void TimeFunctions::setup(NTP& ntp)
{
  this->_ntp = &ntp;
  // last sunday in march 2:00, timetone +120min (+1 GMT + 1h summertime offset)
  this->_ntp->ruleDST("CEST", Last, Sun, Mar, 2, 120); 
  // last sunday in october 3:00, timezone +60min (+1 GMT)
  this->_ntp->ruleSTD("CET", Last, Sun, Oct, 3, 60);
  this->_ntp->begin();
  this->update();
}

void TimeFunctions::update()
{
  this->_ntp->update();
  
  this->_clkHour = this->_ntp->hours();
  if(this->_mode12Enabled) {
    this->_clkHour = this->_clkHour > 12 ? this->_clkHour - 12 : this->_clkHour;
  }
  this->_clkMinute = this->_ntp->minutes();
  this->_clkSecond = this->_ntp->seconds();
  this->_clkDay = this->_ntp->day();
  this->_clkMonth = this->_ntp->month();
  this->_clkWeekDay = this->_ntp->weekDay();
  if(this->_clkWeekDay == 0) {
    this->_clkWeekDay = 7;
  }
}

void TimeFunctions::addMinuteToClk()
{
  this->_clkMinute++;
  if(this->_clkMinute == 60) {
    this->_clkMinute = 0;
    this->_clkHour++;
    if(this->_clkHour > 23) {
      this->_clkHour = 0;
    }
  }

  if(this->_clkMinute == 30) {
    this->update();
  }
  
  // Actualisation du réveil
  if(this->_clkMinute % 5 == 0) {
    //updateAlarm();
  }
}
  
int TimeFunctions::getDayTimestamp()
{
  return this->_clkHour * 60 + this->_clkMinute;
}

int TimeFunctions::getWeekDay()
{
  return this->_clkWeekDay;
}

int TimeFunctions::getMonth()
{
  return this->_clkMonth;
}

int TimeFunctions::getDay()
{
  return this->_clkDay;
}

int TimeFunctions::getHour()
{
  return this->_clkHour;
}

int TimeFunctions::getMinute()
{
  return this->_clkMinute;
}
