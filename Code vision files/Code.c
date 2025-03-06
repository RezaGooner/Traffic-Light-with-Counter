#include <mega32.h>
#include <delay.h>

// Define pins for traffic lights
#define RED_LED    PORTA.0
#define YELLOW_LED PORTA.1
#define GREEN_LED  PORTA.2

// Define pins for 7-segment displays
#define SEGMENT_PORT_1 PORTC // First 7-segment (units place)
#define SEGMENT_PORT_2 PORTD // Second 7-segment (tens place)
#define SEGMENT_DDR_1  DDRC
#define SEGMENT_DDR_2  DDRD

// Define numbers for 7-segment display (Common Anode)
const unsigned char segment_numbers[] = {
    0b11000000, // 0
    0b11111001, // 1
    0b10100100, // 2
    0b10110000, // 3
    0b10011001, // 4
    0b10010010, // 5
    0b10000010, // 6
    0b11111000, // 7
    0b10000000, // 8
    0b10010000  // 9
};

// Function to display a number on the 7-segment
void display_number(unsigned char number, unsigned char segment_port) {
    if (segment_port == 1) {
        SEGMENT_PORT_1 = segment_numbers[number];
    } else if (segment_port == 2) {
        SEGMENT_PORT_2 = segment_numbers[number];
    }
}

void main(void) {
    // Define all nedded variables at the beginning of the function
    unsigned char i, tens, ones;

    // Configure ports
    DDRA = 0xFF; // Port A as output for traffic lights
    DDRC = 0xFF; // Port C as output for the first 7-segment (units)
    DDRD = 0xFF; // Port D as output for the second 7-segment (tens)

    while (1) {
        // Red state (10 seconds)
        RED_LED = 1;    // Turn on the red LED
        YELLOW_LED = 0; // Turn off the yellow LED
        GREEN_LED = 0;  // Turn off the green LED
        for (i = 10; i > 0; i--) { // Countdown from 10 to 1
            tens = i / 10; // Tens digit
            ones = i % 10; // Units digit
            display_number(ones, 1); // Display units on the first 7-segment
            display_number(tens, 2); // Display tens on the second 7-segment
            delay_ms(1000); // 1-second delay
        }

        // Green state (10 seconds)
        RED_LED = 0;    // Turn off the red LED
        YELLOW_LED = 0; // Turn off the yellow LED
        GREEN_LED = 1;  // Turn on the green LED
        for (i = 10; i > 0; i--) { // Countdown from 10 to 1
            tens = i / 10; // Tens digit
            ones = i % 10; // Units digit
            display_number(ones, 1); // Display units on the first 7-segment
            display_number(tens, 2); // Display tens on the second 7-segment
            delay_ms(1000); // 1-second delay
        }

        // Yellow state (3 seconds)
        RED_LED = 0;    // Turn off the red LED
        YELLOW_LED = 1; // Turn on the yellow LED
        GREEN_LED = 0;  // Turn off the green LED
        for (i = 3; i > 0; i--) { // Countdown from 3 to 1
            tens = i / 10; // Tens digit
            ones = i % 10; // Units digit
            display_number(ones, 1); // Display units on the first 7-segment
            display_number(tens, 2); // Display tens on the second 7-segment
            delay_ms(1000); // 1-second delay
        }
    }
}