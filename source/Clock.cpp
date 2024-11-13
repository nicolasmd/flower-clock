#include "Clock.h"


void Clock::setup()
{
    // Setups
    this->_led.setup();
    this->_digit.setup();
    this->_clock.setup();
    this->_timeFunctions.setup(ntp);
    this->_temperature.setup(ahtSensor);
    this->_network.connect();

    pinMode(Clock::SET_BUTTON_PIN, INPUT_PULLUP);
    pinMode(Clock::MINUTE_BUTTON_PIN, INPUT_PULLUP);
    pinMode(Clock::HOUR_BUTTON_PIN, INPUT_PULLUP);
    pinMode(Clock::ALARM_BUTTON_PIN, INPUT_PULLUP);
}

void Clock::loop()
{
    // Minute timer
    if (millis() - this->_previousUpdate > Clock::UPDATE_TIME_DURATION) {
        this->_timeFunctions.addMinuteToClk();
        this->_previousUpdate = millis();
    }

    // Do action
    this->_doActionByMode();

    // Return to time mode ?
    if(this->_hasToReturnToTimeMode()) {
        this->setMode(Clock::MODE_TIME);
        this->_led.uniColor(Led::C_OFF);
    }

    // Get button actions
    int setBtnVal = digitalRead(SET_PIN);
    int alrBtnVal = digitalRead(ALR_PIN);


}

int Clock::getMode()
{
    return this->_mode;
}

void Clock::setMode(int mode)
{
    this->_mode = mode;
}


void Clock::_doActionByMode()
{
    switch(this->getMode()) {
        case Clock::MODE_TIME:
            this->_displayTime();
            break;
        case Clock::MODE_DATE:
            this->_displayDate();
            break;
        case Clock::MODE_TEMPERATURE:
            this->_displayTemperature();
            break;
        case Clock::MODE_ALARM:
            this->_displayAlarm();
            break;
    }
}

bool Clock::_hasToReturnToTimeMode()
{
    if(this->getMode() == Clock::MODE_TIME) {
        return false;
    }
    return (millis() - this->_previousSetMode > Clock::SET_MODE_DURATION);
}


void Clock::_displayTime()
{
    this->_digit.displayDigit(1, floor(this->_timeFunctions.getHour() / 10));
    this->_digit.displayDigit(2, floor(this->_timeFunctions.getHour() % 10));
    this->_digit.displayDigit(3, floor(this->_timeFunctions.getMinute() / 10));
    this->_digit.displayDigit(4, floor(this->_timeFunctions.getMinute() % 10));
}

void Clock::_displayDate()
{
    this->_digit.displayDigit(1, floor(this->_timeFunctions.getDay() / 10));
    this->_digit.displayDigit(2, floor(this->_timeFunctions.getDay() % 10));
    this->_digit.displayDigit(3, floor(this->_timeFunctions.getMonth() / 10));
    this->_digit.displayDigit(4, floor(this->_timeFunctions.getMonth() % 10));
}

void Clock::_displayTemperature()
{
    int t = this->_temperature.getTemperature();
    if(t < Clock::TEMPERATURE_MIN || t > Clock::TEMPERATURE_MAX) {
        this->_digit.displayChar(1, "-");
        this->_digit.displayChar(2, "-");
        this->_digit.displayChar(3, "-");
        this->_digit.displayChar(4, "-");
    } else {
        this->_digit.displayDigit(1, floor(t / 1000));
        t = t - floor(t / 1000) * 1000;
        this->_digit.displayDigit(2, floor(t / 100));
        t = t - floor(t / 100) * 100;
        this->_digit.displayDigit(3, floor(t / 10));
        t = t - floor(t / 10) * 10;
        this->_digit.displayDigit(4, t);
    }
}

// @todo
void Clock::_displayAlarm()
{
    /*int alrTemp = alr;
    displayDigit(1, floor(alrTemp / 1000));
    alrTemp = alrTemp - floor(alrTemp / 1000) * 1000;
    displayDigit(2, floor(alrTemp / 100));
    alrTemp = alrTemp - floor(alrTemp / 100) * 100;
    displayDigit(3, floor(alrTemp / 10));
    alrTemp = alrTemp - floor(alrTemp / 10) * 10;
    displayDigit(4, alrTemp);*/
}
