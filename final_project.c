#include <reg51.h>

void main (void){
	unsigned char SW;
	SW =P1;
	switch(SW){
		case(0):
		{
			P2 = 0x03;
			break;
		}
		case(1):
		{
			P2 = 0x9F;
			break;
		}
		case(2):
		{
			P2 = 0x25;
			break;
		}
		case(3):
		{
			P2 = 0x0D;
			break;
		}
		case(4):
		{
			P2 = 0x99;
			break;
		}
		case(5):
		{
			P2 = 0x49;
			break;
		}
		case(6):
		{
			P2 = 0x41;
			break;
		}
		case(7):
		{
			P2 = 0x1F;
			break;
		}
		case(8):
		{
			P2 = 0x01;
			break;
		}
	
	}
		
}
