#include <Arduino.h>

// Motor driver enable pins
#define EN_R_A 12
#define EN_L_A 13
#define EN_R_B 8
#define EN_L_B 9
#define EN_R_C 2
#define EN_L_C 3

// Motor driver PWM pins
#define PWM_R_A 10
#define PWM_L_A 11
#define PWM_R_B 6
#define PWM_L_B 7
#define PWM_R_C 4
#define PWM_L_C 5

// Button input pins
#define RIGHT_bt      19
#define LEFT_bt       18
#define UP_bt         16
#define DOWN_bt       17
#define EM_STP_Base   20
#define EM_STP_Linear 21

// LCD pins
#define LCD_RS  41
#define LCD_RW  43
#define LCD_E   45
#define LCD_D4  47
#define LCD_D5  49
#define LCD_D6  51
#define LCD_D7  53

// Relay pins
#define RELAY_1 23
#define RELAY_2 25
#define RELAY_3 27
#define RELAY_4 29

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(500);
}