/*
 * DHT11.h
 *
 *  Created on: Jul 9, 2023
 *      Author: brave
 */

//#ifndef INC_DHT11_H_
//#define INC_DHT11_H_
#ifndef __STM32F4xx_HAL_GPIO_H
#define __STM32F4xx_HAL_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

#define DHT11_GPIO_PORT GPIOA
#define DHT11_GPIO_PIN GPIO_PIN_0
void DHT11_ReadData(void);
uint8_t i;
#endif /* INC_DHT11_H_ */
