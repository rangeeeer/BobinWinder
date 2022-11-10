#include "Initiator.h"

Initiator::Initiator(InitPins pins, InitVars vars)
{
    _PINS = pins;
    _VARS = vars;
}

void Initiator::SetDisplayPins(uint8_t rs, uint8_t rw, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
}

// Methods for hall sensor pin Initiation
void Initiator::SetWinderhallPin(uint8_t analogpin) { }
void Initiator::SetHolderHallPin(uint8_t analogpin) { }

// Methods for Steppermotor Driver pins initiation
void Initiator::SetWinderStepperDriverPin(uint8_t dir, uint8_t clk, uint8_t enb) { }
void Initiator::SetHolderStepperDriverPin(uint8_t dir, uint8_t clk, uint8_t enb) { }

// Method for Button pin initiation
void Initiator::SetUpButtonPin(uint8_t pin) { }
void Initiator::SetMidButtonPin(uint8_t pin) { }

void Initiator::SetDownButtonPin(uint8_t pin) { }
InitData Initiator::getInitData(){
    InitData data={ _PINS, _VARS };
    return data;
}