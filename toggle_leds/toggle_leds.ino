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
/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
*/

// int brightness = 0;  // how bright the LED is
// int fadeAmount = 5;  // how many points to fade the LED by
// int targetLed = green; // Start with Green
// bool hasBeenZero = false;
// bool hasBeenLit = false;

// constants won't change. Used here to set a PWM pin number:
const int buttonPin = 2;
const int red = 9;
const int green = 10;
const int blue = 11;
const long interval = 1000;  // interval at which to blink (milliseconds)

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated
int redState = LOW;  // ledState used to set the LED
int greenState = HIGH;
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  pinMode(buttonPin, INPUT);
  // set the digital pin as output:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (redState == LOW) {
      redState = HIGH;
      greenState = LOW;
    } else {
      redState = LOW;
      greenState = HIGH;
    }

    buttonState = digitalRead(buttonPin);

    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
      // turn LED on:
      digitalWrite(blue, HIGH);
    } else {
      // turn LED off:
      digitalWrite(blue, LOW);
    }

    // set the LED with the ledState of the variable:
    digitalWrite(red, redState);
    digitalWrite(green, greenState);
  }
}

// the setup routine runs once when you press reset:
// void setup() {
//   // declare pin 9 to be an output:
//   pinMode(red, OUTPUT);
//   pinMode(green, OUTPUT);
// }

// // the loop routine runs over and over again forever:
// void loop() {
//   // set the brightness of target Pin:
//   analogWrite(targetLed, brightness);

//   // change the brightness for next time through the loop:
//   brightness = brightness + fadeAmount;

//   // reverse the direction of the fading at the ends of the fade:
//   if (brightness <= 0 || brightness >= 255) {
//     fadeAmount = -fadeAmount;
//   }

//   hasBeenZero = (brightness <= 0);
//   hasBeenLit = (brightness >= 255);

//   // wait for 30 milliseconds to see the dimming effect
//   delay(30);
//   if (hasBeenZero && hasBeenLit)
//   {
//     targetLed = (targetLed == green) ? red : green;
//     hasBeenZero = false;
//     hasBeenLit = false;
//     brightness = 0;
//     delay = delay-1;
//   }
// }
