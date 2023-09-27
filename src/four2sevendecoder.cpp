#include "four2sevendecoder.hpp"

uint32_t Four2SevenDecoder ::decode(uint32_t code, bool period) {
  uint32_t segments = 0;
  // Set segment pattern if the code is in 0..15.
  // Make segument blank if else.
  if (code < 16) segments = decode_table_[code];

  // Set USB ( period pattern )
  if (period) segments |= 0x80;
}
