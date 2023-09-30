#include <stdint.h>

class Four2SevenDecoder {
 public:
  enum Common { anode, cathode };
  enum Logic { positive, negative };
  Four2SevenDecoder() = delete;
  Four2SevenDecoder(Common common,  // 7segments LED type
                    Logic logic     // driver logic.
  );

  // output bit7:0 == dp,g,f,...a
  virtual uint32_t decode(uint32_t code, bool period);

 private:
  const Common common_;
  const Logic logic_;
  bool blank_ = false;
  const uint32_t decode_table_[16] = {
      0x3f,  // 0
      0x06,  // 1
      0x5b,  // 2
      0x4f,  // 3
      0x66,  // 4
      0x6d,  // 5
      0x7d,  // 6
      0x07,  // 7
      0x7f,  // 8
      0x6f,  // 9
      0x77,  // a
      0x7c,  // b
      0x39,  // c
      0x5e,  // d
      0x79,  // e
      0x71   // f
  };
};