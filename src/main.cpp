#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  // setting pin 16 as input_pullup pin
  pinMode(16, INPUT_PULLUP);

  // setting the pin 26 as output mode
  pinMode(26, OUTPUT);
}

int dvalue = 0;

void loop()
{
  // put your main code here, to run repeatedly:
  // scanning for any push on the button
  if (!digitalRead(16))
  {
    // writing the status of button on the serial
    Serial.println("Pushed");
    // debounce delay
    delay(150);

    // waiting for the button to be released
    while (!digitalRead(16))
      ;

    // writing the status of button on the serial
    Serial.println("Released");

    // toggling the status of pin 26
    if (dvalue)
    {
      Serial.println("LOW");
      digitalWrite(26, LOW);
    }
    else
    {
      Serial.println("HIGH");
      digitalWrite(26, HIGH);
    }
  }
  dvalue = digitalRead(26);
}