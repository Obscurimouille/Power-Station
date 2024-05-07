#ifndef SCREEN_H
#define SCREEN_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

#define PIN_CS 10
#define PIN_DC 9
#define PIN_RESET 8

#define WIDTH 240
#define HEIGHT 320
#define ROTATION 1

class SCREEN {
    private:
        Adafruit_ST7789 *tft;
    public:
        SCREEN();
        void init();
};
#endif