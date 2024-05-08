#ifndef USBA_H
#define USBA_H

#include "usb.h"
#include <Adafruit_ADS1X15.h>
#include <math.h>

#define ADS_MULTIPLIER 0.1875F
#define VOLTAGE_RES_DIVIDER_COEF 0.25F
#define INA180A2_MULTIPLIER 50.0F
#define CURRENT_SHUNT_RES 0.01F

class USBA: public USB {
    private:
        Adafruit_ADS1115* _adc;
    public:
        USBA(TwoWire &i2c = Wire): USB(i2c) {}
        void init() override;
        void readValues() override;
};
#endif