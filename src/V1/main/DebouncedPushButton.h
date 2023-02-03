#ifndef DebouncedPushButton_h
#define DebouncedPushButton_h
#include "Arduino.h"

class DebouncedPushButton{
  public:
    DebouncedPushButton(int pin,unsigned long DebounceTimeUS,bool pullup);
    bool debouncedRead(void);
    int getPinNumber(void);
  private:
    bool _pullup;
    int _pin;
    int _state;
    int _lastState;
    unsigned long _lastDebounceTime;
    unsigned long _DebounceTimeUS;    
};
#endif
