#include "TinyButton.h"

#define TINY_BUTTON_REPEAT_EVERY_MS 80
#define TINY_BUTTON_REPEAT_DELAY_MS 700
#define TINY_BUTTON_FILTER_TIME_MS 50

TinyButton::TinyButton(uint8_t pin, bool pullup, bool inverted)
{
  m_pin = pin;
  pinMode(pin, pullup ? INPUT_PULLUP : INPUT);
  m_lastState = 2; // not initialized
  m_isInverted = inverted;
  m_lastStableState = false;
}

uint8_t TinyButton::get()
{
  uint8_t currentState = digitalRead(m_pin) ^ m_isInverted;
  uint16_t currentTime = millis();

  if(currentState != m_lastState)
  {
    m_lastState = currentState;
    m_isStateStable = false;
    m_isRepeat = false;
    m_lastTime = currentTime;
    return m_lastStableState;
  }

  if(!m_isStateStable)
  {
    if(currentTime < m_lastTime + TINY_BUTTON_FILTER_TIME_MS) return m_lastStableState;
    m_isStateStable = true;
  }

  if(m_lastStableState == currentState)
  {
    if(!currentState || (currentTime < m_lastTime + (m_isRepeat ? TINY_BUTTON_REPEAT_EVERY_MS : TINY_BUTTON_REPEAT_DELAY_MS))) return m_lastStableState;
    m_isRepeat = true;
    m_lastTime = currentTime;
    return (REPEAT | PRESSED);
  }

  m_lastTime = currentTime;
  m_lastStableState = currentState;
  return currentState ? (PRESS | PRESSED) : RELEASE;
}

