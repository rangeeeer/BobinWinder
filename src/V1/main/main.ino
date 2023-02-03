#include "Engine.h"
#include "Initiator.h"
#include "DebouncedPushButton.h"
InitPins pins;
InitVars vars;

// display pins

void setup()
{

    // display pins
    pins.displayRsPin = 16;
    pins.displayRwPin = 17;
    pins.displayEnPin = 18;
    pins.displayD4pin = 19;
    pins.displayD5pin = 21;
    pins.displayD6pin = 22;
    pins.displayD7pin = 23;

    // sensor pins
    pins.winderHalAnalogPin = 35;
    pins.holderHalAnalogPin = 32;

    // motor pins
    pins.winderDirPin = 26;
    pins.winderClkPin = 25;
    pins.holderDirPin = 14;
    pins.holderClkPin = 27;
    pins.motorsEnPin = 33;
    pins.potentiometerAnalogPin = 13;

    // button pins
    pins.DbuttonPin = 18;
    pins.MbuttonPin = 19;
    pins.UbuttonPin = 20;

    // define constants
    vars.winderSPT = 200;
    vars.winderDriverMP = 8;
    vars.holderSPT = 200;
    vars.holderDriverMP = 8;
    vars.holderScrewPitchMM = 1500;
    vars.debounceDelayMS = 100000;
    vars.pulseTimeMS = 30;

    pinMode(pins.winderClkPin, OUTPUT);
    pinMode(pins.winderDirPin, OUTPUT);
    pinMode(pins.holderClkPin, OUTPUT);
    pinMode(pins.holderDirPin, OUTPUT);
    pinMode(pins.potentiometerAnalogPin, INPUT);

    int numberOfTurns = 10000;
    int wireDiameterUM = 50;
    int windingScater = 50;
    int count = 10000;
    bool start = false;
    bool pause = false;
    int delay;
    int distanceturn = wireDiameterUM + (wireDiameterUM * windingScater / 100);
    int bobinWidthUM = 11500;
    int winderpulsePosition = 0;
    int winderPPT=vars.winderSPT*vars.winderDriverMP
    int holderPPT=vars.holderSPT*vars.holderDriverMP
    

    while (true)
    {   
        digitalWrite(pins.holderDirPin, HIGH);
        for (int i = 0; i < count; i++)
        {
            delay = potcalc(pins.potentiometerAnalogPin);
            digitalWrite(pins.holderClkPin, HIGH);
            digitalWrite(pins.winderClkPin, HIGH);
            delayMicroseconds(vars.pulseTimeMS);
            digitalWrite(pins.holderClkPin, LOW);
            digitalWrite(pins.winderClkPin, LOW);
            delayMicroseconds(delay);
        }
        digitalWrite(pins.holderDirPin, LOW);
        for (int i = 0; i < count; i++)
        {
            delay = potcalc(pins.potentiometerAnalogPin);
            digitalWrite(pins.holderClkPin, HIGH);
            digitalWrite(pins.winderClkPin, HIGH);
            delayMicroseconds(vars.pulseTimeMS);
            digitalWrite(pins.holderClkPin, LOW);
            digitalWrite(pins.winderClkPin, LOW);
            delayMicroseconds(delay);
        }
    }
    Initiator initiator(pins, vars);
    Engine eng(initiator.getInitiator());
    eng.start();
}

int potcalc(uint8_t pin){
    int var= analogRead(pin);
    return (var/4) + 30;
}
void loop() { }
