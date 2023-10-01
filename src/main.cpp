// Include RPi Pico SDK
#include "pico/stdlib.h"

// Include private headers.
#include "counter.hpp"
#include "four2sevendecoder.hpp"

int main() {
  // Use RasPi Pico on-board LED.
  // 1=> Turn on, 0 => Turn pff.
  const uint SEG_e = 16;   // LED pin 1
  const uint SEG_d = 17;   // LED pin 2
  const uint SEG_c = 18;   // LED pin 4
  const uint SEG_dp = 19;  // LED pin 5
  const uint SEG_b = 11;   // LED pin 6
  const uint SEG_a = 12;   // LED pin 7
  const uint SEG_f = 13;   // LED pin 9
  const uint SEG_g = 14;   // LED pin 10

  Counter10 counter;
  Four2SevenDecoder decoder(Four2SevenDecoder::anode,    // 7seg LED type.
                            Four2SevenDecoder::positive  // driver logic
  );

  // Initializing the GPIO pin and set it output.
  gpio_init(SEG_a);
  gpio_init(SEG_b);
  gpio_init(SEG_c);
  gpio_init(SEG_d);
  gpio_init(SEG_e);
  gpio_init(SEG_f);
  gpio_init(SEG_g);
  gpio_init(SEG_dp);

  gpio_set_dir(SEG_a, GPIO_OUT);
  gpio_set_dir(SEG_b, GPIO_OUT);
  gpio_set_dir(SEG_c, GPIO_OUT);
  gpio_set_dir(SEG_d, GPIO_OUT);
  gpio_set_dir(SEG_e, GPIO_OUT);
  gpio_set_dir(SEG_f, GPIO_OUT);
  gpio_set_dir(SEG_g, GPIO_OUT);
  gpio_set_dir(SEG_dp, GPIO_OUT);

  // Initial value of output. The anode common 7segments
  // LED must set output 1 to make it blank.
  gpio_put(SEG_a, 1);
  gpio_put(SEG_b, 1);
  gpio_put(SEG_c, 1);
  gpio_put(SEG_d, 1);
  gpio_put(SEG_e, 1);
  gpio_put(SEG_f, 1);
  gpio_put(SEG_g, 1);
  gpio_put(SEG_dp, 1);

  while (true) {
    // run counter and obtain value.
    uint32_t value = counter.GetValue();

    // decode the obtained value to segment pattern.
    uint32_t segments = decoder.decode(value,  // value of 0..9
                                       true    // no period
    );

    // drive pins.
    gpio_put(SEG_a, (segments >> 0) & 1);
    gpio_put(SEG_b, (segments >> 1) & 1);
    gpio_put(SEG_c, (segments >> 2) & 1);
    gpio_put(SEG_d, (segments >> 3) & 1);
    gpio_put(SEG_e, (segments >> 4) & 1);
    gpio_put(SEG_f, (segments >> 5) & 1);
    gpio_put(SEG_g, (segments >> 6) & 1);
    gpio_put(SEG_dp, (segments >> 7) & 1);

    sleep_ms(500);
  }
}
