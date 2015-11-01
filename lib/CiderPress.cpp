#include "CiderPress.h"

void CiderPress::init(){

  pinMode(LED_PIN, OUTPUT);

  hc_sc04.init(ECHO_PIN, TRIG_PIN);
  display.init();
  valve.init(VALVE_PIN, 30, 100);
  indicator.init(RED_PIN, GREEN_PIN);
}

void CiderPress::run(){

  hc_sc04.run();

  if(hc_sc04.isSuccess){
    uint8_t distance = hc_sc04.cm();
    valve.setDistance(distance);
    display.setDistance(distance);
    indicator.setDistance(distance, valve.highMark, valve.valveState());
  }

  delay(50);
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);

}



