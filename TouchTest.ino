#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define CS_PIN  10
// MOSI=11, MISO=12, SCK=13
#define TIRQ_PIN  7
#define t_CS 4
XPT2046_Touchscreen ts(CS_PIN);

// XPT2046_Touchscreen ts(CS_PIN);  // Param 2 - NULL - No interrupts
//XPT2046_Touchscreen ts(CS_PIN, 255);  // Param 2 - 255 - No interrupts
// XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);  // Param 2 - Touch IRQ Pin - interrupt enabled polling

void setup() {
  Serial.begin(38400);

  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(10,HIGH);
  digitalWrite(4,HIGH);

  ts.begin();
  ts.setRotation(1);
  while (!Serial && (millis() <= 1000));
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    Serial.print("Pressure = ");
    Serial.print(p.z);
    Serial.print(", x = ");
    Serial.print(p.x);
    Serial.print(", y = ");
    Serial.print(p.y);
    delay(30);
    Serial.println();
  }
}

