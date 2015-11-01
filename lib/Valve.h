#ifndef VALVE_H
#define VALVE_H

#define VALVE_ON 1
#define VALVE_OFF 0
#define VALVE_AUTOMATIC 2

#include "Arduino.h"

class Valve{

  public:
    void init(uint8_t valvePin, uint8_t high, uint8_t low);
    void setDistance(uint8_t distance);
    void setMode(uint8_t mode);
    uint8_t valveState();
    uint8_t highMark;
    uint8_t lowMark;

  private:
    uint8_t _valveState;
    uint8_t _mode;
    uint8_t _valvePin;
};

#endif
