#ifndef MAX6675_H
#define MAX6675_H

#include <stdbool.h>
#include <stdint.h>

//Псевдонимы
#define MAX6675_OK  true
#define MAX6675_ERROR   false

//Функция возврата значения микросхемы
bool Max6675_Read_Reg(uint16_t *reg);


#endif // MAX6675_H
