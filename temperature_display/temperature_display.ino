/*

temperature_display.ino By Kyle McMaster

Displays temperature in C or F on LCD Display, 

Based on source found here:
https://docs.arduino.cc/learn/electronics/lcd-displays#serial-to-display-example
https://docs.arduino.cc/tutorials/iot-bundle/plant-communicator

Wiring:
https://docs.arduino.cc/static/7d7b6e99f40c7e55f2e9c6175c6db5b5/260cd/LCD_Base_bb_Fritz.png
https://docs.arduino.cc/static/e6ac5822aa2a0815f64551beb65139e4/b0681/light__temperature_sensor_rp2040_bfbwQp7XjU.png

*/
const int tempPin = A1;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  /* Initialize serial and wait for port to open: */
  Serial.begin(9600);
  /* This delay gives the chance to wait for a Serial Monitor without blocking if none is found */
  delay(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temperature = get_temperature(); /* assign temperature variable to temperature in Celsius */
  Serial.print("temperature ");
  Serial.println(temperature);
  // clear the screen
  lcd.clear();
  // read all the available characters
  while (Serial.available() > 0) {
    // display each character to the LCD
    lcd.write(Serial.read());
  }
  delay(2000);
}

float get_temperature() {

  return 76; // hardcoded until breaboard arrives
  // int reading = analogRead(tempPin);
  // float voltage = reading * 3.3;
  // voltage /= 1024.0;

  // /* temperature in Celsius */
  // float temperatureC = (voltage - 0.5) * 100; /*converting from 10 mv per degree wit 500 mV offset */
  // /* Convert to Fahrenheit */
  // float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  //return temperatureF;
}