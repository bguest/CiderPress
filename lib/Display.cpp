#include "Display.h"
#include "CiderPress.h"

Display::Display(){
  Serial7Segment = new SoftwareSerial(DISPLAY_RX, DISPLAY_TX);
}

void Display::init(){

  Serial7Segment -> begin(9600); //Talk to the Serial7Segment at 9600 bps
  Serial7Segment -> write('v'); //Reset the display - this forces the cursor to return to the beginning of the display

}

void Display::setDistance(uint8_t distance){
   int c = distance;
   char tempString[10]; //Used for sprintf
   sprintf(tempString, "%4d", c); //Convert deciSecond into a string that is right adjusted
   Serial7Segment -> print(tempString); //Send serial string out the soft serial port to the S7S
}

