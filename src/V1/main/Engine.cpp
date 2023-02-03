#include "Engine.h"
#include "Initiator.h"
#include "Arduino.h"
#include "Display/DisplayCore.h"


uint8_t menu[4]={0,0,0,0};
uint16_t WINDER_GOAL_TURNS = 1000;
uint16_t WINDER_ANGLE_IN_PULSE = 0;
uint16_t WINDER_TURNS = 0;
uint16_t HOLDER_SCREW_POSITION_MICROMETER = 0;
bool HOLDER_DIRECTION = true;
bool START_CLICK = false;
bool PAUSE = false;
bool STOP = true;
TaskHandle_t DisplayTask;
TaskHandle_t ControlTask;

InitData vars_pins;
 
void ControlTaskFunction(void * parameter) {
  while(true){
    delay(1000);
  }
}

void DisplayTaskFunction(void * parameter) {
  while(true){
    delay(1000);
  }
}
Engine::Engine(InitData enginePins) {
  vars_pins = enginePins;
}
void Engine::start() {
  xTaskCreatePinnedToCore(ControlTaskFunction, "ControlTask", 10000, NULL, 1, &ControlTask, 1);
  xTaskCreatePinnedToCore(DisplayTaskFunction, "DisplayTask", 10000, NULL, 1, &DisplayTask, 0);
}
