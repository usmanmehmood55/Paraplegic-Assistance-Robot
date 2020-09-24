#include <Arduino.h>
#include <debounce.h>

// Motor driver enable pins
#define EN_F_Right 12
#define EN_B_Right 13
#define EN_F_Left 8
#define EN_B_Left 9
#define EN_F_Linear 2
#define EN_B_Linear 3

// Motor driver PWM pins
#define PWM_F_Right 10
#define PWM_B_Right 11
#define PWM_F_Left 6
#define PWM_B_Left 7
#define PWM_F_Linear 4
#define PWM_B_Linear 5

// Button input pins
#define RIGHT_bt 19
#define LEFT_bt 18
#define UP_bt 16
#define DOWN_bt 17
#define EM_STP_Base 20
#define EM_STP_Linear 21

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

void Move_Up(); void Move_Down(); void Move_Left(); void Move_Right(); 

void setup()
{
  pinMode(RIGHT_bt, INPUT_PULLUP);
  pinMode(LEFT_bt, INPUT_PULLUP);
  pinMode(UP_bt, INPUT_PULLUP);
  pinMode(DOWN_bt, INPUT_PULLUP);
  pinMode(EM_STP_Base, INPUT_PULLUP);
  pinMode(EM_STP_Linear, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(UP_bt), Move_Up, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DOWN_bt), Move_Down, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LEFT_bt), Move_Left, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RIGHT_bt), Move_Right, CHANGE);

  Serial.begin(9600);
}

void loop()
{
  delay(500);
}

void Move_Up()
{
  while (digitalRead(UP_bt) == HIGH)
  {
    digitalWrite(EN_F_Right, HIGH);
    digitalWrite(EN_F_Left, HIGH);
    analogWrite(PWM_F_Right, 150);
    analogWrite(PWM_F_Left, 150);
  }
}

void Move_Down()
{
  while (digitalRead(DOWN_bt) == HIGH)
  {
    digitalWrite(EN_B_Right, HIGH);
    digitalWrite(EN_B_Left, HIGH);
    analogWrite(PWM_B_Right, 150);
    analogWrite(PWM_B_Left, 150);
  }
}

void Move_Left()
{
  while (digitalRead(UP_bt) == HIGH)
  {
    digitalWrite(EN_F_Right, HIGH);
    digitalWrite(EN_B_Left, HIGH);
    analogWrite(PWM_F_Right, 150);
    analogWrite(PWM_B_Left, 150);
  }
}

void Move_Right()
{
  while (digitalRead(UP_bt) == HIGH)
  {
    digitalWrite(EN_B_Right, HIGH);
    digitalWrite(EN_F_Left, HIGH);
    analogWrite(PWM_B_Right, 150);
    analogWrite(PWM_F_Left, 150);
  }
}