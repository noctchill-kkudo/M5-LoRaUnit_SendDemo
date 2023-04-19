#include <Arduino.h>
#include <M5StickCPlus.h>
#include "LoRa.h"

void setup() {
  Serial.begin(115200);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  M5.begin();

  M5.Lcd.setRotation(3);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.setTextColor(WHITE,NAVY);
  M5.Lcd.print(" LoRa Module Client ");
  if (LoRaInit() < 0) Serial.print("LoRa Error");
}

void loop() {
  M5.update();
  if(M5.BtnA.wasPressed()){
    Serial.println("Pressed A button.");
    M5.Lcd.setTextSize(4);
    M5.Lcd.setCursor(15, 50);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.print("SEND!");
    LoRaCommand("Hello");
    digitalWrite(10, LOW);
  }
  if(M5.BtnA.wasReleased()){
    M5.Lcd.fillRect(15, 50, 110, 30, BLACK);
    digitalWrite(10, HIGH);
  }

  if(M5.BtnB.wasPressed()){
    Serial.println("Pressed A button.");
    M5.Lcd.setTextSize(4);
    M5.Lcd.setCursor(15, 50);
    M5.Lcd.setTextColor(CYAN);
    M5.Lcd.print("SEND!");
    LoRaCommand("World");
    digitalWrite(10, LOW);
  }
  if(M5.BtnB.wasReleased()){
    M5.Lcd.fillRect(15, 50, 110, 30, BLACK);
    digitalWrite(10, HIGH);
  }
}