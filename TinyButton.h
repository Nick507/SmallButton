#pragma once
#include "Arduino.h"

class TinyButton
{
  uint8_t m_pin;
  uint16_t m_lastTime;        // save memory, 16 bit is enough for delays <= 65535ms
  uint8_t m_lastState : 2;    // LOW, HIGH, 2 - not initialized
  bool m_isStateStable : 1;
  bool m_lastStableState : 1;
  bool m_isInverted : 1;
  bool m_isRepeat : 1;

public:

  TinyButton(uint8_t pin,          // pin number
             bool pullup = true,   // false: do not use internall pullup resistor, true: activate internal pullup resistor
             bool inverted = true  // false: high port level equals to pressed button state, true: low port level equals to pressed button state
            );

  enum EventMask
  {
    PRESSED = 0x01,
    PRESS = 0x02,
    REPEAT = 0x04,
    PRESS_OR_REPEAT = 0x06,
    PRESS_OR_RELEASE = 0x0A,
    RELEASE = 0x08
  };

  /*
  Possible mask combinations:
  0000 - not pressed
  0011 - has been pressed
  0001 - is on hold
  0101 - repeat
  1000 - has been released
  */
  
  uint8_t get(void); // reads button state and returns value according to EventMask

  /*
  Examples:
  if(button.get() & TinyButton::PRESS)           ... for single press event
  if(button.get() & TinyButton::PRESS_OR_REPEAT) ... for single press and repeat events
  if(button.get() & TinyButton::PRESSED)         ... to check current state
  */
};

