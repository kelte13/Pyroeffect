#ifndef INC_MAX6675_H_
#define INC_MAX6675_H_

//Интерфейс
#define MAX6675_SPI	&hspi1

//Макросы для управления CS
#define MAX6675_CS_SET()	(HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET))
#define MAX6675_CS_RESET()	(HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET))

//Псевдонимы
#define MAX6675_OK	1
#define MAX6675_ERROR	0

//Функция значения микросхемы
uint8_t max6675ReadReg(uint16_t *reg, uint32_t *errorCode);

//Перевод принятых данных в температуру
float max6675Temp(uint16_t reg);

#endif /* INC_MAX6675_H_ */
