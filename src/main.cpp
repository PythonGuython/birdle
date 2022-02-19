#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <IRremote.hpp>

IRsend **irPins = new IRsend*[5];

// Store words in PROGMEM
const char PROGMEM words[][6] = {"abcde", "ghijk", "mnopq", "rstuv"};


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    // Set irPins to act on pins 1 to 5
    for (int i = 0; i < 5; i++) {
        irPins[i] = new IRsend(i + 1);
    } 
}

void loop() {
  // put your main code here, to run repeatedly:
}