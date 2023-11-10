#include <reg51.h>

void main (void){
	unsigned char SW;
	SW =P1;

	switch(SW){
		case(0):
		{
			P0 = 0xC0;
			P2 = 0x00;
			break;
		}
		case(1):
		{
			P0 = 0xF9;
			P2 = 0x01;
			break;
		}
		case(2):
		{
			P0 = 0xA4;
			P2 = 0x02;
			break;
		}
		case(4):
		{
			P0 = 0xB0;
			P2 = 0x04;
			break;
		}
		case(8):
		{
			P0 = 0x99;
			P2 = 0x08;
			break;
		}
		case(16):
		{
			P0 = 0x92;
			P2 = 0x10;
			break;
		}
		case(32):
		{
			P0 = 0x82;
			P2 = 0x20;
			break;
		}
		case(64):
		{
			P0 = 0xF8;
			P2 = 0x40;
			break;
		}
		case(128):
		{
			P0 = 0x80;
			P2 = 0x80;
			break;
		}
	
	}
		
}
