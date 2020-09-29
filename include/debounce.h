/*
  Dobounce.h - Library for debouncing a button.
  Created by Usman Mehmood, September 24th, 2020.
*/

#ifndef debounce_h
#define debounce_h
#include "Arduino.h"

// Object for a button
class debounce
{
public:
    debounce(char buttonPin);           // constructor
    bool debounced();                   // debounce function

private:
    char _buttonPin;                    // pin number of button
    bool _buttonState;                  // state of button, HIGH/LOW
};

debounce::debounce(char buttonPin)
{
    _buttonPin = buttonPin;             // sets pin number
    pinMode(_buttonPin, INPUT);         // declares button pin as input
}

bool debounce::debounced()
{
    // currently just returning digitalRead
    // need to fix debouncing
    return digitalRead(_buttonPin);

    if (digitalRead(_buttonPin))        // if button is pressed
    {
        while (digitalRead(_buttonPin)) // keeps running till the button is released
        {
            _buttonState = HIGH;           
        };                              // stops after the button is released
    }
    else                                // if button is not pressed, returns LOW
    {
        _buttonState = LOW;
    }
    return _buttonState;
}

#endif