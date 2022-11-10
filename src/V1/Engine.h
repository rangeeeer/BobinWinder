#ifndef Engine_h
#define Engine_h
#include "Arduino.h"
#include "Initiator.h"

extern uint16_t WINDER_GOAL_TURNS;
extern uint16_t WINDER_ANGLE_IN_PULSE;
extern uint16_t WINDER_TURNS;
extern uint16_t HOLDER_SCREW_POSITION_MICROMETER;
extern bool HOLDER_DIRECTION;
extern bool START_CLICK;
extern bool PAUSE;
extern bool STOP;
class Engine{
    public:
        Engine(InitData);
        void start();
    private:
        InitData _data;
};

#endif