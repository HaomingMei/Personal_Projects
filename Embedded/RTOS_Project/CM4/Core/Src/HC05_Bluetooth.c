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
int HC05_Process(UART_HandleTypeDef *huart){
	// Local Variable Storing Size

	//* Basic Implementation

		// Insert at Start

		// HERE: Check Buffer if Inserted Propertly


	//* Full Implementation
	// If Not Full

		// if Check Byte Count Enough


		// Insert new data into buffer

		// Else Return 0 (Failed/Full) -> Blink LED?/ Screen Indication

	// Else

		// Pause/Hold...?

	// Return 0 Upon Success




}


