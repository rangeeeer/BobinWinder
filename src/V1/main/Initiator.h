#ifndef Initiator_h
#define Initiator_h
#include "Arduino.h"
typedef struct InitPins {

    // display pins
    uint8_t DISPLAY_RS_PIN;
    uint8_t DISPLAY_RW_PIN;
    uint8_t DISPLAY_EN_PIN;
    uint8_t DISPLAY_D4_PIN;
    uint8_t DISPLAY_D5_PIN;
    uint8_t DISPLAY_D6_PIN;
    uint8_t DISPLAY_D7_PIN;
    // sensor pins
    uint8_t WINDER_HALL_ANALOG_PIN;
    uint8_t HOLDER_HALL_ANALOG_PIN;

    // motor pins
    uint8_t WINDER_DIRECTION_PIN;
    uint8_t WINDER_CLICK_PIN;
    uint8_t WINDER_ENABLE_PIN;
    uint8_t HOLDER_DIRECTION_PIN;
    uint8_t HOLDER_CLICK_PIN;
    uint8_t HOLDER_ENABLE_PIN;
    // button pins
    uint8_t DOWN_BUTTON_PIN;
    uint8_t MID_BUTTON_PIN;
    uint8_t UP_BUTTON_PIN;
} InitPins;

typedef struct InitVars {

    uint16_t WINDER_MOTOR_PULSE_PER_TURN;
    uint8_t WINDER_MOTOR_DRIVER_MICROPULSE;
    uint16_t HOLDER_MOTOR_PULSE_PER_TURN;
    uint8_t HOLDER_MOTOR_DRIVER_MICROPULSE;
    uint16_t HOLDER_SCREW_PITCH_MICROMETER;
    uint32_t DEBOUNCE_DELAY_MICROSECONDS;
    uint8_t PULSE_TIME_MICROSECOND;
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