# SmallButton
Button library for arduino with support of almost use cases and optimized memory footprint<br/>
<br/>
Size of SmallButton class - 4 bytes.<br/>
## Features
- Single button press
- Single press and repeat
- Press or release
- Release
- Get current state
- Support invert flag: active button state can be 0 or 1
- Configure pullup resistor
<br/>
Library configuration macro:<br/>
SMALL_BUTTON_FILTER_TIME_MS - filter time for debouncing (default 50ms)<br/>
SMALL_BUTTON_REPEAT_DELAY_MS - delay time before first repeat (default 700ms)<br/>
SMALL_BUTTON_REPEAT_EVERY_MS - time interval between repeat (default 80ms)<br/>
<br/>
To override these settings, add define statement before include library header, for example:

```cpp
#define SMALL_BUTTON_FILTER_TIME_MS 100 // this line must be above include
#include "SmallButton.h"
```

Example of usage:
```cpp
#include <SmallButton.h>

SmallButton button(1); // 1 - pin number

void setup() {
  Serial.begin(115200); // initialize serial to print log
  button.begin(); // initialize button
}

void loop() {
  if(button.get() & SmallButton::PRESS_OR_REPEAT) {
    Serial.println("Button pressed");
  }
}
```
Note: get() method returns bit flags with all events, so DO NOT call it in a way:
```cpp
if((button.get() & SmallButton::PRESS) || (button.get() & SmallButton::REPEAT))
```
because you may skip events. Use masks from SmallButton::EventMask, or store result value in a variable and then deal with it.
