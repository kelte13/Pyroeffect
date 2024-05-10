#include <stdio.h>
#include "Max6675_Temperature.h"
#include "receiving_data_max6675.h"
#include "write_to_file.h"

int main()
{
    uint16_t reg = 0;
    float temperature = 0;
    for (size_t i = 0; i < 10; ++i) {
        bool answer = Max6675_Read_Reg(&reg, true);
        if (answer == MAX6675_OK) {
            //получение данных о температуре
            temperature = Max6675_Temperature(reg);
            write_to_file( temperature);
        }
        printf("temp = %f\n\r", temperature);
    }
    return 0;
}
//дополнить код, чтобы данные заносились в файл