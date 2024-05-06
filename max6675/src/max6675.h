#ifndef MAX6675_H
#define MAX6675_H

#include <stdbool.h>
#include <stdint.h>

//Псевдонимы
#define MAX6675_OK  1
#define MAX6675_ERROR   0

//Функция возврата значения микросхемы
bool Max6675_Read_Reg(uint16_t *reg);

//Перевод принятых данных в температуру
float Max6675_Temperature(uint16_t reg);

#endif // MAX6675_H
