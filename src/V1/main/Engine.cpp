#include "Engine.h"
#include "Initiator.h"
#include "Arduino.h"
#include "Display/DisplayCore.h"



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

 
void Engine::ControlTaskFunction(void * parameter) {
  while(true){
    Serial.println(xPortGetCoreID());
    delay(1000);
  }
}

void Engine::DisplayTaskFunction(void * parameter) {
  while(true){
    Serial.println(xPortGetCoreID());
    delay(1000);
  }
}
Engine::Engine(InitData data) {
  _data = data;
}
void Engine::start() {
  Serial.begin(115200);
  xTaskCreatePinnedToCore(ControlTaskFunction, "ControlTask", 10000, NULL, 1, &ControlTask, 1);
  xTaskCreatePinnedToCore(DisplayTaskFunction, "DisplayTask", 10000, NULL, 1, &DisplayTask, 0);
}
