/*
 * HC05_Bluetooth.c
 *
 *  Created on: Jul 7, 2025
 *      Author: haoming
 */


#include "HC05_Bluetooth.h"
#include "stm32h7xx_hal.h"


// This function will be Called when RX Reception Finishes (Interrupt Happens)
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart == &huart8){
		HC05_Process(&huart);
	}
}

