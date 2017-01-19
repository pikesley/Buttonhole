// Low power NeoPixel goggles example.  Makes a nice blinky display
// with just a few LEDs on at any time.

#include <FastLED.h>

#define RING_LEDS 12
#define RING_PIN 7

int red[]     = {255,   0,   0};
int orange[]  = {255, 127,   0};
int yellow[]  = {255, 255,   0};
int green[]   = {  0, 255,   0};
int cyan[]    = {  0, 255, 255};
int blue[]    = {  0,   0, 255};
int magenta[] = {255,   0, 255};

CRGB ring[RING_LEDS];

int speed() {
  return 25;
  //return random(500);
}

int interval() {
  return 0;
  //return random(500);
}

void wipe(int colour[]) {
  for (int i = 0; i < RING_LEDS; i++) {
    ring[i].r = colour[0];
    ring[i].g = colour[1];
    ring[i].b = colour[2];
    FastLED.show();
    delay(speed());
  }
}

void setup() {
  FastLED.addLeds<NEOPIXEL, RING_PIN>(ring, RING_LEDS);
  FastLED.setCorrection(0x0f0f0f);
  randomSeed(analogRead(0));
}

void loop() {
  wipe(red);
  delay(interval());
  wipe(orange);
  delay(interval());
  wipe(yellow);
  delay(interval());
  wipe(green);
  delay(interval());
  wipe(cyan);
  delay(interval());
  wipe(blue);
  delay(interval());
  wipe(magenta);
  delay(interval());
}
