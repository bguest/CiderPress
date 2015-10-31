#include "CiderPress.h"

#define ECHO_PIN 3 // Echo Pin
#define TRIG_PIN 4 // Trigger Pin
#define LED_PIN 13 // Onboard LED

void CiderPress::init(){

  pinMode(LED_PIN, OUTPUT);

  hc_sc04.init(ECHO_PIN, TRIG_PIN);
  display.init();
}

void CiderPress::run(){

  hc_sc04.run();

  if(hc_sc04.isSuccess){
    uint8_t distance = hc_sc04.cm();
    //tap.setDistance(distance);
    display.setDistance(distance);
  }

  delay(50);
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);

}



