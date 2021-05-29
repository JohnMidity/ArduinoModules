#ifndef LedBlinker_H
#define LedBlinker_H

#include "module.h"

class LedBlinker : public Module
{
private:
  int _ledPin, _ledState;
  unsigned long _previousMillis;
  long _interval;

public:
  LedBlinker(int ledPin);
  void moduleLoop();
};
#endif
