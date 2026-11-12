/**
 * @file main.c
 */

#include <inttypes.h>

#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#include "BTN.h"
#include "LED.h"

#define SLEEP_MS 200

const char *status = NULL;
  bool button_pressed;

int main(void) {
  if (0 > BTN_init()) {
    return 0;
  }
  if (0 > LED_init()) {
    return 0;
  }



  while (1) {
    button_pressed = BTN_is_pressed(BTN1);

    if (button_pressed) {
      status = "Button pressed";
      printk("Status: %s\n", status);
    }

    LED_toggle(1);
    k_msleep(SLEEP_MS);
  }
  return 0;
}
