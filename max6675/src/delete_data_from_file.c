#include "delete_data_from_file.h"

bool delete_data_from_file(void) {
    const char *filename = "C:\\\\Users\\\\DMITRIY\\\\Documents\\\\GitHub\\\\Pyroeffect\\\\max6675\\\\file\\\\temperature.txt";
    if (truncate(filename, 0) == -1) {
        perror("Ошибка при очистке файла");
        return MAX6675_ERROR;
    }
    return MAX6675_OK;
}

