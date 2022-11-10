#include "Engine.h"
#include "Initiator.h"
#include "Arduino.h"



uint16_t WINDER_GOAL_TURNS = 1000;
uint16_t WINDER_ANGLE_IN_PULSE = 0;
uint16_t WINDER_TURNS = 0;
uint16_t HOLDER_SCREW_POSITION_MICROMETER = 0;
bool HOLDER_DIRECTION = true;
bool START_CLICK = false;
bool PAUSE = false;
bool STOP = true;
Engine::Engine(InitData data){
    _data=data;
}


void Engine::start(){
    Serial.begin(115200);
    Serial.println("Engine is running");
    Serial.print("code is running on core ");
    Serial.println(xPortGetCoreID());
}