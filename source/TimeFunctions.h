#ifndef TIME_FUNCTIONS_H
#define TIME_FUNCTIONS_H

#include "NTP.h"

class TimeFunctions {
  
  public:
  
    void setup(NTP& ntp);
    void setMode12Enabled(bool);
    void addMinuteToClk();
    void update();
    int getDayTimestamp();
    int getWeekDay();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();

  private:

    int _clkHour;
    int _clkMinute;
    int _clkSecond;
    int _clkDay;
    int _clkWeekDay;
    int _clkMonth;
    bool _mode12Enabled = false;
    NTP *_ntp;

};

#endif