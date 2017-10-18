#include "BME280_I2C.h"

//<---Method Bodies will be filled eventually--->

BME280_I2C::BME280_I2C(PinName sda, scl, int frequency){
    //To be filled.
}

BME280_I2C::void reset(void){
        i2c.start();
        i2c.write(bmeAddr);
        i2c.write(0xB6); 
        i2c.stop();
}