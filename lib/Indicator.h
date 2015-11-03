#ifndef INDICATOR_H
#define INDICATOR_H

#include "Arduino.h"

typedef enum{
  IndicatorOff = 0,
  IndicatorRed = 1,
  IndicatorGreen = 2
} IndicatorColor;

class Indicator{

  public:
    void init(uint8_t red, uint8_t green);
    void setDistance(uint8_t distance, uint8_t high, uint8_t low);
    void blinkMillis(uint16_t millis);
    void run();

  private:
    void blink();

    uint8_t redPin;
    uint8_t greenPin;
    unsigned long lastUpdate;
    bool isRed;
    IndicatorColor currColor;
    unsigned long blinkEnd;
};


#endif
