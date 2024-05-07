#include "inverter.h"

INVERTER::INVERTER() {}

void INVERTER::init()
{
    SoftwareSerial pzemSerial(PIN_RX, PIN_TX);
    pzem = new PZEM004Tv30(pzemSerial);
}

void INVERTER::resetEnergy()
{
    pzem->resetEnergy();
}

bool INVERTER::read()
{
    _voltage = pzem->voltage();
    if (isnan(_voltage))
        return false;
    _current = pzem->current() / CURRENT_WIND_COUNT;
    if (isnan(_current))
        return false;
    _power = pzem->power();
    if (isnan(_power))
        return false;
    _energy = pzem->energy();
    if (isnan(_energy))
        return false;
    _frequency = pzem->frequency();
    if (isnan(_frequency))
        return false;
    _pf = pzem->pf();
    if (isnan(_pf))
        return false;
    return true;
}

float INVERTER::voltage()
{
    return _voltage;
}

float INVERTER::current()
{
    return _current;
}

float INVERTER::power()
{
    return _power;
}

float INVERTER::energy()
{
    return _energy;
}

float INVERTER::frequency()
{
    return _frequency;
}

float INVERTER::pf()
{
    return _pf;
}