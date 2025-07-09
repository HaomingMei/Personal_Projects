/*
 * keypad.c
 *
 *  Created on: Jun 28, 2025
 *      Author: haoming
 */
#include "keypad.h"
#include "stm32h7xx_hal.h"

const char Keys_4by3[4][3] = {
		{'1', '2', '3' },
		{'4', '5', '6' },
		{'7', '8', '9'},
		{'*', '0', '#'}

};
#define KEYPAD_MODE_INPUT (0x0UL << 0U)
#define KEYPAD_MODE_OUTPUT (0x1uL << 0U)
#define KEYPAD_PULL_UP 0x00000001U
#define KEYPAD_OUTPUT_PUSH_PULL (0x0UL << 0U)
#define KEYPAD_NO_PUSH_PULL (0x0UL<<0U)
void Restore_Rows(const Keypad_TypeDef* Keypad_Struct, uint16_t Row_Index){
	// Set the Row GPIO Pins to Input and Pull Up
	uint32_t temp;
	uint32_t position;
	position = Keypad_Struct->Row_Pins[Row_Index].pin_number; // Get the Pin Number
	//* Set the Port Mode Register (MODER) to Input

	temp = Keypad_Struct->Row_Pins[Row_Index].port->MODER;

	// Position has to be multiplied by 2 since each Pin takes 2 bits (total 32 bits)
	temp &= ~(0x3U << (position * 2U)); // Clearing in case of pre-existing value
	temp |= ((KEYPAD_MODE_INPUT) << (position * 2U)); // Setting
	Keypad_Struct->Row_Pins[Row_Index].port->MODER= temp; // Updating the Register

	//* Set the Pull-Up/Pull-Down Register (PUPDR) to PullUp

	temp = Keypad_Struct->Row_Pins[Row_Index].port->PUPDR;
	temp &= ~(0x3U << (position * 2U)); // Clear
	temp |= ((KEYPAD_PULL_UP) << (position * 2U)); // Setting Pull-Up
	Keypad_Struct->Row_Pins[Row_Index].port->PUPDR = temp;

	// I only have to set MODE and Pull-Up because other register are don't care in
	// input mode.
}

//* Drive the Specified Row Pin Low, then check if any of column pins are LOW
void Drive_Row_Low(const Keypad_TypeDef* Keypad_Struct, uint16_t Row_Index){
	uint32_t temp;
	uint32_t position;
	position = Keypad_Struct->Row_Pins[Row_Index].pin_number; // Get the Pin Number

	//* Setting the Mode to Output
	temp = Keypad_Struct->Row_Pins[Row_Index].port->MODER;

	// Position has to be multiplied by 2 since each Pin takes 2 bits (total 32 bits)
	temp &= ~(0x3U << (position * 2U)); // Clearing in case of pre-existing value
	temp |= ((KEYPAD_MODE_OUTPUT) << (position * 2U)); // Setting
	Keypad_Struct->Row_Pins[Row_Index].port->MODER= temp; // Updating the Register

	//* Setting no Push and no Pull
	temp = Keypad_Struct->Row_Pins[Row_Index].port->PUPDR;
	temp &= ~(0x3U << (position * 2U)); // Clear
	temp |= ((KEYPAD_NO_PUSH_PULL) << (position * 2U)); // Setting Pull-Up
	Keypad_Struct->Row_Pins[Row_Index].port->PUPDR = temp;

	//* Setting the OTYPER to be Output Push-Pull
	temp = Keypad_Struct->Row_Pins[Row_Index].port->OTYPER;
	temp &= ~(0x1U << (position));
	temp |= ((KEYPAD_OUTPUT_PUSH_PULL) << (position));
	Keypad_Struct->Row_Pins[Row_Index].port->OTYPER = temp;

	//* Drive the Specific Pin at the Correct Position to 0 (LOW)
	Keypad_Struct->Row_Pins[Row_Index].port->ODR &= ~(GPIO_PIN_SET << position);


}
int Key_Pressed(const Keypad_TypeDef* Keypad_Struct, uint16_t* Pressed_Row, uint16_t* Pressed_Column ){
	//* Setting the Row to Output Mode and Send out a Low Signal
	for(int row = 0; row < 4; row ++){
		Drive_Row_Low(Keypad_Struct, row);
		//* Check if Any Column Pins Are Low
		for(int col = 0; col < 3; col++){
			// -> is use because Keypad_struct is a pointer, we need to dereference and then access the members (. requires object,
			// and we get that by dereferencing)
			if(HAL_GPIO_ReadPin(Keypad_Struct->Col_Pins[col].port, Keypad_Struct->Col_Pins[col].pin) == GPIO_PIN_RESET){
				*Pressed_Row = row;
				*Pressed_Column = col;
				return 1;
			}
		}
		//* Resetting the Row to Input Mode with Pull Up
		Restore_Rows(Keypad_Struct,row);


	}
	return 0; // 0 = False, 1 = True
}
