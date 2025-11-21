#ifndef LIGHTYEAR_H
#define LIGHTYEAR_H

#include <FastLED.h>

#define LED_TYPE WS2815
#define COLOR_ORDER RGB

#define LEDS_GPIO_1 1
#define LEDS_GPIO_2 2
#define LEDS_GPIO_3 4
#define LEDS_GPIO_4 16

#define NUM_LEDS_1 104
#define NUM_LEDS_2 104
#define NUM_LEDS_3 104
#define NUM_LEDS_4 52

class LightYear {
    CRGB leds1[NUM_LEDS_1];
    CRGB leds2[NUM_LEDS_2];
    CRGB leds3[NUM_LEDS_3];
    CRGB leds4[NUM_LEDS_4];

public:
    LightYear();
    void show();
    void setPixel(uint8_t index, CRGB color);
};

#endif //LIGHTYEAR_H
