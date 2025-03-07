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

// Define pins for buttons
#define RED_BUTTON    PINB.0  // Use PINB for reading button state
#define GREEN_BUTTON  PINB.1  // Use PINB for reading button state
#define YELLOW_BUTTON PINB.2  // Use PINB for reading button state

// Define pins for mode switch
#define MODE_SWITCH_1 PINB.3  // Mode 1: Normal operation
#define MODE_SWITCH_2 PINB.4  // Mode 2: Time adjustment

// Define variables for traffic light timings
unsigned char red_time = 10;    // Default red time
unsigned char green_time = 10;  // Default green time
unsigned char yellow_time = 3;  // Default yellow time

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

// Function to increase the time for a specific light
void increase_time(unsigned char *time) {
    if (*time < 99) {
        (*time)++; // Increase time
    } else {
        *time = 1; // Reset to 1 if time reaches 99
    }
}

// Function to handle time adjustment mode
void time_adjustment_mode() {
    // Turn off all traffic lights
    RED_LED = 0;
    YELLOW_LED = 0;
    GREEN_LED = 0;

    while (MODE_SWITCH_2 == 1) {
        // Adjust red time
        display_number(red_time % 10, 1); // Display units
        display_number(red_time / 10, 2); // Display tens
        if (RED_BUTTON == 1) {
            increase_time(&red_time); // Increase red time
            delay_ms(300); // Debounce delay
            while (RED_BUTTON == 1); // Wait for button release
        }

        // Adjust green time
        display_number(green_time % 10, 1); // Display units
        display_number(green_time / 10, 2); // Display tens
        if (GREEN_BUTTON == 1) {
            increase_time(&green_time); // Increase green time
            delay_ms(300); // Debounce delay
            while (GREEN_BUTTON == 1); // Wait for button release
        }

        // Adjust yellow time
        display_number(yellow_time % 10, 1); // Display units
        display_number(yellow_time / 10, 2); // Display tens
        if (YELLOW_BUTTON == 1) {
            increase_time(&yellow_time); // Increase yellow time
            delay_ms(300); // Debounce delay
            while (YELLOW_BUTTON == 1); // Wait for button release
        }

        // Check if mode switch is changed to normal mode
        if (MODE_SWITCH_1 == 1) {
            break; // Exit time adjustment mode
        }
    }
}

void main(void) {
    // Define all variables at the beginning of the function
    unsigned char i, tens, ones;

    // Configure ports
    DDRA = 0xFF; // Port A as output for traffic lights
    DDRC = 0xFF; // Port C as output for the first 7-segment (units)
    DDRD = 0xFF; // Port D as output for the second 7-segment (tens)
    DDRB = 0x00; // Port B as input for buttons and mode switch

    while (1) {
        // Check mode switch
        if (MODE_SWITCH_1 == 1) {
            // Mode 1: Normal operation
            // Red state
            RED_LED = 1;    // Turn on the red LED
            YELLOW_LED = 0; // Turn off the yellow LED
            GREEN_LED = 0;  // Turn off the green LED
            for (i = red_time; i > 0; i--) { // Countdown from red_time to 1
                if (MODE_SWITCH_2 == 1) break; // Exit if mode switch changes
                tens = i / 10; // Tens digit
                ones = i % 10; // Units digit
                display_number(ones, 1); // Display units on the first 7-segment
                display_number(tens, 2); // Display tens on the second 7-segment
                delay_ms(1000); // 1-second delay
            }

            // Green state
            RED_LED = 0;    // Turn off the red LED
            YELLOW_LED = 0; // Turn off the yellow LED
            GREEN_LED = 1;  // Turn on the green LED
            for (i = green_time; i > 0; i--) { // Countdown from green_time to 1
                if (MODE_SWITCH_2 == 1) break; // Exit if mode switch changes
                tens = i / 10; // Tens digit
                ones = i % 10; // Units digit
                display_number(ones, 1); // Display units on the first 7-segment
                display_number(tens, 2); // Display tens on the second 7-segment
                delay_ms(1000); // 1-second delay
            }

            // Yellow state
            RED_LED = 0;    // Turn off the red LED
            YELLOW_LED = 1; // Turn on the yellow LED
            GREEN_LED = 0;  // Turn off the green LED
            for (i = yellow_time; i > 0; i--) { // Countdown from yellow_time to 1
                if (MODE_SWITCH_2 == 1) break; // Exit if mode switch changes
                tens = i / 10; // Tens digit
                ones = i % 10; // Units digit
                display_number(ones, 1); // Display units on the first 7-segment
                display_number(tens, 2); // Display tens on the second 7-segment
                delay_ms(1000); // 1-second delay
            }
        } else if (MODE_SWITCH_2 == 1) {
            // Mode 2: Time adjustment
            time_adjustment_mode();
        }
    }
}