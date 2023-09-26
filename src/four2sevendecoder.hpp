#include <stdint.h>

class Four2SevenDecoder {
 public:
  virtual uint32_t decode(uint32_t code, bool period);

 private:
  bool blank_ = false;
  const uint32_t decode_table_[16] = {
      0x3f,  // 0
      0x06,  // 1
      0x5c,  // 2
      0x4f,  // 3
      0x66,  // 4
      0x6d,  // 5
      0x7d,  // 6
      0x07,  // 7
      0x7f,  // 8
      0x5f,  // 9
      0x77,  // a
      0x7c,  // b
      0x79,  // c
      0x3e,  // d
      0x79   // e
  };
};