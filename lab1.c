#include <avr/io.h>
#include "lcd.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>
#define LED_output PORTD
#define PIR_input PINB

unsigned int num = 0;
char val[16];

// 1 leu si 00 bani.

void get_val_str() {
	int i;
	for (i = 0; i < 16; ++i)
		val[i] = 0;

	if (num >= 100) {
		// lei
		unsigned char lei = num / 100;
		unsigned char bani = (((num / 10) - (lei * 10)) * 10) + (num % 10);

		sprintf(val, "%d.%d LEI", lei, bani);
	} else {
		// Sub 1 leu => Bani
		if (num < 20) {
			// bani
			sprintf(val, "%d BANI", num);
		} else {
			// de bani
			sprintf(val, "%d DE BANI", num);
		}
	}
}

int main(void) {
	LCD_init();
	LCD_toggle_backlight();

	char val[16];
	// PD0 = senzor 5 bani
	// Il fac de intrare
	//DDRB = 0x00;
	DDRD &= ~(1 << PD0);
	DDRD &= ~(1 << PD1);
	DDRD |= (1 << PD7);
	
	//DDRD = 0xFF;
	PORTD |= (1 << PD0);
	PORTD |= (1 << PD1);

	unsigned char on10 = 0;
	unsigned char on50 = 0;

	sprintf(val, "0.00 LEI");

	while(1){
		// 50 bani
		LCD_printAt(0x00, "Ati introdus:");
		if ((PIND & (1 << PD0)) == 0) {
			// aprind led
			// 50 bani
			PORTD |= (1 << PD7);
			on50 = 1;
		} else if ((PIND & (1 << PD1)) == 0) {
			// 10 bani
			PORTD |= (1 << PD7);
			on10 = 1;
		} else {
			// sting led
			PORTD &= ~(1 << PD7);
			if (on50 == 1) {
				num += 40;
				on50 = 0;
		//		get_val_str();
				_delay_ms(100);
			} else if (on10 == 1) {
				num += 10;
				on10 = 0;
		//		get_val_str();
				_delay_ms(100);
			}
		}
		//get_val_str();
		//LCD_printAt(0x40, val);
		
		sprintf(val, "%d Bani", num);
		LCD_printAt(0x40, val);
	}

	return 0;
}

