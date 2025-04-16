#include <TinyButton.h>

TinyButton button(1); // 1 - pin number

void setup() {
    Serial.begin(115200); // initialize serial to print log
    button.begin(); // initialize button
  }

  void loop() {
    if(button.get() & TinyButton::PRESS_OR_REPEAT) Serial.println("Button pressed");
  }