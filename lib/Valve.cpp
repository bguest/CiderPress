#include "Valve.h"

void Valve::init(uint8_t valvePin, uint8_t high, uint8_t low){
  _valvePin = valvePin;
  pinMode(valvePin, OUTPUT);
  _mode = VALVE_AUTOMATIC;

  highMark = high;
  lowMark = low;
}

void Valve::setMode(uint8_t mode){
  _mode = mode;
  if(_mode == VALVE_ON || _mode == VALVE_OFF){
    _valveState = _mode;
    digitalWrite(_valvePin, _mode);
  }
}
uint8_t Valve::valveState(){
  return _valveState;
}

void Valve::setDistance(uint8_t distance){
  if(_mode != VALVE_AUTOMATIC){
    return;
  }

  if(distance > lowMark){
    digitalWrite(_valvePin, VALVE_OFF);
    _valveState = VALVE_OFF;
  }else if(distance < highMark){
    digitalWrite(_valvePin, VALVE_ON);
    _valveState = VALVE_ON;
  }

}


