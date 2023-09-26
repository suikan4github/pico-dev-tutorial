#include "counter.hpp"

uint32_t Counter10 ::GetValue() {
  counter_++;

  // wrap arround to keep value in 0..9;
  if (counter_ >= 10) counter_ = 0;

  return counter_;
}
