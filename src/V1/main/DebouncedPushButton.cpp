#include "DebouncedPushButton.h"


DebouncedPushButton::DebouncedPushButton(int pin,long DebounceTimeUS,bool pullup) {
  _pin = pin; 
  _state = LOW;
  _lastState = LOW;
  _lastDebounceTime = micros();
  _DebounceTimeUS = DebounceTimeUS;
  _pullup = pullup;
  if(pullup){
  pinMode(pin,INPUT_PULLUP);
  }
  else{
    pinMode(pin,INPUT);
  }
}

bool DebouncedPushButton::debouncedRead() {
  int reading = digitalRead(_pin);
  if (reading != _lastState) {
    _lastDebounceTime = micros();
  }
  if ( micros() - _lastDebounceTime > _DebounceTimeUS && reading != _state ) {
    _state = reading;
    if (_state == HIGH) {
      _lastState = HIGH;
      return true;
    }
  }
  _lastState = reading;
  return false;
}
int DebouncedPushButton::getPinNumber() {
  return _pin;
}
