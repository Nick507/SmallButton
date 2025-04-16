# TinyButton
Button library for arduino with support of almost use cases and optimized memory footprint

Size of TinyButton class - 4 bytes.
Supported use cases:
1) Single button press
2) Single press and repeat
3) Press or release
4) Release
5) Get current state

Invert flag and using of pullup resistor can be configured per button.

Library configuration macro:
TINY_BUTTON_FILTER_TIME_MS - filter time for debouncing (default 50ms)
TINY_BUTTON_REPEAT_DELAY_MS - delay time before first repeat (default 700ms)
TINY_BUTTON_REPEAT_EVERY_MS - time interval between repeat (default 80ms)

To override these settings, add define statement before include library header, for example:

#define TINY_BUTTON_FILTER_TIME_MS 100
#include "TinyButton.h"