/*
 * keypad.h
 *
 *  Created on: Jun 28, 2025
 *      Author: haoming
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
#include <stdbool.h>


#endif /* INC_KEYPAD_H_ */
// Use extern because with normal declaration, every C file will make a copy of it
// When either including keypad.h or main.h. Using extern, we only need 1
// Copy of it through the program lifetime
extern const char Keypad_4by3[4][3];



typedef struct{
	uint32_t num_Rows;
	uint32_t num_Cols;


}Keypad_TypeDef;


void Restore_Keys(Keypad_TypeDef Keypad_Struct); // Pulls all the pin to input high
// Sets Each Row Pin to Output, and sends a Low signal
// Check which Column Pin is Low, if there is a match, break and return True. Also
// Return the Corresponding the Row and Column by Reference
bool Key_Pressed(Keypad_TypeDef Keypad_Struct, char* Pressed_Row, char* Pressed_Column );



