// Low power NeoPixel goggles example.  Makes a nice blinky display
// with just a few LEDs on at any time.

#include <FastLED.h>

#define RING_LEDS 12
#define RING_PIN 9

int red[]        = {255,   0,   0};
int orange[]     = {255, 127,   0};
int yellow[]     = {255, 255,   0};
int green[]      = {  0, 255,   0};
int deep_green[] = {  0,  31, 0};
int cyan[]       = {  0, 255, 255};
int blue[]       = {  0,   0, 255};
int magenta[]    = {255,   0, 255};
int purple[]     = {63,   0, 255};

uint8_t offset = 0;
uint8_t counter = 0;

CRGB ring[RING_LEDS];

int speed() {
  return 50;
  //return random(500);
}

int interval() {
  return 2000;
  //return random(500);
}

void flower(int first[], int second[]) {
  for (int i = 0; i < RING_LEDS; i++) {
    ring[i].r = 0;
    ring[i].g = 0;
    ring[i].b = 0;
    delay(speed());
    FastLED.show();
  }

  for (int i = 0; i < RING_LEDS; i++) {
    if(i % counter == 0) {
      ring[i].r = second[0];
      ring[i].g = second[1];
      ring[i].b = second[2];
    } else {
      ring[i].r = first[0];
      ring[i].g = first[1];
      ring[i].b = first[2];
    }

    delay(speed());
    FastLED.show();
  }
  counter = (counter + 1) % RING_LEDS;
}

void wipe(int colour[]) {
  for (int i = 0; i < RING_LEDS - 1; i++) {
    ring[offset % RING_LEDS].r = colour[0];
    ring[offset % RING_LEDS].g = colour[1];
    ring[offset % RING_LEDS].b = colour[2];

    FastLED.show();
    offset = (offset + 1) % RING_LEDS;
    delay(speed());
  }
}

void setup() {
  FastLED.addLeds<NEOPIXEL, RING_PIN>(ring, RING_LEDS);
  FastLED.setCorrection(0x0f0f0f);
  randomSeed(analogRead(0));
}

void loop() {
/*  wipe(red);
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
  delay(interval());*/

  flower(purple, deep_green);
  delay(interval());
  flower(yellow, deep_green);
  delay(interval());
  flower(orange, deep_green);
  delay(interval());
  flower(red, deep_green);
  delay(interval());
}
