#include <driver.h>


driverA_t driverA_ctor(void *ll, driverA_ll_read_fptr r, driverA_ll_write_fptr w)
{
    driverA_t this = {
        .peripheral = ll,
        .read = r,
        .write = w
    };
    return this;
}

uint8_t driverA_xfer(void *this, uint8_t d)
{
    driverA_t *driver = (driverA_t *)this;
    driver->write(d);
    return driver->read();
}