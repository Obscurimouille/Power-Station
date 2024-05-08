#include "usba.h"

void USBA::init() {
    _adc = new Adafruit_ADS1115();
    if (!_adc->begin()) {
        Serial.println("Failed to initialize ADS1115");
    }
}

void USBA::readValues() {
    // Get ADC value from voltage sensor
    int16_t voutVoltage = _adc->readADC_SingleEnded(0);
    // Calculate voltage in mV
    float voltage = ((float)voutVoltage * ADS_MULTIPLIER) / VOLTAGE_RES_DIVIDER_COEF;
    // Calculate voltage in V with 10mV precision
    _voltage = round(voltage / 10.0) / 100.0;

    // Get ADC value from current sensor
    int16_t csVoltage = _adc->readADC_SingleEnded(1);
    // Calculate shunt voltage
    float shuntVoltage = ((float)csVoltage * ADS_MULTIPLIER) / INA180A2_MULTIPLIER;
    // Calculate current in A with 10mA precision
    _current = round(shuntVoltage / CURRENT_SHUNT_RES / 10.0) / 100.0;
}