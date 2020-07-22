#include <Arduino.h>

// selection the led pin
#define LED_PIN 26

// selecting the pushbutton pin
int button = 16;

void setup()
{
  // starting the serial communication
  Serial.begin(115200);

  // setting pin 16 as input_pullup pin
  pinMode(button, INPUT_PULLUP);

  // setting the pin ledSelect as output mode
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // scanning for any push on the button
  if (!digitalRead(button))
  {
    // debouncing delay
    delay(160);

    // wait until the button is released
    while (!digitalRead(button))
      ;

    // writing the toggled pin state
    digitalWrite(LED_PIN, digitalRead(LED_PIN) ? LOW : HIGH);
  }
}