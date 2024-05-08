#include "usbc2.h"

void USBC2::init()
{
    _sw3518s = new SW35xx(_bus);
}

void USBC2::readValues()
{
    _sw3518s->readStatus();
    _voltage = round(_sw3518s->vout_mV / 10.0) / 100.0;
    _current = round(_sw3518s->iout_usba_mA / 10.0) / 100.0;
}