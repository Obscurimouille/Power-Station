#include "usb.h"

USB::USB(TwoWire &bus) : _bus(bus)
{
    _voltage = 0;
    _current = 0;
}

void USB::init()
{
}

void USB::readValues()
{
    // Read the voltage and current values
}

float USB::getVoltage()
{
    return _voltage;
}

float USB::getCurrent()
{
    return _current;
}

float USB::getPower()
{
    return _voltage * _current;
}