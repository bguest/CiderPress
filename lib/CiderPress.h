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

#define PLAY_PAUSE_IR 0x31F0E936
#define MENUE_IR      0xD14F58B0
#define UP_IR         0x17E1F858
#define DOWN_IR       0x8EBB3CFC
#define LEFT_IR       0xC26B4710
#define RIGHT_IR      0xFA0E2992
#define CENTER        0x133620BA

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
