/*
 * HC05_Bluetooth.c
 *
 *  Created on: Jul 7, 2025
 *      Author: haoming
 */


#include "HC05_Bluetooth.h"
#include "stm32h7xx_hal.h"

#define BUFFER_EMPTY 0
#define BUFFER_NOT_EMPTY 1


// This function will be Called when RX Reception Finishes (Interrupt Happens)
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart == &huart8){
		HC05_Process(huart);
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

	return 0; // Placeholder


}

#define BUFFERSIZE 128 // Average Sentence Length is 15-20 words. ~5 letter per word * 20 * 0.5 byte per character = 50 bytes
// factor of 2 is easy for bitwise maniupulation
// Declare Ring Buffer Struct Here
typedef struct{
	char data[BUFFERSIZE];
	uint64_t head; // Points to buffer index, Increments when inserting
	uint64_t tail; // Points to buffer index, Increments when a byte is read
} RingBuffer; // Default head = tail = 0, buffer is empty
// Head increments upon insertion and tail increases when bytes are read


// Init Ring Buffer Function: upon HC05_Init
void Ring_Buffer_Init(RingBuffer *Buffer){
	// Bluetooth Initialization

	Buffer->head = 0;
	Buffer->tail = 0;

}

// CheckEmpty Function: Returns 0 if Buffer is Empty. Otherwise, Return 1 (There is some data to be read)
inline int CheckEmpty(RingBuffer * Buffer){
	return (Buffer->head != Buffer->tail);
}


// CheckFull Function: Returns 0 if Not Full. Returns 1 if Full
inline int CheckFull(RingBuffer * Buffer){
	return (((Buffer->head + 1) % BUFFERSIZE )== Buffer->tail); // Since head and tail wraps around, and resets to 0 if increment after they hit BUFFER_SIZE - 1 index

}

// Insert Function

void Insert(RingBuffer * Buffer, char * Data, uint8_t dataSize){
	for(uint8_t i = 0; i < dataSize; i++){
		if(CheckFull(Buffer)){
			break;
		}
		Buffer->data[Buffer->head] = (char)Data[i];
		Buffer->head = (Buffer->head + 1) % BUFFERSIZE;
	}
	return;

}
// Read Function (Removes)
void ReadData(RingBuffer * Buffer,char * Data, uint8_t dataSize ){
	for(uint8_t i = 0; i < dataSize; i++){
		if(Buffer->head == Buffer->tail){ // Empty Case
			break;
		}
		Data[i] = (char)Buffer->data[Buffer->tail];
		Buffer->tail = (Buffer->tail + 1) % BUFFERSIZE; // Wraps around
	}
	return;

}

// CheckByteCount: Returns how many bytes can be read
inline int CheckByteCount(RingBuffer * Buffer){
	 return (Buffer->head + BUFFERSIZE - Buffer->tail) % BUFFERSIZE;
}

// CheckEmptyCount: Returns the number of bytes that can be inserted without overwritting unprocessed data
inline int CheckEmptyCount(RingBuffer * Buffer){
	return (BUFFERSIZE-1) - CheckByteCount(Buffer);
}

// Reset Buffer Function: Clear the Entire Buffer
void Reset_Buffer(RingBuffer * Buffer){
	Buffer->head = Buffer->tail = 0;
}




