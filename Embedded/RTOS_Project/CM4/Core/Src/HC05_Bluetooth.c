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

#define BUFFERSIZE 128 // Average Sentence Length is 15-20 words. ~5 letter per word * 20 * 0.5 byte per character = 50 bytes
// factor of 2 is easy for bitwise maniupulation
// Declare Ring Buffer Struct Here
typedef struct{
	uint8_t data[BUFFERSIZE];
	uint8_t head;
	uint8_t tail;
} RingBuffer; // Default head = tail = 0, buffer is empty
// Head increments upon insertion and tail increases when bytes are read


// Init Ring Buffer Function: upon HC05_Init
void Ring_Buffer_Init(RingBuffer *Bufer){
	// Bluetooth Initialization

	Buffer->head = 0;
	Buffer->tail = 0;

}

// CheckEmpty Function

// CheckFull Function

// Insert Function

// Read Function (Removes)

// CheckByteCount

// CheckEmptyCount

// Reset Buffer Function




