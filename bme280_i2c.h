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

//Calibration Registers
//<--Fill in eventually-->




#endif BME280_H