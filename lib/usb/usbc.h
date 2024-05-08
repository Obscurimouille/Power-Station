#ifndef USBC_H
#define USBC_H

#include "usb.h"
#include <math.h>

class USBC: public USB {
    private:
        SW35xx* _sw3518s;
        h1_SW35xx::SW35xx::fastChargeType_t _fastChargeType;
        uint8_t _pdVersion;

    public:
        USBC(TwoWire &bus = Wire): USB(bus) {}
        void init() override;
        void readValues() override;
        h1_SW35xx::SW35xx::fastChargeType_t getFastChargeType();
        uint8_t getPdVersion();
};
#endif