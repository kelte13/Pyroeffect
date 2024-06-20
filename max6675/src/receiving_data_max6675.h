#ifndef MAX6675_H
#define MAX6675_H

#include <stdbool.h>
#include <stdint.h>
#include "HAL_SPI_Received.h"

//псевдопсевдонимы (в дальнейшем заменить на HAL_ ...)
#define MAX6675_OK true
#define MAX6675_ERROR false
//Функция возврата значения микросхемы
bool Max6675_Read_Reg(uint16_t *reg, bool answer);


#endif // MAX6675_H
