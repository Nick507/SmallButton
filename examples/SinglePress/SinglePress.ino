#include <SmallButton.h>

SmallButton button(1); // 1 - pin number

void setup() {
    Serial.begin(115200); // initialize serial to print log
    button.begin(); // initialize button
  }

  void loop() {
    if(button.get() & SmallButton::PRESS) Serial.println("Button pressed");
  }