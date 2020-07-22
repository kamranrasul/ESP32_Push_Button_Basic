#include <Arduino.h>

// selecting led pin
#define LED_PIN 26
// selecting BTN_PIN pin 
#define BTN_PIN 16

void setup()
{
  // starting the serial communication
  Serial.begin(115200);

  // setting pin 16 as input_pullup pin
  pinMode(BTN_PIN, INPUT_PULLUP);

  // setting the pin ledSelect as output mode
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // scanning for any push on the BTN_PIN
  if (!digitalRead(BTN_PIN))
  {
    // debouncing delay
    delay(160);

    // wait until the BTN_PIN is released
    while (!digitalRead(BTN_PIN))
      ;

    // writing the toggled pin state
    digitalWrite(LED_PIN, digitalRead(LED_PIN) ? LOW : HIGH);
  }
}