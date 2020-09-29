#include <Arduino.h>
#include <debounce.h>
#include <IBT2.h>

// Motor driver enable pins
const char EN_F_Pins[3] = {12, 8, 2}; // EN_F_Right EN_F_Left EN_F_Linear
const char EN_B_Pins[3] = {13, 9, 3}; // EN_B_Right EN_B_Left EN_B_Linear

// Motor driver PWM pins
const char PWM_F_Pins[3] = {10, 6, 4}; // PWM_F_Right PWM_F_Left PWM_F_Linear
const char PWM_B_Pins[3] = {11, 7, 5}; // PWM_B_Right PWM_B_Left PWM_B_Linear

IBT2 Drive(EN_F_Pins, EN_B_Pins, PWM_F_Pins, PWM_B_Pins); // initializes IBT object

// Button input pins
#define RIGHT_bt 19
#define LEFT_bt 18
#define UP_bt 16
#define DOWN_bt 17
#define EM_STP_Base 20
#define EM_STP_Linear 21

// button debounce intitalizations
debounce UP_Button(UP_bt);
debounce DOWN_Button(DOWN_bt);
debounce LEFT_Button(LEFT_bt);
debounce RIGHT_Button(RIGHT_bt);

// LCD pins
#define LCD_RS 41
#define LCD_RW 43
#define LCD_E 45
#define LCD_D4 47
#define LCD_D5 49
#define LCD_D6 51
#define LCD_D7 53

// Relay pins
#define RELAY_1 23
#define RELAY_2 25
#define RELAY_3 27
#define RELAY_4 29

// Robot States
enum Robot_States
{
  SIT,
  STAND,
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};
Robot_States Robot_State = STAND; // FSM initialization

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  /*
    need to make inturrupt based logic, robot should stay in the same state 
    until another button is pressed. For now, debounce.h does not work with 
    this code right away. Use digitalRead() instead of debouncing. 
  */
  switch (Robot_State)
  {
  case SIT:
  {
    Drive.Stop_Base();
    break;
  }
  case STAND:
  {
    Serial.println("State: STAND");
    Drive.Stop_Base();
    // need to add cases according to button presses
    // need to add joystick code

    if (UP_Button.debounced())
    {
      Robot_State = FORWARD;
    }
    else if (DOWN_Button.debounced())
    {
      Robot_State = BACKWARD;
    }
    else if (LEFT_Button.debounced())
    {
      Robot_State = LEFT;
    }
    else if (RIGHT_Button.debounced())
    {
      Robot_State = RIGHT;
    }
    break;
  }
  case FORWARD:
  {
    Serial.println("State: FORWARD");
    if (UP_Button.debounced())
    {
      Drive.Move_Forward();
      Robot_State = FORWARD;
    }
    if (!UP_Button.debounced())
      Robot_State = STAND;
    break;
  }
  case BACKWARD:
  {
    Serial.println("State: BACKWARD");
    if (DOWN_Button.debounced())
    {
      Drive.Move_Backward();
      Robot_State = BACKWARD;
    }
    if (!DOWN_Button.debounced())
      Robot_State = STAND;
    break;
  }
  case LEFT:
  {
    Serial.println("State: LEFT");
    if (LEFT_Button.debounced())
    {
      Drive.Move_Left();
      Robot_State = LEFT;
    }
    if (!LEFT_Button.debounced())
      Robot_State = STAND;
    break;
  }
  case RIGHT:
  {
    Serial.println("State: RIGHT");
    if (RIGHT_Button.debounced())
    {
      Drive.Move_Right();
      Robot_State = RIGHT;
    }
    if (!RIGHT_Button.debounced())
      Robot_State = STAND;
    break;
  }
  }
}