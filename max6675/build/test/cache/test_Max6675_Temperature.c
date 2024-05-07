#include "src/Max6675_Temperature.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










void setUp(void)

{

}



void tearDown(void)

{

}



void test_Max6675_Temperature_received_4_and_return_1(void)

{

    float result = Max6675_Temperature(4);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((1)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((1))), (UNITY_FLOAT)((UNITY_FLOAT)((result))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(20)));

}



void test_Max6675_Temperature_received_cant_be_negative(void)

{

    

   _Bool 

        check = 

                0

                     ;

    float result = Max6675_Temperature(1);

    if (result > 0) {

        check = 

               1

                   ;

    }

    do {if ((check)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(30)));}} while(0);

}

void test_Max6675_Temperature_above_max_temperature(void)

{

    float result = Max6675_Temperature(5000);

    UnityAssertFloatsWithin((UNITY_FLOAT)((UNITY_FLOAT)((-1)) * (UNITY_FLOAT)(0.00001f)), (UNITY_FLOAT)((UNITY_FLOAT)((-1))), (UNITY_FLOAT)((UNITY_FLOAT)((result))), ((

   ((void *)0)

   )), (UNITY_UINT)((UNITY_UINT)(35)));



}
