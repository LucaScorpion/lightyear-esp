#include <Arduino.h>
#include <FastLED.h>

#define LED_TYPE WS2815
#define COLOR_ORDER GRB

#define NUM_LEDS 10
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<LED_TYPE, 2>(leds, NUM_LEDS);
}

void loop() {
    leds[0] = CRGB::Red; FastLED.show();
    delay(500);
    leds[0] = CRGB::Blue; FastLED.show();
    delay(500);
}
