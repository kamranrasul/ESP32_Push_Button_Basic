#include <Arduino.h>

// selecting led pin
#define LED_PIN 26
// selecting BTN_PIN pin 
#define BTN1_PIN 16
#define BTN2_PIN 17

void setup()
{
  // starting the serial communication
  Serial.begin(115200);

  // setting pin 16 as input_pullup pin
  pinMode(BTN1_PIN, INPUT_PULLUP);
  pinMode(BTN2_PIN, INPUT_PULLUP);

  // setting the pin ledSelect as output mode
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // scanning for any push on the BTN_PIN
  if (!digitalRead(BTN1_PIN) || !digitalRead(BTN2_PIN))
  {
    // debouncing delay
    delay(160);

    // wait until the BTN_PIN is released
    while (!digitalRead(BTN1_PIN) || !digitalRead(BTN2_PIN))
      ;

    // writing the toggled pin state
    digitalWrite(LED_PIN, digitalRead(LED_PIN) ? LOW : HIGH);
  }
}