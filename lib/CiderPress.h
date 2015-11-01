#ifndef CIDER_PRESS_H
#define CIDER_PRESS_H

#define IR_PIN 3
#define ECHO_PIN 4 // Echo Pin
#define TRIG_PIN 5 // Trigger Pin
#define DISPLAY_RX 8
#define DISPLAY_TX 9
#define LED_PIN 13 // Onboard LED
#define VALVE_PIN 2
#define RED_PIN A0
#define GREEN_PIN A1

#include "Arduino.h"
#include "Display.h"
#include "HC_SC04.h"
#include "Valve.h"
#include "Indicator.h"

class CiderPress{
  public:
    void init();
    void run();
  private:
    HC_SC04 hc_sc04;
    Display display;
    Valve valve;
    Indicator indicator;
};


#endif
