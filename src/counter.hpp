#include <stdint.h>

class Counter10 {
 public:
  virtual uint32_t GetValue();

 private:
  uint32_t counter_ = 0;
};
