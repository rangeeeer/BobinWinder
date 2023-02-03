#ifndef Initiator_h
#define Initiator_h
#include "Arduino.h"
typedef struct InitPins {

    // display pins
    uint8_t displayRsPin;
    uint8_t displayRwPin;
    uint8_t displayEnPin;
    uint8_t displayD4pin;
    uint8_t displayD5pin;
    uint8_t displayD6pin;
    uint8_t displayD7pin;

    // hall sensor pins
    uint8_t winderHalAnalogPin;
    uint8_t holderHalAnalogPin;

    // motor pins
    uint8_t winderDirPin;
    uint8_t winderClkPin;
    uint8_t holderDirPin;
    uint8_t holderClkPin;
    uint8_t motorsEnPin;
    // button pins
    uint8_t DbuttonPin;
    uint8_t MbuttonPin;
    uint8_t UbuttonPin;

    // potentiometer pin
    uint8_t potentiometerAnalogPin;
    

} InitPins;

typedef struct InitVars {

    uint16_t winderSPT; //step per turn
    uint8_t  winderDriverMP; // driver micro step
    uint16_t holderSPT; //step per turn
    uint8_t  holderDriverMP; // driver micro step
    uint16_t holderScrewPitchMM;  //holder Screw pitch in micro meter
    uint32_t debounceDelayMS;  //debounce delay in micro seconds
    uint8_t  pulseTimeMS;  //pulse time in micro seconds
} InitVars;

typedef struct InitData {
    InitPins pins;
    InitVars vars;
} InitData;

class Initiator {
public:
    Initiator(InitPins pins, InitVars vars);
    // LiquidCrystalDisplay pin  Initiation
    void SetDisplayPins(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);

    // Methods for hall sensor pin Initiation
    void SetWinderhallPin(uint8_t analogpin);
    void SetHolderHallPin(uint8_t analogpin);

    // Methods for Steppermotor Driver pins initiation
    void SetWinderStepperDriverPin(uint8_t dir, uint8_t clk, uint8_t enb);
    void SetHolderStepperDriverPin(uint8_t dir, uint8_t clk, uint8_t enb);

    // Method for Button pin initiation
    void SetUpButtonPin(uint8_t pin);
    void SetMidButtonPin(uint8_t pin);
    void SetDownButtonPin(uint8_t pin);

    InitData getInitiator();

    // Other Methods

private:
    // pins
    InitPins _PINS;
    // variables
    InitVars _VARS;
};

#endif