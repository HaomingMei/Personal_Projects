/*
 * HC05_Bluetooth.h
 *
 *  Created on: Jul 7, 2025
 *      Author: haoming
 */

#ifndef INC_HC05_BLUETOOTH_H_
#define INC_HC05_BLUETOOTH_H_
#include <stdbool.h>
#include <stdint.h>
#include "stm32h747xx.h"
#include "stm32h7xx_hal.h"
extern UART_HandleTypeDef huart8;

// Declare Ring Buffer Struct Here



// Init Ring Buffer Function: upon HC05_Init


// CheckEmpty Function

// CheckFull Function

// Insert Function

// Read Function (Removes)

// CheckByteCount

// CheckEmptyCount

// Reset Buffer Function


// Initializes the Bluetooth Classic Stack: Linker & PHY <-> HCI & Data Mode <-> L2CAP <-> SDP & RFCOMM <-> SPP Profile <-> MCU App
void HC05_Init(void);

// Used to Send Data
void HC05_BlueTooth_UART_TX(UART_HandleTypeDef *huart, uint8_t* data, uint16_t size);

//* Used for Parsing Data (Received)
void HC05_Process(UART_HandleTypeDef *huart);


#endif /* INC_HC05_BLUETOOTH_H_ */
