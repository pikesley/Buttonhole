// Low power NeoPixel goggles example.  Makes a nice blinky display
// with just a few LEDs on at any time.

#include <FastLED.h>
#include <Buttonhole.h>

#define RING_LEDS 12
#define RING_PIN 7
#define SPEED 25

int red[]     = {255,   0,   0};
int orange[]  = {255, 127,   0};
int yellow[]  = {255, 255,   0};
int green[]   = {  0, 255,   0};
int cyan[]    = {  0, 255, 255};
int blue[]    = {  0,   0, 255};
int magenta[] = {255,   0, 255};

uint8_t offset = 0;

CRGB ring[RING_LEDS];
Buttonhole bh();

void wipe(int colour[]) {
  for (int i = 0; i < RING_LEDS - 1; i++) {
    ring[offset % RING_LEDS].r = colour[0];
    ring[offset % RING_LEDS].g = colour[1];
    ring[offset % RING_LEDS].b = colour[2];

    FastLED.show();
    offset = (offset + 1) % RING_LEDS;
    delay(SPEED);
  }
}

void setup() {
  FastLED.addLeds<NEOPIXEL, RING_PIN>(ring, RING_LEDS);
  FastLED.setCorrection(0x0f0f0f);
  randomSeed(analogRead(0));
}

void loop() {
  wipe(red);
  wipe(orange);
  wipe(yellow);
  wipe(green);
  wipe(cyan);
  wipe(blue);
  wipe(magenta);
}
