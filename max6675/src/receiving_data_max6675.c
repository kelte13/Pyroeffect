#include "receiving_data_max6675.h"
bool Max6675_Read_Reg(uint16_t *reg, bool answer) {
    //массив для временного хранения данных
    uint8_t temp[2] = {127, 248};
    //нужно перевести чипcелект на 0, затем считать 2 байти данных, затем перевести чипселект на 1
    //получаем ответ от функции
     //= true;
    bool hal_answer = HAL_SPI_Received(answer);
    if (hal_answer == 1) {
        //проверка работается ли модуль
        if (temp[1] & 0x04) {
            return MAX6675_ERROR;
        }
        //преобразование полученных данных
        *reg = (uint16_t) (temp[1] >> 3);
        *reg |= (uint16_t) (temp[0] << 5);
        return MAX6675_OK;
    } else
    {
        return MAX6675_ERROR;
    }

}