#ifdef TEST

#include "unity.h"
#include <stdint.h>
#include <stdbool.h>

#include "Max6675_Temperature.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Max6675_Temperature_received_4_and_return_1(void)
{
    float result = Max6675_Temperature(4);
    TEST_ASSERT_EQUAL_FLOAT(1, result);
}

void test_Max6675_Temperature_received_cant_be_negative(void)
{
    bool check = false;
    float result = Max6675_Temperature(1);
    if (result > 0) {
        check = true;
    }
    TEST_ASSERT_TRUE(check);
}
void test_Max6675_Temperature_above_max_temperature(void)
{
    float result = Max6675_Temperature(5000);
    TEST_ASSERT_EQUAL_FLOAT(-1, result);

}



#endif // TEST
