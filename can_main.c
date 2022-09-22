#include <lpc21xx.h>
#include "can_fun.c"
#include "lcd_fun.c"
unsigned int can_rx(void);
void can_tx(unsigned int d);
void can_config(void);

int main(int argc, char const *argv[])
{
	
	unsigned int b;
	lcd_config();
	can_config();


	can_tx(11223344);
	b=can_rx();
	lcd_data(b);
	return 0;
}