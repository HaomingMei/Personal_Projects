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
//	GPIO_InitTypeDef GPIO_InitStruct = {0};
//	GPIO_InitStruct.Pin = KEYPAD_COLUMN1_D7_Pin|KEYPAD_ROW4_D6_Pin|KEYPAD_COLUMN3_D9_Pin|KEYPAD_COLUMN2_D8_Pin
//            |KEYPAD_ROW1_D2_Pin|KEYPAD_ROW2_D4_Pin;
//	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	//GPIO_InitStruct.Pull = ;
}

int Key_Pressed(Keypad_TypeDef Keypad_Struct, char* Pressed_Row, char* Pressed_Column ){
	// Set all the Row GPIO Pins to Input and Pull Up
//		uint32_t temp;
//		uint32_t position;
//		for(int i = 0; i < 4; i++){
//			// Input
//			position = KeyPad_Struct.Row_Pins[i].pin; // Get the Pin Number
//			temp = KeyPad_Struct.Row_Pins[i]->MODER;
//			temp &= ~(GPIO_MODER_MODE0 << (position * 2U)); // Clearing in case of pre-existing value
//			 temp |= ((GPIO_Init->Mode & GPIO_MODE) << (position * 2U));
//			KeyPad_Struct.Row_Pins[i]->MODER = 0x00 << (position * 2U);
//
//			// Pull Up
//		}
	return 0; // 0 = False, 1 = True
}



