#include "write_to_file.h"

bool write_to_file(float temperature) {
    //создаем файл
    const char *filename = "temperature.txt";
    // Дескриптор файла
    int fd;
    // Открытие файла в режиме добавления данных
    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Ошибка при открытии файла");
        return MAX6675_ERROR;
    }
    // Запись данных в файл в реальном времени
    if (write(fd, &temperature, sizeof(float)) == -1) {
        perror("Ошибка при записи данных в файл");
        close(fd);
        return MAX6675_ERROR;
    }
    // Закрытие файла
    close(fd);
    return MAX6675_OK;
}