//
//  M5Stack series
//  LoRa Sample
//
//  MaiaR create
//
//  Applicable model
//  * M5Stack StickC Plus       with LoRa HAT/LoRa UNIT
//  * M5Stack StickC            with LoRa HAT/LoRa UNIT
//  * M5Stack ATOM S3/S3 Lite   with LoRa KIT/LoRa UNIT
//  * M5Stack ATOM Matrix/Lite  with LoRa KIT/LoRa UNIT
//  * M5Stack BASIC             with LoRa MODULE/LoRa UNIT
//


#ifdef ARDUINO_M5Stick_C_PLUS
#include <M5StickCPlus.h>
#define Btn BtnA
#elif defined ARDUINO_M5Stick_C
#include <M5StickC.h>
#define Btn BtnA
#elif defined ARDUINO_M5Stack_ATOMS3
#include <M5AtomS3.h>
#elif defined ARDUINO_M5Stack_ATOM
#include <M5Atom.h>
#elif defined ARDUINO_M5Stack_Core_ESP32
#include <M5Stack.h>
#define Btn BtnA
#endif

#include "LoRa.h"

void setup() {
  M5.begin();
  LoRaInit();
}

void loop() {
  M5.update();
  if (M5.Btn.wasPressed()) {
    LoRaCommand("Button ON");
    delay(2000);
  }
}
