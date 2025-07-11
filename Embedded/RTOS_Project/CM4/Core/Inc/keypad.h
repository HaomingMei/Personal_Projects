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
void Restore_Rows(const Keypad_TypeDef* Keypad_Struct, uint16_t Row_Index); // Pulls all the pin to input high

// Sets Each Row Pin to Output, and sends a Low signal
// Check which Column Pin is Low, if there is a match, break and return True. Also
// Return the Corresponding the Row and Column by Reference
int Key_Pressed(const Keypad_TypeDef* Keypad_Struct, uint16_t* Pressed_Row, uint16_t* Pressed_Column );

void Drive_Row_Low(const Keypad_TypeDef* Keypad_Struct, uint16_t Row_Index);



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
static void Ring_Buffer_Init(RingBuffer *Bufer){
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


