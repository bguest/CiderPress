#include "HC_SC04.h"

#define MAXIMUM_DURATION 12000
#define MINIMUM_DURATION 0

void HC_SC04::init(uint8_t echoPin, uint8_t trigPin){
  _echoPin = echoPin;
  _trigPin = trigPin;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  isSuccess = false;
}

void HC_SC04::run(){
  
 /* The following trigPin/echoPin cycle is used to determine the
  * distance of the nearest object by bouncing soundwaves off of it.
  */
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(_trigPin, LOW);
  duration = pulseIn(_echoPin, HIGH);

  if(duration >= MAXIMUM_DURATION || duration <= MINIMUM_DURATION){
    isSuccess = false;
  }else{
    isSuccess = true;
  }

}

uint8_t HC_SC04::cm(){
  //Calculate the distance (in cm) based on the speed of sound.
  return duration/58.2;
}
