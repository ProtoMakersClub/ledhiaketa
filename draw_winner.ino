unsigned long t1 = 0;
int animation_winner = 1;

void startWinnerAnimation(int winner) {
  t1 = millis();
  animation_winner = winner;
}

#define animation_speed 30
void drawWinnerAnimation() {
  unsigned long t = millis() - t1;
  int num_on_leds = min(t / animation_speed, NUM_LEDS);
  for (size_t i = 0; i < NUM_LEDS; i++) {
    CRGB color = CRGB::Black;
    if(NUM_LEDS - num_on_leds <= i) {
      color = animation_winner == 1 ? CRGB::Red : CRGB::Blue;
    }
    leds[i] = color;
  }
  FastLED.show();
}
