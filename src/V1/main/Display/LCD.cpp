#include "LCD.h"
#include "LiquidCrystal.h"
LCD::LCD(lcdPins pins){
    _pins=pins;
}
void LCD::initiateLCD(){
    _LCD=new LiquidCrystal(_pins.RS,_pins.RW,_pins.EN,_pins.D4,_pins.D5,_pins.D6,_pins.D7);
    _initiated=true;
}
lcdPins LCD::setLCDPins(lcdPins pins){
    if(!initiated){
    _pins=pins;
    return _pins;
    }else(
        return pins;
    )
}
LiquidCrystal LCD::getLCD(){
    return _LCD;
}

bool isInitiated(){
    return _initiated;
}