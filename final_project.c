#include <reg51.h>

void main (void){
	unsigned char SW;
	SW =P1;
	switch(SW){
		case(0):
		{
			P0 = 0x03;
			P2 = 0x00;
			break;
		}
		case(1):
		{
			P0 = 0x9F;
			P2 = 0x01;
			break;
		}
		case(2):
		{
			P0 = 0x25;
			P2 = 0x02;
			break;
		}
		case(3):
		{
			P0 = 0x0D;
			P2 = 0x04;
			break;
		}
		case(4):
		{
			P0 = 0x99;
			P2 = 0x08;
			break;
		}
		case(5):
		{
			P0 = 0x49;
			P2 = 0x10;
			break;
		}
		case(6):
		{
			P0 = 0x41;
			P2 = 0x20;
			break;
		}
		case(7):
		{
			P0 = 0x1F;
			P2 = 0x40;
			break;
		}
		case(8):
		{
			P0 = 0x01;
			P2 = 0x80;
			break;
		}
	
	}
		
}
