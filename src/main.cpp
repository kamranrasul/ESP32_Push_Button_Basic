#include <Arduino.h>

int pinStatus = HIGH;
int pinSelect = 16;
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
    delay(150);
    while (!digitalRead(pinSelect));

    // toggling the status of pin ledSelect
    pinStatus = digitalRead(ledSelect) ? LOW : HIGH;
    digitalWrite(ledSelect, pinStatus);
  }
}