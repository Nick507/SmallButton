#pragma once
#include "Arduino.h"

#ifndef SMALL_BUTTON_REPEAT_EVERY_MS
#define SMALL_BUTTON_REPEAT_EVERY_MS 80
#endif

#ifndef SMALL_BUTTON_REPEAT_DELAY_MS
#define SMALL_BUTTON_REPEAT_DELAY_MS 700
#endif

#ifndef SMALL_BUTTON_FILTER_TIME_MS
#define SMALL_BUTTON_FILTER_TIME_MS 50
#endif

class SmallButton
{
  uint8_t m_pin;
  uint16_t m_lastTime;        // save memory, 16 bit is enough for delays <= 65535ms
  uint8_t m_lastState : 2;    // LOW, HIGH, 2 - not initialized
  bool m_isStateStable : 1;
  bool m_lastStableState : 1;
  bool m_isInverted : 1;
  bool m_isRepeat : 1;
  bool m_pullup : 1;

public:

  SmallButton(uint8_t pin,          // pin number
             bool pullup = true,   // false: do not use internall pullup resistor, true: activate internal pullup resistor
             bool inverted = true  // false: high port level equals to pressed button state, true: low port level equals to pressed button state
            );

  void begin();

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
  if(button.get() & SmallButton::PRESS)           ... for single press event
  if(button.get() & SmallButton::PRESS_OR_REPEAT) ... for single press and repeat events
  if(button.get() & SmallButton::PRESSED)         ... to check current state
  */
};

