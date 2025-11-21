#include "LightYear.h"
#include <FastLED.h>

LightYear::LightYear() {
    FastLED.addLeds<LED_TYPE, LEDS_GPIO_1, COLOR_ORDER>(leds1, NUM_LEDS_1);
    FastLED.addLeds<LED_TYPE, LEDS_GPIO_2, COLOR_ORDER>(leds2, NUM_LEDS_2);
    FastLED.addLeds<LED_TYPE, LEDS_GPIO_3, COLOR_ORDER>(leds3, NUM_LEDS_3);
    FastLED.addLeds<LED_TYPE, LEDS_GPIO_4, COLOR_ORDER>(leds4, NUM_LEDS_4);
}

void LightYear::show() {
    FastLED.show();
}

void LightYear::setPixel(uint8_t index, CRGB color) {
    this->leds1[index] = color;
}
