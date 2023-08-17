#include "DHT11.h"
// function to read data from DHT11
void DHT11_ReadData(void)
{
    uint8_t i;

    // send start signal
    HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_GPIO_PIN, GPIO_PIN_RESET);
    HAL_Delay(20);
    HAL_GPIO_WritePin(DHT11_GPIO_PORT, DHT11_GPIO_PIN, GPIO_PIN_SET);

    // wait for response
    HAL_Delay(40);

    // initialize data array
    memset(data, 0, sizeof(data));

    // read 40 bits of data
    for(i=0; i<40; i++)
    {
        // wait for low pulse
        while(!HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_GPIO_PIN));

        // wait for high pulse
        uint32_t t = 0;
        while(HAL_GPIO_ReadPin(DHT11_GPIO_PORT, DHT11_GPIO_PIN))
        {
            t++;
            HAL_Delay(1);
        }

        // store bit value in data array
        if(t > 30)
            data[i/8] |= (1 << (7 - (i % 8)));
    }

    // verify checksum
    if(data[4] == (data[0] + data[1] + data[2] + data[3]))
    {
        // convert temperature and humidity values
        uint8_t hum = data[0];
        uint8_t temp = data[2];

        // do something with temperature and humidity values
        // ...
    }
}
