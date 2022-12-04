#ifndef LCD_h
#define LCD_h
#include "LiquidCrystal.h"
#include "Arduino.h"
typedef struct lcdPins{
    uint8_t RS;
    uint8_t RW;
    uint8_t EN;
    uint8_t D0;
    uint8_t D1;
    uint8_t D2;
    uint8_t D3;
    uint8_t D4;
    uint8_t D5;
    uint8_t D6;
    uint8_t D7;
    
} lcdPins;

class LCD{
    public:
        LCD(lcdPins pins);
        void initiateLCD();
        lcdPins setLCDPins();
        LiquidCrystal getLCD();
        bool isInitiated();
    private:
        bool _initiated;
        lcdPins _pins;
        LiquidCrystal _LCD;
        
};


#endif