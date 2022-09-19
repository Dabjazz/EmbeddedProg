#include <lpc21xx.h>
#include "lcd_fun.c"
void pll_36Mhz();
int main(int argc, char const *argv[])
{
	int counter=0;
	IODIR1|=(0Xff<<17);

	while(1){
		IOSET1=(0XFF<<17);
		delay(500);
		IOCLR1=(0XFF<<17);
		delay(500);
		counter++;
		if (counter==10)
		{
			/* code */
			pll_36Mhz();
		}
	}
	return 0;
}




void pll_36Mhz(void){
	/* M=3 P=4 MSEL[4:0]=00010 PSEL[6:5]=10*/

	PLLCFG=(1<<6)|(1<<1);
	PLLCON=(1<<0);
	PLLFEED=0XAA;
	PLLFEED=0X55;

	//check PLL locked or not
	while(!(PLLSTAT&(1<<10)));

	PLLCON=(1<<0)|(1<<1); //ENABLE PLL TO CONNECT TO CPU
	PLLFEED=0XAA;
	PLLFEED=0X55;
}