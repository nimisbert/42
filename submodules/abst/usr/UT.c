#include <stdio.h>

#include <driver.h>
#include <library.h>
#include <peripheral.h>

void main(void)
{
// Testing peripheralA :
    peripheralA_t peripheralA = peripheralA_ctor();
    printf("%s : %s \r\n", "peripheralA_read test", peripheralA.read()==0xFF? "PASS":"FAIL");
    peripheralA.write(0xAA);
    printf("%s : %s \r\n", "peripheralA_write test", peripheralA.read()!=0xFF? "PASS":"FAIL");

// Testing driverA :
    driverA_t driverA = driverA_ctor(&peripheralA, peripheralA_read_8bit, peripheralA_write_8bit);
    printf("%s : %s \r\n", "driverA_xfer test", driverA_xfer(&driverA, 0xBB)==0xBB? "PASS":"FAIL");

// Testing libraryA :   
    libA_t libA = libA_ctor(&driverA, driverA_xfer);
    printf("%s : %s \r\n", "libA_add test", libA_add(&libA, 0xBB)==0xBB+1? "PASS":"FAIL");
    printf("%s : %s \r\n", "libA_sub test", libA_sub(&libA, 0xBB)==0xBB-1? "PASS":"FAIL");
    
}