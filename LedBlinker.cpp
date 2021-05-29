#include <Arduino.h>
#include "LedBlinker.h"

LedBlinker::LedBlinker(int ledPin)
{
  _ledPin = ledPin;
  _ledState = LOW;
  _interval = 1000;
  _previousMillis = 0;

  pinMode(_ledPin, OUTPUT);
}

void LedBlinker::moduleLoop()
{
  unsigned long currentMillis = millis();

  if (currentMillis - _previousMillis >= _interval)
  {
    _previousMillis = currentMillis;
    if (_ledState == LOW)
    {
      _ledState = HIGH;
    }
    else
    {
      _ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(_ledPin, _ledState);
  }
}
