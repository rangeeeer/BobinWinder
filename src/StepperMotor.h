#ifndef StepperMotor_h
#define StepperMotor_h
#include <Arduino.h>


class StepperMotor {
  public:
    StepperMotor(int ClickPin, int DirectionPin, int DriverMicroStep, int PulseTimeMicroSeconds, bool StraitDirection );
    void Check() ;
    void SetDirection(bool Direction) ;
    int GetMicroStep() ;
    bool GetState() ;
    void Pulse();
  private:
    int _ClickPin;
    int _DirectionPin;
    bool _Direction;
    bool _PulseState;
    unsigned long _PulseStartTime;
    int _DriverMicroStep;
    int _PulseTime;
    bool _StraitDirection;
};

#endif
