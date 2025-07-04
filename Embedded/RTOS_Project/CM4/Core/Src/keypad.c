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
const

void Restore_Rows(Keypad_TypeDef Keypad_Struct){
	// Set all the Row GPIO Pins to Input and Pull Up
}

bool Key_Pressed(Keypad_TypeDef Keypad_Struct, char* Pressed_Row, char* Pressed_Column );



