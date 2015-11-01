#ifndef INDICATOR_H
#define INDICATOR_H

#include "Arduino.h"

class Indicator{

  public:
    void init(uint8_t red, uint8_t green);
    void setDistance(uint8_t distance, uint8_t high, uint8_t low);

  private:
    uint8_t redPin;
    uint8_t greenPin;
    unsigned long lastUpdate;
    bool isRed;
};


#endif
