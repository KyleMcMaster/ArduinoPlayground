/*

temperature_display.ino By Kyle McMaster

Displays temperature in C or F on LCD Display, 

Based on source found here:
https://docs.arduino.cc/learn/electronics/lcd-displays#serial-to-display-example
https://docs.arduino.cc/tutorials/iot-bundle/plant-communicator|

Layout: 
https://docs.arduino.cc/tutorials/giga-r1-wifi/cheat-sheet

Wiring:
https://docs.arduino.cc/static/7d7b6e99f40c7e55f2e9c6175c6db5b5/260cd/LCD_Base_bb_Fritz.png
https://docs.arduino.cc/static/e6ac5822aa2a0815f64551beb65139e4/b0681/light__temperature_sensor_rp2040_bfbwQp7XjU.png
https://www.youtube.com/watch?v=wEbGhYjn4QI

*/
#include <LiquidCrystal.h>

const int tempPin = A1;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  int temperature = get_temperature();
  lcd.print("Temperature: " + String(temperature));
  delay(2000);
}

float get_temperature() {
  int reading = analogRead(tempPin);
  float voltage = reading * 3.3;
  voltage /= 1024.0;

  /* temperature in Celsius */
  float temperatureC = (voltage - 0.5) * 100; /*converting from 10 mv per degree wit 500 mV offset */
  /* Convert to Fahrenheit */
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  return temperatureF;
}
