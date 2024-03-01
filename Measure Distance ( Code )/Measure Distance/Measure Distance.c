/******************************************************************************
 *
 * File Name: Measure Distance.c
 *
 * Description: Measuring the distance using Ultrasonic Sensor ( HC-SR04 ).
 *
 * Author: Khaled Samy
 *
 *******************************************************************************/

#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h> /* To use the delay function */
#include "HC-SR04.h"
#include "lcd.h"

int main(void) {
	uint16 distance;

	LCD_init(); /* Initialize the LCD Driver */
	LCD_displayStringRowColumn(0, 0, "Distance = ");
	LCD_displayStringRowColumn(0, 14, "cm");

	SREG |= (1 << 7); /* Enable Global Interrupt I-Bit */

	Ultrasonic_init(); /* Initialize the Ultrasonic Sensor Driver */

	while (1) {
		LCD_moveCursor(0, 11);
		distance = Ultrasonic_readDistance();
		if (distance < 10) {
			/* To clear the 2 digits after the number */
			LCD_intgerToString(distance);
			LCD_displayString("  ");
		} else if (distance < 100) {
			/* To clear the digit after the number */
			LCD_intgerToString(distance);
			LCD_displayCharacter(' ');
		} else {
			LCD_intgerToString(distance);
		}
	}

	return 0;
}
