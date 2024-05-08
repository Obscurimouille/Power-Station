#ifndef USB_H
#define USB_H

#include <h1_SW35xx.h>
#include <Wire.h>
using namespace h1_SW35xx;

class USB {
    protected:
        TwoWire &_bus;
        float _voltage;
        float _current;
        float _power;

    public:

        /**
         * @brief Construct a new USB object
         * 
         * @param bus The I2C bus to use
         */
        USB(TwoWire &bus = Wire);

        /**
         * @brief Initialize the USB device
         */
        virtual void init();

        /**
         * @brief Read the voltage, current, and power values from the USB device
         */
        virtual void readValues();

        /**
         * @brief Get the output voltage in volts (10mV resolution)
         * @return float The output voltage in volts
         */
        float getVoltage();

        /**
         * @brief Get the output current in amperes (10mA resolution)
         * @return float The output current in amperes
         */
        float getCurrent();

        /**
         * @brief Get the output power in watts
         * @return float The output power in watts
         */
        float getPower();
};
#endif