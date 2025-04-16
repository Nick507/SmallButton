# SmallButton
Button library for arduino with support of almost use cases and optimized memory footprint<br/>
<br/>
Size of TinyButton class - 4 bytes.<br/>
Supported use cases:<br/>
1) Single button press
2) Single press and repeat
3) Press or release
4) Release
5) Get current state
<br/>
Invert flag and using of pullup resistor can be configured per button.<br/>
Do not need to call initialization in setup().<br/>
<br/>
Library configuration macro:<br/>
TINY_BUTTON_FILTER_TIME_MS - filter time for debouncing (default 50ms)<br/>
TINY_BUTTON_REPEAT_DELAY_MS - delay time before first repeat (default 700ms)<br/>
TINY_BUTTON_REPEAT_EVERY_MS - time interval between repeat (default 80ms)<br/>
<br/>
To override these settings, add define statement before include library header, for example:<br/>
<br/>
#define TINY_BUTTON_FILTER_TIME_MS 100<br/>
#include "SmallButton.h"<br/>