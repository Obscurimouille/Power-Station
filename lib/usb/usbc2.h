#ifndef USBC2_H
#define USBC2_H

#include "usb.h"
#include <math.h>

class USBC2: public USB {
    private:
        SW35xx* _sw3518s;

    public:
        USBC2(TwoWire &bus = Wire): USB(bus) {}
        void init() override;
        void readValues() override;
};
#endif