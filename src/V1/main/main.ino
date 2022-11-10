#include "Initiator.h"
#include "Engine.h"

InitPins pins{
    // display pins
    DISPLAY_RS_PIN = 0;
    DISPLAY_RW_PIN = 1;
    DISPLAY_EN_PIN = 2;
    DISPLAY_D4_PIN = 3;
    DISPLAY_D5_PIN = 4;
    DISPLAY_D6_PIN = 5;
    DISPLAY_D7_PIN = 6;
    // sensor pins
    WINDER_HALL_ANALOG_PIN = 10;
    HOLDER_HALL_ANALOG_PIN = 11;
    // motor pins
    WINDER_DIRECTION_PIN = 12;
    WINDER_CLICK_PIN = 13;
    WINDER_ENABLE_PIN = 14;
    HOLDER_DIRECTION_PIN = 15;
    HOLDER_CLICK_PIN = 16;
    HOLDER_ENABLE_PIN = 17;
    // button pins
    DOWN_BUTTON_PIN = 18;
    MID_BUTTON_PIN = 19;
    UP_BUTTON_PIN = 20;
};

InitVars vars{
  WINDER_MOTOR_PULSE_PER_TURN = 200;
  WINDER_MOTOR_DRIVER_MICROPULSE = 16;
  HOLDER_MOTOR_PULSE_PER_TURN = 200;
  HOLDER_MOTOR_DRIVER_MICROPULSE = 16;
  HOLDER_SCREW_PITCH_MICROMETER = 1500;
  DEBOUNCE_DELAY_MICROSECONDS = 100000;
  PULSE_TIME_MICROSECOND = 1; 
};


void setup()
{
  Initiator init(pins,vars);
  Engige    core(init)
}

void loop(){}
