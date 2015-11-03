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
  blinkEnd = 0;
}

void Indicator::blinkMillis(uint16_t time){
  blinkEnd = millis() + time;
}

void Indicator::blink(){
  unsigned long currMillis = millis();
  if(currMillis - lastUpdate > BLINK_TIME){
    lastUpdate = currMillis;
    if(isRed){
      currColor = IndicatorRed;
      isRed = false;
    }else{
      currColor = IndicatorGreen;
      isRed = true;
    }
  }
}

void Indicator::run(){

  if(millis() < blinkEnd){
    this -> blink();
  }

  switch(currColor){
    case IndicatorOff:
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, LOW);
      break;
    case IndicatorGreen:
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
      break;
    case IndicatorRed:
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, HIGH);
      break;
  }
}

void Indicator::setDistance(uint8_t distance, uint8_t high, uint8_t valveState){
  if(valveState == VALVE_AUTOMATIC){
    return;
  }
  if(distance < high){
    this -> blink();
  }else if(valveState == VALVE_ON){
    currColor = IndicatorGreen;
  }else{
    currColor = IndicatorRed;
  }
}
