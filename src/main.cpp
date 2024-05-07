#include <Arduino.h>
#include "screen.h"
#include "inverter.h"

SCREEN screen;
INVERTER inverter;

Adafruit_ST7789 *tft;

void setup()
{
  Serial.begin(115200);
  Serial.println("[*] Initializing...");
  screen.init();
  inverter.init();
  Serial.println("[*] Initialized");

  delay(1000);

  tft = screen.getTFT();
  tft->setTextColor(ST77XX_WHITE);
  tft->setTextWrap(true);
  tft->setTextSize(2);
  tft->fillScreen(ST77XX_BLACK);
}

bool prevValidValues = true;

void loop()
{
  bool validValues = inverter.read();
  if (!validValues)
    Serial.println("[!] Error reading inverter values");

  if (validValues != prevValidValues)
  {
    tft->fillScreen(ST77XX_BLACK);
    prevValidValues = validValues;

    if (!validValues)
    {
      tft->setCursor(0, 0);
      tft->setTextColor(ST77XX_WHITE, ST77XX_BLACK);
      tft->print("No inverter values");
    }
  }

  if (validValues)
  {
    screen.showInverterValues(inverter.voltage(), inverter.current(), inverter.power(), inverter.energy(), inverter.frequency(), inverter.pf());
  }

  delay(200);
}