#include "usbc.h"

void USBC::init()
{
    _sw3518s = new SW35xx(_bus);
    _sw3518s->setMaxCurrent5A();
}

void USBC::readValues()
{
    _sw3518s->readStatus();
    _voltage = round(_sw3518s->vout_mV / 10.0) / 100.0;
    _current = round(_sw3518s->iout_usbc_mA / 10.0) / 100.0;
    _fastChargeType = _sw3518s->fastChargeType;
    _pdVersion = _sw3518s->PDVersion;
}

h1_SW35xx::SW35xx::fastChargeType_t USBC::getFastChargeType()
{
    return _fastChargeType;
}

uint8_t USBC::getPdVersion()
{
    return _pdVersion;
}