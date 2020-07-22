#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(16, INPUT_PULLUP);
}

int dvalue = 0;

void loop()
{
  // put your main code here, to run repeatedly:
  if (!digitalRead(16))
  {
    Serial.println("Pushed");
    delay(150);

    while (!digitalRead(16));
    Serial.println("Released");

    pinMode(26, OUTPUT);
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