#include <reg51.h>

unsigned char floor; 
unsigned char targetFloor = 0; 
unsigned char callButtons = 0; 

unsigned char displayValues[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80};


void moveElevator() {
    if (floor < targetFloor) {
        floor++;
    } else if (floor > targetFloor) {
        floor--;
    }
    targetFloor = floor; 
}

void checkCallButtons() {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        if ((callButtons & (1 << i)) != 0) {
            targetFloor = i;
            break;
        }
    }
}

void main (void) {
    unsigned char SW;
    while(1) {
        SW = P1;
        callButtons = P3;
        if (floor == targetFloor) {
            checkCallButtons();
            switch(SW) {
                case(1):
                {
                    targetFloor = 0;
                    break;
                }
                case(2):
                {
                    targetFloor = 1;
                    break;
                }
                case(4):
                {
                    targetFloor = 2;
                    break;
                }
                case(8):
                {
                    targetFloor = 3;
                    break;
                }
                case(16):
                {
                    targetFloor = 4;
                    break;
                }
                case(32):
                {
                    targetFloor = 5;
                    break;
                }
                case(64):
                {
                    targetFloor = 6;
                    break;
                }
                case(128):
                {
                    targetFloor = 7;
                    break;
                }
            }
        }
        moveElevator();
        P0 = displayValues[floor + 1]; 	
        P2 = 1 << floor; 
    }
}
