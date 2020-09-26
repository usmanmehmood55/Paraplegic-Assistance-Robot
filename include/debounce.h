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
    debounce(char buttonPin);
    bool debounced();

private:
    char _buttonPin;
    bool _buttonState;
};

debounce::debounce(char buttonPin)
{
    _buttonPin = buttonPin;
    pinMode(_buttonPin, INPUT);
}

bool debounce::debounced()
{
    if (digitalRead(_buttonPin))
    {
        while (digitalRead(_buttonPin))
        {
            _buttonState = HIGH;
        };
    }
    else
    {
        _buttonState = LOW;
    }
    return _buttonState;
}

#endif