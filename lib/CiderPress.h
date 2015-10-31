#ifndef CIDER_PRESS_H
#define CIDER_PRESS_H

#include "Arduino.h"
#include "Display.h"
#include "HC_SC04.h"

class CiderPress{
  public:
    void init();
    void run();
  private:
    HC_SC04 hc_sc04;
    Display display;
};


#endif
