#include "Indicator.h"
#include "Valve.h"

#define BLINK_TIME 100

void Indicator::init(uint8_t red, uint8_t green){
  redPin = red;
  greenPin = green;

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  lastUpdate = 0;
  isRed = false;
}

void Indicator::setDistance(uint8_t distance, uint8_t high, uint8_t valveState){
  if(distance < high){
    unsigned long currMillis = millis();
    if(currMillis - lastUpdate > BLINK_TIME){
      if(isRed){
        digitalWrite(greenPin, HIGH);
        digitalWrite(redPin, LOW);
        isRed = false;
      }else{
        digitalWrite(greenPin, LOW);
        digitalWrite(redPin, HIGH);
        isRed = true;
      }
    }
  }else if(valveState == VALVE_ON){
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
  }else{
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }
}
