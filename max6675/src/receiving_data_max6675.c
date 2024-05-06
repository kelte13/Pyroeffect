#include "receiving_data_max6675.h"
bool Max6675_Read_Reg(uint16_t *reg) {
    //массив для временного хранения данных
    uint8_t temp[2] = {127, 248};
    //нужно перевести чипсет на 0, затем считать 2 байти данных, затем перевести чипселект на 1
    //получаем ответ от функции
    bool hal_answer = HAL_SPI_Received(true);
    if (hal_answer == 1) {
        //проверка работается ли модуль
        if (temp[1] & 0x04) {
            return MAX6675_ERROR;
        }
        //преобразование полученных данных
        *reg = (uint16_t) (temp[1] >> 3);
        *reg |= (uint16_t) (temp[0] << 5);
        return MAX6675_OK;
    }
    return MAX6675_ERROR;
}