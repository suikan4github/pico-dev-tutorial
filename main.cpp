// Include RPi Pico SDK
#include "pico/stdlib.h"

int main() {
  // Use RasPi Pico on-board LED.
  // 1=> Turn on, 0 => Turn pff.
  const uint LED_PIN = PICO_DEFAULT_LED_PIN;

  // Initializing the GPIO pin and set it output.
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  while (true) {
    // Turn LED on
    gpio_put(LED_PIN, 1);
    sleep_ms(500);
    // Turn LED off
    gpio_put(LED_PIN, 0);
    sleep_ms(500);
  }
}
