#include <Arduino.h>
#include <IRremote.hpp>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(1, 6, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(9600);
    pixels.begin();
}

void loop() {
    
    while(true) {
        // Blink pin 3 (D3)
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(3, LOW);
        delay(500);
    }

    int pulse = pulseIn(A1, HIGH);
    Serial.println(pulse);

    // All non zero values are half brightness
    if (pulse < 900) {
        // Set LED to OFF
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    } else if (pulse < 1800) {
        // Set LED to Yellow
        pixels.setPixelColor(0, pixels.Color(128, 128, 0));
    } else if (pulse < 2700) {
        // Set LED to Green
        pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    } else if (pulse < 3600) {
        // Set LED to Red
        pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    } else if (pulse < 4500) {
        // Set LED to White
        pixels.setPixelColor(0, pixels.Color(86, 86, 86));
    }
}