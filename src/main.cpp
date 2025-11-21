#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "../lib/lightyear/LightYear.h"

#define WIFI_SSID "infi guests"
#define WIFI_PASS "sp@ceinv@der"

LightYear *lightYear;

uint32_t colors[NUM_LEDS_TOTAL];

void setup() {
    lightYear = new LightYear();

    // Connect to WiFi.
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    CRGB statusColor = CRGB::Red;
    while (WiFi.status() != WL_CONNECTED) {
        statusColor = statusColor == CRGB::Red ? CRGB::Blue : CRGB::Red;
        lightYear->setPixel(statusColor);
        delay(500);
    }

    // Connected.
    lightYear->setPixel(CRGB::Green);
    delay(1000);
}

bool updateDisplay() {
    HTTPClient http;
    http.begin("https://lightyear.tocabi.software/boards/1");

    String response = "";
    const int code = http.GET();
    if (code == HTTP_CODE_OK) {
        WiFiClient *stream = http.getStreamPtr();

        // Parse all bytes.
        uint8_t buffer[4];
        for (int i = 0; i < NUM_LEDS_TOTAL; i++) {
            const int readBytes = stream->readBytes(buffer, 4);
            if (readBytes == 4) {
                // R, G, B
                colors[i] = (buffer[0] << 16) | (buffer[1] << 8) | buffer[2];
            } else {
                // Default to black.
                colors[i] = 0;
            }
        }
    }

    http.end();
    return code == HTTP_CODE_OK;
}

void loop() {
    if (updateDisplay()) {
        lightYear->setDisplay(colors);
        lightYear->show();
    } else {
        lightYear->setPixel(CRGB::Red);
    }
    delay(1000);
}
