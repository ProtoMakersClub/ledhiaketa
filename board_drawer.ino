void drawBoard() {
  for (size_t i = 0; i < NUM_LEDS; i++) {
    CRGB color = CRGB::Black;
    if(a_score == 0 && b_score == 0) {
      color = CRGB::Green;
    } else if (a_score == b_score && a_score == i) {
      color = CRGB::Blue;
      if (millis() % 500 < 250) {
        color = CRGB::Red;
      }
    } else if (i == a_score) {
      color = CRGB::Red;
    } else if (i == b_score) {
      color = CRGB::Blue;
    }

    leds[i] = color;
  }
  FastLED.show();
}
