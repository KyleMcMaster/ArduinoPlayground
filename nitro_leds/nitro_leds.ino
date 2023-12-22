/*
nitro_leds.ino
By Kyle McMaster
Using the Arduino Uno R4 Wifi to write "Nitro" to the LED Matrix.

Based on this tutorial here: https://docs.arduino.cc/tutorials/uno-r4-wifi/led-matrix
*/

// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const uint32_t frames[][4] = {
  {
    0xffffffff,
    0xffffffff,
    0xffffffff,
    66
  },
  {
    0x7fffffff,
    0xffffffff,
    0xfffff7ff,
    66
  },
  {
    0x3fe7ffff,
    0xffffffff,
    0xff7ff3fe,
    66
  },
  {
    0x1fc3fe7f,
    0xfffffff7,
    0xff3fe1fc,
    66
  },
  {
    0xf81fc3f,
    0xe7ff7ff3,
    0xfe1fc0f8,
    66
  },
  {
    0x500f81f,
    0xc3fe3fe1,
    0xfc0f8070,
    66
  },
  {
    0x500f,
    0x81fc1fc0,
    0xf8070020,
    66
  },
  {
    0x5,
    0xf80f80,
    0x70020000,
    66
  },
  {
    0x5,
    0xa80880,
    0x50020000,
    600
  },
  {
    0xd812,
    0x41040880,
    0x50020000,
    200
  },
  {
    0x5,
    0xa80880,
    0x50020000,
    0xFFFFFFFF
  }
};

void setup() {
  Serial.begin(115200);
  matrix.begin();

  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  // add some static text
  // will only show "UNO" (not enough space on the display)
  const char text[] = "UNO r4";
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText();
  matrix.endDraw();

  delay(1000);
}

void loop() {
  // Make it scroll!
  matrix.beginDraw();

  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);

  // add the text
  const char text[] = "   Hello Arduino!   ";
  matrix.textFont(Font_5x7);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.loadSequence(frames);
  matrix.play(true);
  delay(3000);
  matrix.endDraw();
}