#ifndef HC_SC04_H
#define HC_SC04_H

#include "Arduino.h"

class HC_SC04{
  public:
    void init(uint8_t trigPin, uint8_t echoPin);
    void run();
    uint8_t cm();
    long duration;
    bool isSuccess;


  private:
    uint8_t _trigPin;
    uint8_t _echoPin;
};

#endif
