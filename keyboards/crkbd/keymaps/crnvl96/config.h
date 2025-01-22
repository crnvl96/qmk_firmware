#pragma once

#define MASTER_LEFT

// defines what is a tap and what is a hold
#undef TAPPING_TERM
#define TAPPING_TERM 160

#define TAPPING_TERM_PER_KEY

// combos must be pressed under this time interval
#define COMBO_TERM 30

// disables hold auto-repeat.
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 0

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64
