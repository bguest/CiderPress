#include "CiderPress.h"

CiderPress::CiderPress(){
  irrecv = new IRrecv(IR_PIN);
}

void CiderPress::init(){

  pinMode(LED_PIN, OUTPUT);

  hc_sc04.init(ECHO_PIN, TRIG_PIN);
  display.init();
  valve.init(VALVE_PIN, 30, 100);
  indicator.init(RED_PIN, GREEN_PIN);
  irrecv -> enableIRIn();
}

void CiderPress::run(){

  hc_sc04.run();

  if(hc_sc04.isSuccess){
    distance = hc_sc04.cm();
    valve.setDistance(distance);
    display.setDistance(distance);
    indicator.setDistance(distance, valve.highMark, valve.valveState());
  }

  if (irrecv -> decode(&irResults)) {
    //Serial.println(results.value, HEX);
    indicator.blinkMillis(100);
    this -> handleIrCode(irResults.value);
    irrecv -> resume(); // Receive the next value
  }

  indicator.run();

  delay(50);
  digitalWrite(LED_PIN, HIGH);
  delay(50);
  digitalWrite(LED_PIN, LOW);

}

void CiderPress::handleIrCode(uint32_t irCode){
  Serial.println(irCode, HEX);

  switch(irCode){
    case PLAY_PAUSE_IR_0: case PLAY_PAUSE_IR_1:
      valve.setMode(VALVE_ON);
      indicator.blinkMillis(500);
      break;
    case MENUE_IR_0: case MENUE_IR_1:
      valve.setMode(VALVE_OFF);
      indicator.blinkMillis(500);
      break;
    case UP_IR_0: case UP_IR_1:
      valve.highMark = distance;
      indicator.blinkMillis(500);
      break;
    case DOWN_IR_0: case DOWN_IR_1:
      valve.lowMark = distance;
      indicator.blinkMillis(500);
      break;
    case LEFT_IR_0: case LEFT_IR_1:
      break;
    case RIGHT_IR_0: case RIGHT_IR_1:
      break;
    case CENTER_0: case CENTER_1:
      Serial.println("AUTO");
      indicator.blinkMillis(500);
      valve.setMode(VALVE_AUTOMATIC);
      break;
  }

}



