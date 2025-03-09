#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

uint8_t segment_numbers[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
uint8_t segment_po[2] = {0x73, 0x3F};

enum Modes { NORMAL, SET_RED, SET_GREEN, BLINK_RED, OFF };
volatile int mode = NORMAL;
volatile int red_time = 10, green_time = 10, yellow_time = 3;

void display_number(int num);
void check_switches(void);

void display_number(int num) {
	PORTD = segment_numbers[num / 10];
	PORTC = segment_numbers[num % 10];
}

void check_switches(void) {
	if (!(PINB & (1 << PB0))) mode = NORMAL;
	if (!(PINB & (1 << PB1))) mode = SET_RED;
	if (!(PINB & (1 << PB2))) mode = SET_GREEN;
	if (!(PINB & (1 << PB3))) mode = BLINK_RED;
	if (!(PINB & (1 << PB4))) mode = OFF;
}

int main(void) {
	DDRA = 0x07;
	DDRC = 0x7F;
	DDRD = 0x7F;
	DDRB = 0x00;
	PORTB = 0xFF; // ???? ???? Pull-Up ????? ???? ???????

	while (1) {
		check_switches();

		if (mode == NORMAL) {
			PORTA = 0x04;
			for (int i = red_time; i >= 0; i--) {
				check_switches();
				if (mode != NORMAL) break;
				display_number(i);
				_delay_ms(1000);
			}

			PORTA = 0x01;
			for (int i = green_time; i >= 0; i--) {
				check_switches();
				if (mode != NORMAL) break;
				display_number(i);
				_delay_ms(1000);
			}

			PORTA = 0x02;
			for (int i = yellow_time; i >= 0; i--) {
				check_switches();
				if (mode != NORMAL) break;
				display_number(i);
				_delay_ms(1000);
			}
		}
		else if (mode == SET_RED) {
			PORTA = 0x04; // ???? ???? ???? ?????
			while (mode == SET_RED) {
				check_switches();
				display_number(red_time);

				if (!(PINB & (1 << PB5))) {
					red_time++;
					display_number(red_time);
					_delay_ms(200);
				}
				if (!(PINB & (1 << PB6))) {
					red_time--;
					display_number(red_time);
					_delay_ms(200);
				}
			}
		}
		else if (mode == SET_GREEN) {
			PORTA = 0x01; // ???? ??? ???? ?????
			while (mode == SET_GREEN) {
				check_switches();
				display_number(green_time);

				if (!(PINB & (1 << PB5))) {
					green_time++;
					display_number(green_time);
					_delay_ms(200);
				}
				if (!(PINB & (1 << PB6))) {
					green_time--;
					display_number(green_time);
					_delay_ms(200);
				}
			}
		}
		else if (mode == BLINK_RED) {
			while (mode == BLINK_RED) {
				check_switches();
				PORTA = 0x04;
				PORTD = segment_po[0];
				PORTC = segment_po[1];
				_delay_ms(500);
				PORTA = 0x00;
				_delay_ms(500);
			}
		}
		else if (mode == OFF) {
			while (mode == OFF) {
				check_switches();
				PORTA = 0x00;
				PORTD = 0x00;
				PORTC = 0x00;
			}
		}
	}
}
