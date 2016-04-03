#ifndef CIDER_PRESS_H
#define CIDER_PRESS_H

#define IR_PIN A3
#define ECHO_PIN 4 // Echo Pin
#define TRIG_PIN 5 // Trigger Pin
#define DISPLAY_RX 8
#define DISPLAY_TX 9
#define LED_PIN 13 // Onboard LED
#define VALVE_PIN 2
#define RED_PIN A0
#define GREEN_PIN A1

#define PLAY_PAUSE_IR_0 0x31F0E936
#define PLAY_PAUSE_IR_1 0xFFF18C59

#define MENUE_IR_0      0xD14F58B0
#define MENUE_IR_1      0x5F00BA93

#define UP_IR_0         0x17E1F858
#define UP_IR_1         0xA5935A3B

#define DOWN_IR_0       0x8EBB3CFC
#define DOWN_IR_1       0x1C6C9EDF

#define LEFT_IR_0       0xC26B4710
#define LEFT_IR_1       0x501CA8F3

#define RIGHT_IR_0      0xFA0E2992
#define RIGHT_IR_1      0xC80ECCB5

#define CENTER_0        0x133620BA
#define CENTER_1        0xE136C3DD

#include "Arduino.h"
#include "Display.h"
#include "HC_SC04.h"
#include "Valve.h"
#include "Indicator.h"
#include "IRremote.h" 

class CiderPress{

  public:
    CiderPress();
    void init();
    void run();

  private:
    HC_SC04 hc_sc04;
    Display display;
    Valve valve;
    Indicator indicator;
    IRrecv *irrecv;

    decode_results irResults;
    uint8_t distance;

    void handleIrCode(uint32_t irCode);

};


#endif
