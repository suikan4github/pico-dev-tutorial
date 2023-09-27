// Include RPi Pico SDK
#include "pico/stdlib.h"

// Include private headers.
#include "src/counter.hpp"
#include "src/four2sevendecoder.hpp"

int main() {
  // Use RasPi Pico on-board LED.
  // 1=> Turn on, 0 => Turn pff.
  const uint SEG_e = 11;   // LED pin 1
  const uint SEG_d = 12;   // LED pin 2
  const uint SEG_c = 13;   // LED pin 4
  const uint SEG_dp = 14;  // LED pin 5
  const uint SEG_b = 16;   // LED pin 6
  const uint SEG_a = 17;   // LED pin 7
  const uint SEG_f = 18;   // LED pin 9
  const uint SEG_g = 19;   // LED pin 10

  Counter10 counter;
  Four2SevenDecoder decoder(Four2SevenDecoder::anode,
                            Four2SevenDecoder::positive);

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

  gpio_put(SEG_a, 1);
  gpio_put(SEG_b, 1);
  gpio_put(SEG_c, 1);
  gpio_put(SEG_d, 1);
  gpio_put(SEG_e, 1);
  gpio_put(SEG_f, 1);
  gpio_put(SEG_g, 1);
  gpio_put(SEG_dp, 1);

  while (true) {
    uint32_t value;
    uint32_t segments;
    value = counter.GetValue();

    segments = decoder.decode(value,  // value of 0..9
                              true    // no peiriod
    );

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
