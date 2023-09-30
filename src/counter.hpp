#include <stdint.h>

// Count from 0 to 9 and then, 0.
class Counter10 {
 public:
  virtual uint32_t GetValue();

 private:
  uint32_t counter_ = 0;
};
