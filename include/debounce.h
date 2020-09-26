/*
  Dobounce.h - Library for debouncing a button.
  Created by Usman Mehmood, September 24th, 2020.
*/

#ifndef debounce_h
#define debounce_h
#include "Arduino.h"

class debounce
{
public:
    debounce(char buttonPin, unsigned long debounceDelay);
    bool debounceButton();

private:
    char _buttonPin;
    bool _buttonState;
    bool _lastButtonState;
    unsigned long _debounceDelay;
    unsigned long _lastDebounceTime;
};

debounce::debounce(char buttonPin, unsigned long debounceDelay)
{
    _buttonPin = buttonPin;
    _debounceDelay = debounceDelay;
    pinMode(_buttonPin, INPUT);
    _lastButtonState = LOW;
}

bool debounce::debounceButton()
{
    if (digitalRead(_buttonPin))
    {
        while (digitalRead(_buttonPin));
        return true;
    }
    else
    {
        return false;
    }
}

#endif