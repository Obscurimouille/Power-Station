#include "screen.h"

SCREEN::SCREEN() {
    _tft = new Adafruit_ST7789(PIN_CS, PIN_DC, PIN_RESET);
}

void SCREEN::init() {
    _tft->init(WIDTH, HEIGHT, SPI_MODE0);
    _tft->invertDisplay(false);
    _tft->setRotation(ROTATION);
    _tft->fillScreen(ST77XX_BLACK);

    _tft->setCursor(0, 0);
    _tft->setTextColor(ST77XX_WHITE);
    _tft->setTextWrap(true);
    _tft->setTextSize(2);
    _tft->print("Initialized!");
}

void SCREEN::clear() {
    _tft->fillScreen(ST77XX_BLACK);
}

Adafruit_ST7789* SCREEN::getTFT() {
    return _tft;
}

void SCREEN::showInverterValues(float voltage, float current, float power, float energy, float frequency, float pf) {
    _tft->setCursor(0, 16);
    _tft->setTextColor(ST77XX_WHITE, ST77XX_BLACK);
    _tft->print("Voltage:      ");
    _tft->print(voltage);
    _tft->println("V");
    _tft->print("Current:      ");
    _tft->print(current);
    _tft->println("A");
    _tft->print("Power:        ");
    _tft->print(power);
    _tft->println("W");
    _tft->print("Energy:       ");
    _tft->print(energy, 3);
    _tft->println("kWh");
    _tft->print("Frequency:    ");
    _tft->print(frequency, 1);
    _tft->println("Hz");
    _tft->print("PF:           ");
    _tft->println(pf);
}