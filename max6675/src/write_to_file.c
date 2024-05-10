#include "write_to_file.h"

bool write_to_file(float temperature) {
    const char *filename = "C:\\\\Users\\\\DMITRIY\\\\Documents\\\\GitHub\\\\Pyroeffect\\\\max6675\\\\file\\\\temperature.txt";
    FILE *file = fopen(filename, "a"); // Открыть файл для добавления данных
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return MAX6675_ERROR;
    }
    fprintf(file, "%f\n", temperature); // Записать температуру в файл
    fclose(file); // Закрыть файл
    return MAX6675_OK;
}