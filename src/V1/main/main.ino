#include "Engine.h"
#include "Initiator.h"

InitPins pins;
InitVars vars;

// display pins

void setup()
{

    // display pins
    pins.DISPLAY_RS_PIN = 0;
    pins.DISPLAY_RW_PIN = 1;
    pins.DISPLAY_EN_PIN = 2;
    pins.DISPLAY_D4_PIN = 3;
    pins.DISPLAY_D5_PIN = 4;
    pins.DISPLAY_D6_PIN = 5;
    pins.DISPLAY_D7_PIN = 6;



    // sensor pins
    pins.WINDER_HALL_ANALOG_PIN = 10;
    pins.HOLDER_HALL_ANALOG_PIN = 11;



    // motor pins
    pins.WINDER_DIRECTION_PIN = 12;
    pins.WINDER_CLICK_PIN = 13;
    pins.WINDER_ENABLE_PIN = 14;
    pins.HOLDER_DIRECTION_PIN = 15;
    pins.HOLDER_CLICK_PIN = 16;
    pins.HOLDER_ENABLE_PIN = 17;



    // button pins
    pins.DOWN_BUTTON_PIN = 18;
    pins.MID_BUTTON_PIN = 19;
    pins.UP_BUTTON_PIN = 20;

    // define constants
    vars.WINDER_MOTOR_PULSE_PER_TURN = 200;
    vars.WINDER_MOTOR_DRIVER_MICROPULSE = 16;
    vars.HOLDER_MOTOR_PULSE_PER_TURN = 200;
    vars.HOLDER_MOTOR_DRIVER_MICROPULSE = 16;
    vars.HOLDER_SCREW_PITCH_MICROMETER = 1500;
    vars.DEBOUNCE_DELAY_MICROSECONDS = 100000;
    vars.PULSE_TIME_MICROSECOND = 1;
    Initiator initiator(pins, vars);
    Engine eng(initiator.getInitiator());
    delete InitVars;
    eng.start();
}

void loop() { }
