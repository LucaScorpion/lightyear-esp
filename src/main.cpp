#include <Arduino.h>
#include "../lib/lightyear/LightYear.h"

LightYear *lightYear;

void setup() {
    lightYear = new LightYear();
    FastLED.setBrightness(255);
}

void loop() {
    lightYear->setPixel(0, CRGB::Red);
    lightYear->show();
    delay(500);
    lightYear->setPixel(0, CRGB::Green);
    lightYear->show();
    delay(500);
    lightYear->setPixel(0, CRGB::Blue);
    lightYear->show();
    delay(500);
    lightYear->setPixel(0, CRGB::Black);
    lightYear->show();
    delay(500);
    lightYear->setPixel(0, CRGB::White);
    lightYear->show();
    delay(500);
}
