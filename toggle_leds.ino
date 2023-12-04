/*
  Toggle Leds With Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fade
*/

int green = 9;
int red = 10;        // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by
int targetLed = green; // Start with Green
bool hasBeenZero = false;
bool hasBeenLit = false;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(targetLed, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  if (brightness <= 0)
  {
    hasBeenZero = true;
  }

  if (brightness >= 255)
  {
    hasBeenLit = true;
  }

  // wait for 30 milliseconds to see the dimming effect
  delay(15);
  if (hasBeenZero && hasBeenLit)
  {
    targetLed = (targetLed == green) ? red : green;
    hasBeenZero = false;
    hasBeenLit = false;
  }
}
