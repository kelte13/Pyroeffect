#include "stm32f7xx_hal.h"
#include "spi.h"
#include "gpio.h"
#include "max6675.h"
#include <stdio.h>

//Функция возврата значения микросхемы
uint8_t max6675ReadReg(uint16_t *reg, uint32_t *errorCode)
{
	//Возвращаемые функции HAL
	HAL_StatusTypeDef hal_answer = HAL_ERROR;

	//Массив для хранения полученных данных
	uint8_t temp[2] = {0};


	//Выбор микросхемы
	MAX6675_CS_SET();

	//Чтение из микросхемы
	hal_answer = HAL_SPI_Receive(MAX6675_SPI, temp, 2, 100);

	//Выбор микросхемы
	MAX6675_CS_RESET();

	if(hal_answer == HAL_OK)
	{
		//Проверка подключения датчика
		if(temp[1] & 0x04) return MAX6675_ERROR;
		uint16_t result = temp[0] | (temp[1] << 8);
		*reg = result >> 3;
		return MAX6675_OK;
	}

	return MAX6675_OK;
}

float max6675Temp(uint16_t reg)
{
	return reg * 0.25;
}

