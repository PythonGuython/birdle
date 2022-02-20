#include <Arduino.h>
#include <MFRC522.h>
#include <SPI.h>
#include <IRremote.hpp>

IRrecv **irPins = new IRrecv*[5];

// Store words in PROGMEM
const char PROGMEM words[][6] = {"abcde", "ghijk", "mnopq", "rstuv"};


void setup() {
    // put your setup code here, to run once:
    pinMode(0, OUTPUT);
    Serial.begin(9600);
    // Set irPins to act on pins 1 to 5
    for (int i = 0; i < 5; i++) {
        irPins[i] = new IRrecv(i + 1);
    } 
}

void loop() {
    // put your main code here, to run repeatedly:
    // Send 255 on all irPins
    for (int i = 0; i < 5; i++) {
        if(irPins[i]->decodeNEC()){
            Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
            irPins[i]->resume();
        }
    }
}