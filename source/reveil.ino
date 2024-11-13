#include "Clock.h"

Clock clock;

int alr; // fake
int alrHour;
int alrMinute;

int isAlrEnabled = 0;


String line;

int turns = 0;
int sequence[] = {1, 3, 2, 6, 7, 5, 4};


void setup() {
    Serial.begin(9600);
    clock.setup();
}


// Vérifications displayOff (extinction de la lumière)
  /*if(ts > 1320 || ts < 480) {
    setMode = -1;
    displayOff();
  } else {
    // displayOn
    if(setMode == -1) {
      setMode = 0;
    }
  }*/


void loop() {

  clock.loop(millis());


  if(setBtnVal == LOW) {
    //Serial.println("setBtnVal = LOW");
    // Change mode
    setMode = setMode + 1;
    //Serial.print("setMode = "); Serial.println(setMode);
    if(setMode >= 3) {
      setMode = 0;
      ledUniColor(0);
    }
    
    // INIT MODES
    if(setMode == -1) {
      // date
      displayTime();
    }
    if(setMode == 1) {
      // date
      previousSet = millis();
      int leds[] = {0, 0, 0, 0, 0, 0, 0};
      leds[timeFunctions.getWeekDay()] = timeFunctions.getWeekDay() + 1;
      
      ledArrColor(leds);
    }
    if(setMode == 2) {
      // temperature
      setColorByTemperature(temperature.getTemperature());
      previousSet = millis();
      
    }
    delay(500);
  }
  // INIT ALARM
  if(alrBtnVal == LOW) {
    Serial.println("alrBtnVal = LOW");
    if(setMode == 0) {
      Serial.println("setMode = 10");
      setMode = 10;
      previousSet = millis();
      ledUniColor(5);
      updateAlarm();
    }

  }
  
}


void setColorByTemperature(int t)
{
  if(t >= 2200) {
    ledUniColor(4);
  }
  if(t < 2200 && t >= 1900) {
    ledUniColor(2);
  }
  if(t < 1900) {
    ledUniColor(1);
  }
}




