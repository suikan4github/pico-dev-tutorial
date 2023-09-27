#include "four2sevendecoder.hpp"

Four2SevenDecoder::Four2SevenDecoder(Common common, Logic logic)
    : common_(common), logic_(logic) {}

uint32_t Four2SevenDecoder::decode(uint32_t code, bool period) {
  uint32_t segments = 0;
  // Set segment pattern if the code is in 0..15.
  // Make segument blank if else.
  if (code < 16) segments = decode_table_[code];

  // Set USB ( period pattern )
  if (period) segments |= 0x80;

  if (common_ == anode) segments = ~segments;

  if (logic_ == negative) segments = ~segments;

  return segments;
}
