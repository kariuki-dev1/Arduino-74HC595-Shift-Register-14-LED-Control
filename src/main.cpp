#include <Arduino.h>
const int datapin = 2; //DS
const int clkpin = 5; //SHCP
const int latchpin = 4; //STCP

void setup() {
  pinMode(datapin, OUTPUT);
  pinMode(clkpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
}

void loop() {

  digitalWrite(latchpin, LOW);
  shiftOut(datapin,clkpin,MSBFIRST,0b11111111);
  shiftOut(datapin,clkpin,MSBFIRST,0b11111111);
  digitalWrite(latchpin, HIGH);
  delay(1000);

  digitalWrite(latchpin, LOW);
  shiftOut(datapin,clkpin,MSBFIRST,0b00000000);
  shiftOut(datapin,clkpin,MSBFIRST,0b00000000);
  digitalWrite(latchpin, HIGH);
  delay(1000);
}