#include <Arduino.h>
#include <WiFi.h>
#include "../lib/lightyear/LightYear.h"

#define WIFI_SSID "infi guests"
#define WIFI_PASS "sp@ceinv@der"

LightYear *lightYear;

void setup() {
    lightYear = new LightYear();

    WiFi.begin(WIFI_SSID, WIFI_PASS);
    CRGB statusColor = CRGB::Red;
    while (WiFi.status() != WL_CONNECTED) {
        statusColor = statusColor == CRGB::Red ? CRGB::Blue : CRGB::Red;
        lightYear->setPixel(0, statusColor);
        lightYear->show();
        delay(500);
    }

    // Connected
    lightYear->setPixel(0, CRGB::Green);
    lightYear->show();
    delay(1000);
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
    lightYear->setPixel(0, CRGB::White);
    lightYear->show();
    delay(500);
}
