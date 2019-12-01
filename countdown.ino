CRGB color;
unsigned long t0 = 0;
int subMode = 0;

void startCountdown() {
  t0 = millis();
  color =  CRGB::White;
  subMode = 0;
}

float brightness = 0;
bool drawCountdown() {
  t = millis() - t0;
  if (t > 1000 && subMode == 0) {
    brightness = 1;
    subMode = 1;
    tone(9, 800, 200);
  }

  if (t > 2000 && subMode == 1) {
    brightness = 1;
    subMode = 2;
    tone(9, 800, 200);

  }

  if (t > 3000 && subMode == 2) {
    brightness = 1;
    subMode = 3;
    tone(9, 800, 200);

  }

  if (t > 4000 && subMode == 3) {
    color = CRGB::Green;
    brightness = 1;
    subMode = 4;
    tone(9, 1000, 1000);
  }

  if (subMode < 4) {
    brightness = max(brightness - 0.01, 0);
  }

  fill_solid(leds, NUM_LEDS, color);
  nscale8_video(leds, NUM_LEDS,  brightness * 255);
  FastLED.show();

  return t > 5000;


}
