#ifndef DELETE_DATA_FROM_FILE_H
#define DELETE_DATA_FROM_FILE_H

#include <unistd.h>
#include <stdbool.h>

//псевдопсевдонимы (в дальнейшем заменить на HAL_ ...)
#define MAX6675_OK true
#define MAX6675_ERROR false

bool delete_data_from_file(void);

#endif // DELETE_DATA_FROM_FILE_H
