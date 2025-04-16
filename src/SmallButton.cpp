#include "SmallButton.h"

SmallButton::SmallButton(uint8_t pin, bool pullup, bool inverted) :
  m_pin(pin),
  m_isInverted(inverted),
  m_pullup(pullup)
{
  // to avoid separate call in setup()
  // but some platforms (ESP32) still requires to call begin in setup(): https://github.com/mathertel/OneButton/issues/129
  begin(); 
}

void SmallButton::begin()
{
  pinMode(m_pin, m_pullup ? INPUT_PULLUP : INPUT);
  m_lastState = 2; // not initialized
  m_lastStableState = false;
}

uint8_t SmallButton::get()
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
    if(currentTime < (uint16_t)(m_lastTime + SMALL_BUTTON_FILTER_TIME_MS)) return m_lastStableState;
    m_isStateStable = true;
  }

  if(m_lastStableState == currentState)
  {
    if(!currentState || (currentTime < (uint16_t)(m_lastTime + (m_isRepeat ? SMALL_BUTTON_REPEAT_EVERY_MS : SMALL_BUTTON_REPEAT_DELAY_MS)))) return m_lastStableState;
    m_isRepeat = true;
    m_lastTime = currentTime;
    return (REPEAT | PRESSED);
  }

  m_lastTime = currentTime;
  m_lastStableState = currentState;
  return currentState ? (PRESS | PRESSED) : RELEASE;
}

