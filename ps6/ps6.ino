#include <LiquidCrystal_I2C.h>

#include "mastermind.h"
#include "lcd_wrapper.h"

void setup() {
  init();
  pinMode(LED_BLUE_1, OUTPUT);
  pinMode(LED_RED_1, OUTPUT);
  pinMode(LED_BLUE_2, OUTPUT);
  pinMode(LED_RED_2, OUTPUT);
  pinMode(LED_BLUE_3, OUTPUT);
  pinMode(LED_RED_3, OUTPUT);
  pinMode(LED_BLUE_4, OUTPUT);
  pinMode(LED_RED_4, OUTPUT);
  pinMode(BTN_1_PIN, INPUT);
  pinMode(BTN_2_PIN, INPUT);
  pinMode(BTN_3_PIN, INPUT);
  pinMode(BTN_4_PIN, INPUT);
  pinMode(BTN_ENTER_PIN, INPUT);
  randomSeed(analogRead(A1));
}

void loop() {
  char* secret=generate_code(false, 4);
  play_game(secret);
  free(secret);
}
