#include "screen.h"

SCREEN::SCREEN() {
    tft = new Adafruit_ST7789(PIN_CS, PIN_DC, PIN_RESET);
}

void SCREEN::init() {
    tft->init(WIDTH, HEIGHT, SPI_MODE0);
    tft->invertDisplay(false);
    tft->setRotation(ROTATION);
    tft->fillScreen(ST77XX_BLACK);

    tft->setCursor(0, 0);
    tft->setTextColor(ST77XX_WHITE);
    tft->setTextWrap(true);
    tft->setTextSize(2);
    tft->print("Initialized!");
}