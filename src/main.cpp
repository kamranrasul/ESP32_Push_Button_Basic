#include <Arduino.h>

// storing the pin status
int pinStatus = HIGH;

// selecting the pushbutton pin
int pinSelect = 16;

// selection the led pin
int ledSelect = 26;

void setup()
{
  // starting the serial communication
  Serial.begin(115200);

  // setting pin 16 as input_pullup pin
  pinMode(pinSelect, INPUT_PULLUP);

  // setting the pin ledSelect as output mode
  pinMode(ledSelect, OUTPUT);
}

void loop()
{
  // scanning for any push on the button
  if (!digitalRead(pinSelect))
  {
    // debouncing delay
    delay(160);

    // wait until the button is released
    while (!digitalRead(pinSelect))
      ;

    // writing the toggled pin state
    digitalWrite(ledSelect, digitalRead(ledSelect) ? LOW : HIGH);
  }
}