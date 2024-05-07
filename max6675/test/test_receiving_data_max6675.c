#ifdef TEST

#include "unity.h"
#include "stdbool.h"

#include "receiving_data_max6675.h"
#include "mock_HAL_SPI_Received.h"


void setUp(void)
{
}

void tearDown(void)
{
}

void test_receiving_data_max6675_if_spi_send_true(void)
{
    uint16_t temp = 0;
    HAL_SPI_Received_ExpectAndReturn(true, true);
    TEST_ASSERT_TRUE(Max6675_Read_Reg(&temp));
}
void test_receiving_data_max6675_if_spi_send_false(void)
{
    uint16_t temp = 0;
    HAL_SPI_Received_ExpectAndReturn(false, false);

    TEST_ASSERT_FALSE(Max6675_Read_Reg(&temp));
}

#endif // TEST
