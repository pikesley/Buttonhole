// Low power NeoPixel goggles example.  Makes a nice blinky display
// with just a few LEDs on at any time.

#include <Adafruit_NeoPixel.h>

#define PIN 7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(21, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(10); // 1/3 brightness
  for(int j = 0; j < 19; j++) pixels.setPixelColor(j, 0);
  pixels.show();
  delay(100);
}

void loop() {
  pixels.setPixelColor(0, 0, 255, 0);
  pixels.setPixelColor(1, 255, 0, 0);
  pixels.setPixelColor(2, 0, 0, 255);
  pixels.setPixelColor(4, 0, 255, 0);
  pixels.setPixelColor(5, 255, 0, 0);
  pixels.setPixelColor(6, 0, 0, 255);
  pixels.setPixelColor(8, 0, 255, 0);

  for (int i = 9; i < 21; i++) {
    pixels.setPixelColor(i, 255, 0, 0);
  }

  pixels.show();
}
