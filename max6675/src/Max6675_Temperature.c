#include "Max6675_Temperature.h"
float Max6675_Temperature(uint16_t reg) {
    float coefficient = 0.25;
    float result = reg * coefficient;
    if ((result) >= 0 && (result) <= 1024) {
        return (reg * 0.25);
    }
    return -1;
}


