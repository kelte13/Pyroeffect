#ifndef WRITE_TO_FILE_H
#define WRITE_TO_FILE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

//псевдопсевдонимы (в дальнейшем заменить на HAL_ ...)
#define MAX6675_OK true
#define MAX6675_ERROR false

//функция записи в файл
bool write_to_file(float temperature);


#endif // WRITE_TO_FILE_H
