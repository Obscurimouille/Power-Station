#include <Arduino.h>
#include "screen.h"
#include "inverter.h"
#include "usba.h"
#include "usbc.h"
#include "usbc2.h"
#include <Wire.h>

#define EN_INVERTER 0

SCREEN screen;
#if EN_INVERTER
INVERTER inverter;
#endif

Adafruit_ST7789 *tft;

USBA usba(Wire);
USBC usbc1(Wire);
USBC2 usbc2(Wire);

/* -------------------------- FUNCTIONS DEFINITION -------------------------- */
void handleInverterValues();
void handleUSBValues();

void setup()
{
  Serial.begin(115200);
  Serial.println("[*] Initializing...");
  Wire.begin(); 
  screen.init();
  #if EN_INVERTER
  inverter.init();
  #endif
  Serial.println("[*] Initialized");

  delay(1000);

  usba.init();
  usbc1.init();
  usbc2.init();

  tft = screen.getTFT();
  tft->setTextColor(ST77XX_WHITE);
  tft->setTextWrap(true);
  tft->setTextSize(2);
  tft->fillScreen(ST77XX_BLACK);
}

void loop()
{
  handleInverterValues();
  handleUSBValues();
  delay(2000);
}

bool prevValidValues = true;
void handleInverterValues()
{
#if EN_INVERTER
  bool validValues = inverter.read();
  if (!validValues)
    Serial.println("[!] Error reading inverter values");

  if (validValues != prevValidValues)
  {
    tft->fillScreen(ST77XX_BLACK);
    prevValidValues = validValues;

    if (!validValues)
    {
      tft->setCursor(0, 2 * 8);
      tft->setTextColor(ST77XX_WHITE, ST77XX_BLACK);
      tft->print("No inverter values");
    }
  }

  if (validValues)
  {
    screen.showInverterValues(inverter.voltage(), inverter.current(), inverter.power(), inverter.energy(), inverter.frequency(), inverter.pf());
  }
#endif
}

void handleUSBValues()
{
  usba.readValues();
  // usbc1.readValues();
  // usbc2.readValues();

  Serial.println("USB-A:");
  Serial.print("Voltage (V): ");
  Serial.println(usba.getVoltage());
  Serial.print("Current (A): ");
  Serial.println(usba.getCurrent());
  Serial.print("Power (W): ");
  Serial.println(usba.getPower());
  
  // Serial.println("USB-C 1:");
  // Serial.print("Voltage (V): ");
  // Serial.println(usbc1.getVoltage());
  // Serial.print("Current (A): ");
  // Serial.println(usbc1.getCurrent());
  // Serial.print("Power (W): ");
  // Serial.println(usbc1.getPower());

  // Serial.println("USB-C 2:");
  // Serial.print("Voltage (V): ");
  // Serial.println(usbc2.getVoltage());
  // Serial.print("Current (A): ");
  // Serial.println(usbc2.getCurrent());
  // Serial.print("Power (W): ");
  // Serial.println(usbc2.getPower());

  Serial.println();
}