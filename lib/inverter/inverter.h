#ifndef INVERTER_H
#define INVERTER_H

#include <PZEM004Tv30.h>
#include <SoftwareSerial.h>

#define PIN_RX 5
#define PIN_TX 6

#define CURRENT_WIND_COUNT 2

class INVERTER
{
private:
    PZEM004Tv30 *pzem;
    float _voltage;
    float _current;
    float _power;
    float _energy;
    float _frequency;
    float _pf;

public:
    INVERTER();
    void init();
    bool read();
    void resetEnergy();
    float voltage();
    float current();
    float power();
    float energy();
    float frequency();
    float pf();
};

#endif