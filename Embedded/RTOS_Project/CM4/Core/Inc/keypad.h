/*
 * keypad.h
 *
 *  Created on: Jun 28, 2025
 *      Author: haoming
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include <stdbool.h>
#include <stdint.h>
#include "stm32h747xx.h"
#endif /* INC_KEYPAD_H_ */
// Use extern because with normal declaration, every C file will make a copy of it
// When either including keypad.h or main.h. Using extern, we only need 1
// Copy of it through the program lifetime
extern const char Keypad_4by3[4][3];

typedef struct{
	 GPIO_TypeDef *port;
	 uint16_t      pin;  // One-Hot Encoded, used for the gpio init in reset
	 uint16_t      pin_number; // Used in the scanning function
}GPIO_PIN;

// Record this information when we do GPIO INIT
typedef struct{
	GPIO_PIN Row_Pins[4];
	GPIO_PIN Col_Pins[3];

}Keypad_TypeDef;


// No duplication error here since declaration needs no storage
// We will write the function in keypad.c
void Reset_Rows(void); // Pulls all the pin to input high

// Sets Each Row Pin to Output, and sends a Low signal
// Check which Column Pin is Low, if there is a match, break and return True. Also
// Return the Corresponding the Row and Column by Reference
bool Key_Pressed(Keypad_TypeDef Keypad_Struct, char* Pressed_Row, char* Pressed_Column );



