#include <stdio.h>
#include "Max6675_Temperature.h"
#include "receiving_data_max6675.h"

int main()
{
    uint16_t reg = 0;
    float temperature = 0;
    bool answer = Max6675_Read_Reg(&reg);
    if (answer == MAX6675_OK) {
        temperature = Max6675_Temperature(reg);
    }
    printf("%f", temperature);
    return 0;
}
