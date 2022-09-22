#include <peripheral.h>

static Register_t REG = {
    .REG0 = 0xFF,
    .REG1 = 0xFF,
    .REG2 = 0xFF
};

peripheralA_t peripheralA_ctor(void)
{
// Register configuration
    REG.REG0 = 0xAB;
    REG.REG1 = 0xCD;
// Structure handling peripheral
    peripheralA_t this = {
        .write = peripheralA_write_8bit,
        .read  = peripheralA_read_8bit
    };
    return this;
}

uint8_t peripheralA_read_8bit(void)
{
    return REG.REG2;
}

void peripheralA_write_8bit(uint8_t d)
{
    REG.REG2 = d;
}