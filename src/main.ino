
#include "DebouncedPushButton.h"
#include "StepperMotor.h"


///////////////////////////////
//                           //
//     WIRING_GPIO_PINS      //
//                           //
///////////////////////////////

int HOLDER_CW_PIN    = 0  ;
int HOLDER_CL_PIN    = 5  ;
int WINDER_CW_PIN    = 15 ;
int WINDER_CL_PIN    = 2  ;
int PUSH_BUTTON_PIN  = 13 ;




///////////////////////////////
//                           //
// MECHANICAL-SPECIFICATIONS //
//                           //
///////////////////////////////

int WINDER_MOTOR_PULSE_PER_TURN       = 200   ;
int WINDER_MOTOR_DRIVER_MICROPULSE    = 16    ;
int HOLDER_MOTOR_PULSE_PER_TURN       = 200   ;
int HOLDER_MOTOR_DRIVER_MICROPULSE    = 16    ;
int HOLDER_SCREW_PITCH_MICROMETER     = 1500  ;




///////////////////////////////
//                           //
//     TIMING-VARIABLES      //
//                           //
///////////////////////////////

long DEBOUNCE_DELAY_MICROSECONDS         = 100000 ;
int  PULSE_TIME_MICROSECOND              = 1     ;
int  DELAY_BETWEN_PULSES_MICROSECOND     = 100  ;




///////////////////////////////
//                           //
//   DEVELOPMENT-VARIABLES   //
//                           //
///////////////////////////////

int WIRE_DIAMETER_MICROMETER  = 75    ;
int BOBIN_WIDTH_MICROMETER    = 10000 ;
int NUMBER_OF_TURNS           = 1000 ;




///////////////////////////////
//                           //
//      CLASS-VARIABLES      //
//                           //
///////////////////////////////

DebouncedPushButton btnStart(PUSH_BUTTON_PIN,DEBOUNCE_DELAY_MICROSECONDS,false);
StepperMotor WWM(WINDER_CL_PIN, WINDER_CW_PIN, WINDER_MOTOR_DRIVER_MICROPULSE, PULSE_TIME_MICROSECOND, true);
StepperMotor WHM(HOLDER_CL_PIN, HOLDER_CW_PIN, HOLDER_MOTOR_DRIVER_MICROPULSE, PULSE_TIME_MICROSECOND, true);



///////////////////////////////
//                           //
//          VARIABLES        //
//                           //
///////////////////////////////
int  WINDER_GOAL_TURNS = 1000;
int  WINDER_ANGLE_IN_PULSE = 0;
int  WINDER_TURNS = 0;
int  HOLDER_SCREW_POSITION_MICROMETER = 0;
bool HOLDER_DIRECTION = true;
bool START_CLICK = false;
bool PAUSE = false;
bool STOP = true;



void setup() {
  pinMode(HOLDER_CW_PIN, OUTPUT);
  pinMode(HOLDER_CL_PIN, OUTPUT);
  pinMode(WINDER_CW_PIN, OUTPUT);
  pinMode(WINDER_CL_PIN, OUTPUT);


}


void loop() {
  START_CLICK = btnStart.debouncedRead();
  if (START_CLICK) {
    STOP = false;
  }
  if (!STOP) {

    if (WINDER_TURNS >= WINDER_GOAL_TURNS) {

    }
  }

}
