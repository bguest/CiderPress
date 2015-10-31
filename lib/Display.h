#ifndef DISPLAY_H
#define DISPLAY_H

#include "Arduino.h"
#include <SoftwareSerial.h>

class Display{
  public:
    Display();
    void init();
    void setDistance(uint8_t distance);

  private:
    uint8_t currentMode;
    SoftwareSerial *Serial7Segment;
};

#endif
