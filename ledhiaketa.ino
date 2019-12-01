#define NEOPIXEL_DATA_PIN 5
#define NUM_LEDS 53

#include <FastLED.h>
CRGB leds[NUM_LEDS];

const int a_btn = 6;
const int b_btn = 7;

unsigned int a_score = 0;
unsigned int b_score = 0;
unsigned int a_clicks = 0;
unsigned int b_clicks = 0;

unsigned long t = 0;

unsigned int gHue = 0;
int mode = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, NEOPIXEL_DATA_PIN>(leds, NUM_LEDS);
  startCountdown();
  countSetup();
}


unsigned long last_evt_t = 0;
void loop() {
  // put your main code here, to run repeatedly:
  /*if (millis() - t >= 100) {
    t = millis();
    Serial.print(a_score);
    Serial.print("\t");
    Serial.println(b_score);
  }*/

  unsigned long t = millis();


  if (mode == 0) {
    EVERY_N_MILLISECONDS( 1 ) {
      gHue++;  // slowly cycle the "base color" through the rainbow
    }
    fill_rainbow( leds, NUM_LEDS, gHue, 7);
    FastLED.show();

    if (!digitalRead(a_btn) || !digitalRead(b_btn)) {
      mode = 3;
      startCountdown();
      last_evt_t = t;
      a_clicks = 0;
      b_clicks = 0;
    }
  }

  // Playing
  if (mode == 1) {
    countScore();
    drawBoard();

    if (a_score >= NUM_LEDS) {
      mode = 2;
      startWinnerAnimation(1);
      last_evt_t = t;
    }
    if (b_score >= NUM_LEDS) {
      mode = 2;
      startWinnerAnimation(2);
      last_evt_t = t;

    }
  }

  //
  if (mode == 2) {
    drawWinnerAnimation();
    if (t - last_evt_t >= 5000) {
      mode = 0;
      last_evt_t = t;
    }
  }

  //Countdown
  if (mode == 3) {
    if (drawCountdown()) {
      mode = 1;
      last_evt_t = t;
    }
  }


}
