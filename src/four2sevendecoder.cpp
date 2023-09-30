#include "four2sevendecoder.hpp"

Four2SevenDecoder::Four2SevenDecoder(Common common, Logic logic)
    : common_(common),  // Initialize class variable.
      logic_(logic)     // Initialize class variable.
{}

uint32_t Four2SevenDecoder::decode(uint32_t code, bool period) {
  uint32_t segments = 0;
  // Set segment pattern if the code is in 0..15.
  // Make segument blank if else.
  if (code < 16) segments = decode_table_[code];

  // Set USB ( period pattern )
  if (period) segments |= 0x80;

  // For anode common display, logic should be netative.
  if (common_ == anode) segments = ~segments;

  // In the case of the negative logic LED driver circuit.
  if (logic_ == negative) segments = ~segments;

  return segments;
}
