#include "Arduino.h"
#include <SoftwareSerial.h>

#include "CiderPress.h"
CiderPress ciderPress;

void setup() {
  Serial.begin (9600);
  ciderPress.init();
}

void loop() {

  ciderPress.run();
}
