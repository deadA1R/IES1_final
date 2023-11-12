										// Final Project 
										// CS-2117
										// Dias Amangeldy, Ilya Rogov, Beybarys Rysbek all from CS-2117

#include <reg51.h> // Connecting the library for working with 8051 microcontrollers

unsigned char floor; // Variable for storing the current floor
unsigned char targetFloor = 0; // Variable for storing the target floor
unsigned char buttonsOnFloors = 0; // Variable for storing the status of call buttons on floors
unsigned char buttonsInElevator = 0; // Variable for storing the status of call buttons in elevator

// Array, for displaying values from 1 to 8 on a 7-segment display
unsigned char displayValues[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80};

// Method for moving between floors
void moveElevator() {
    if (floor < targetFloor) { // If the current floor is lower than the target one, the one we want to get to
        floor++; // Moving up one floor
    } else if (floor > targetFloor) { // If the current floor is larger than the target one, the one we want to get to
        floor--; // Moving down one floor
    }
    targetFloor = floor; // We save the current floor as a standard value so that the elevator remains on this floor
}

// Method for checking which button was pressed
void checkButtons(unsigned char button){
	 unsigned char i; // Variable i for loop
    for (i = 0; i < 8; i++) { // Check each button
        if ((button & (1 << i)) != 0) { // If the call button is pressed
            targetFloor = i; // Setting the target floor to which the elevator will be moved
            break; // Break the IF operation and exit the method
        }
    }
}

// The main method, the program starts working here
void main (void) {
    while(1) { // Infinite Loop
        buttonsInElevator = P1; // Reading the status of the buttons inside the elevator
        buttonsOnFloors = P3; // Reading the status of the call buttons on the floors
        if (floor == targetFloor) { // If the elevator is on the target floor
						checkButtons(buttonsInElevator); // Checking the call buttons in the elevator, calling the method
						checkButtons(buttonsOnFloors); // Checking the call buttons on the floors, calling the method
        }
        moveElevator(); // Moving the elevator
        P0 = displayValues[floor + 1]; 	// Displaying the current floor on a 7-segment display
        P2 = 1 << floor; // Lights the corresponding light bulb
    }
}
