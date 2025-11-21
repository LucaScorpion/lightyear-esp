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

void LightYear::setPixel(CRGB color) {
    this->leds1[0] = color;
    this->show();
}

void LightYear::setDisplay(uint32_t* colors) {
    int offset = 0;
    for (uint8_t i = 0; i < NUM_LEDS_1 / 2; i++) {
        this->leds1[i] = colors[i + offset];
    }
    offset += NUM_LEDS_1 / 2;
    for (uint8_t i = NUM_LEDS_1 - 1; i >= NUM_LEDS_1 / 2; i--) {
        this->leds1[i] = colors[i + offset];
    }
    offset += NUM_LEDS_1 / 2;
    for (uint8_t i = 0; i < NUM_LEDS_2 / 2; i++) {
        this->leds2[i] = colors[i + offset];
    }
    offset += NUM_LEDS_2 / 2;
    for (uint8_t i = NUM_LEDS_2 - 1; i >= NUM_LEDS_2 / 2; i--) {
        this->leds2[i] = colors[i + offset];
    }
    offset += NUM_LEDS_2 / 2;
    for (uint8_t i = 0; i < NUM_LEDS_3 / 2; i++) {
        this->leds3[i] = colors[i + offset];
    }
    offset += NUM_LEDS_3 / 2;
    for (uint8_t i = NUM_LEDS_3 - 1; i >= NUM_LEDS_3 / 2; i--) {
        this->leds3[i] = colors[i + offset];
    }
    offset += NUM_LEDS_3 / 2;
    for (uint8_t i = 0; i < NUM_LEDS_4; i++) {
        this->leds4[i] = colors[i + offset];
    }
}
