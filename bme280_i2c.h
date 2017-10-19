#ifndef BME280_I2C_H
#define BME280_I2C_H

#include "mbed.h"

//<-----------------Register Definitions, all are 8-bit----------------->

//Data Registers, 3 Bytes for Press/Temp, 2 Bytes for Humidity.
#define BME280_PRESSURE_MSB        0xF7
#define BME280_PRESSURE_LSB        0xF8
#define BME280_PRESSURE_XLSB       0xF9 // Only bits 7-4 used, 3-0 are 0.
#define BME280_TEMP_MSB            0xFA
#define BME280_TEMP_LSB            0xFB
#define BME280_TEMP_XLSB           0xFC // Only bits 7-4 used, 3-0 are 0.
#define BME280_HUMIDITY_MSB        0xFD
#define BME280_HUMIDITY_LSB        0xFE

//Config Registers
#define BME280_CTRL_HUM         0xF2
#define BME280_STATUS           0xF3
#define BME280_CTRL_MEAS        0xF4
#define BME280_CONFIG           0xF5

//ID and Resest registers
#define BME_280_RESET           0xE0 // Write-Only
#define BME_280_ID              0xD0 // Read-Only

//Temperature Calibration Registers, dig_T1-3.
#define BME_280_CALIB00         0x88 // 0x88 & 0x89 expect an unsigned short.
#define BME_280_CALIB02         0x8A // 0x8A - 0x8D expect a signed short.

//Pressure Calibration Registers, dig_P1-9.
#define BME_280_CALIB06         0x8E // 0x8E & 0x8F -> unsigned short
#define BME_280_CALIB08         0x90 // 0x90 - 0x9F -> signed short

//Humidity Calibration Registers, dig_H1-H6
#define BME_280_CALIB25         0xA1 // 0xA1 -> unsigned char
#define BME_280_CALIB26         0xE1 // 0xE1 & 0xE2 - > signed short
#define BME_280_CALIB28         0xE3 // 0xE3 -> unsigned char
#define BME_280_CALIB29         0xE4 // 0xE4 - 0xE6 -> signed short
#define BME_280_CALIB32         0xE7 // 0xE7 - > signed char



class BME280_I2C {
    public:
    
    /**
    * Makes a BME280_I2C object with specified pins and frequency.
    * @param sda The SDA pin on the mbed.
    * @param scl The SCL pin on the mbed.
    * @param frequency The frequency to use for the i2c communication.
    */
    BME280_I2C(PinName sda, scl, int frequency);
        
    /**
    * Resets the sensor using the complete power-on-reset procedure.
    * More information on page 26 of the datasheet.
    */
    void reset(void);
    
    private:
    
    I2C i2c; //Used to communicate with the sensor using i2c.
    const char bmeAddr; //Address assigned to the sensor.
    
}


#endif BME280_H