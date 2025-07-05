/*
 * keypad.c
 *
 *  Created on: Jun 28, 2025
 *      Author: haoming
 */
#include "keypad.h"

const char Keys_4by3[4][3] = {
		{'1', '2', '3' },
		{'4', '5', '6' },
		{'7', '8', '9'},
		{'*', '0', '#'}

};
#define KEYPAD_MODE_INPUT (0x0UL << 0U)
#define KEYPAD_PULL_UP 0x00000001U
void Restore_Rows(Keypad_TypeDef Keypad_Struct, uint16_t Row_Index){
	// Set the Row GPIO Pins to Input and Pull Up
	uint32_t temp;
	uint32_t position;
	position = Keypad_Struct.Row_Pins[Row_Index].pin_number; // Get the Pin Number
	//* Set the Port Mode Register (MODER) to Input

	temp = Keypad_Struct.Row_Pins[Row_Index].port->MODER;

	// Position has to be multiplied by 2 since each Pin takes 2 bits (total 32 bits)
	temp &= ~(0x00 << (position * 2U)); // Clearing in case of pre-existing value
	temp |= ((KEYPAD_MODE_INPUT) << (position * 2U)); // Setting
	Keypad_Struct.Row_Pins[Row_Index].port->MODER= temp; // Updating the Register

	//* Set the Pull-Up/Pull-Down Register (PUPDR) to PullUp

	temp = Keypad_Struct.Row_Pins[Row_Index].port->PUPDR;
	temp &= ~(0x00 << (position * 2U)); // Clear
	temp |= ((KEYPAD_PULL_UP) << (position * 2U)); // Setting Pull-Up
	Keypad_Struct.Row_Pins[Row_Index].port->PUPDR = temp;


}

int Key_Pressed(Keypad_TypeDef Keypad_Struct, char* Pressed_Row, char* Pressed_Column ){
	// Resetting the Row to Input Mode with Pull Up
	return 0; // 0 = False, 1 = True
}



