#include "build/test/mocks/mock_HAL_SPI_Received.h"
#include "src/receiving_data_max6675.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










void setUp(void)

{

}



void tearDown(void)

{

}



void test_receiving_data_max6675_if_spi_send_true(void)

{

    uint16_t temp = 0;

    HAL_SPI_Received_CMockExpectAndReturn(21, 

   1

   , 

   1

   );

    do {if ((Max6675_Read_Reg(&temp))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(22)));}} while(0);

}

void test_receiving_data_max6675_if_spi_send_false(void)

{

    uint16_t temp = 0;

    HAL_SPI_Received_CMockExpectAndReturn(27, 

   0

   , 

   0

   );

    do {if (!(Max6675_Read_Reg(&temp))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(28)));}} while(0);

}
