#include "StepperMotor.h"
StepperMotor::StepperMotor(int ClickPin, int DirectionPin, int DriverMicroStep, int PulseTimeMicroSeconds, bool StraitDirection ) {
  _ClickPin = ClickPin;
  _DirectionPin = DirectionPin;
  _DriverMicroStep = DriverMicroStep;
  _PulseTime = PulseTimeMicroSeconds;
  _StraitDirection = StraitDirection;
}

void StepperMotor::Check() {
  if (_PulseState) {
    if (micros() - _PulseStartTime > _PulseTime) {
      digitalWrite(_ClickPin, LOW);
      _PulseState = false;
    }
  }
  else {
    digitalWrite(_ClickPin, HIGH);
    _PulseState = true;
  }
}

void StepperMotor::SetDirection(bool Direction) {
  if (_StraitDirection) {
    _Direction = Direction;
  }
  else {
    _Direction = (!Direction);
  }
  if (_Direction == _StraitDirection) {
    digitalWrite(_DirectionPin, HIGH);
  }
  else {
    digitalWrite(_DirectionPin, LOW);
  }

}
int StepperMotor::GetMicroStep() {
  return _DriverMicroStep;
}
bool StepperMotor::GetState() {
  return _PulseState;
}

void StepperMotor::Pulse() {
  if (!_PulseState) {
    _PulseStartTime = micros();
    _PulseState = true;
  }
}
