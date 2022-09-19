
#include <lpc21xx.h>
#include "lcd_fun.c"
void beep(void);
void wdconfig(void);
int main(int argc, char const *argv[])
{
	wdconfig();
	beep();
	IODIR1|=(0xff<<17);

	IODIR0|=(1<<11);
	
	while(1){
		IOSET1=(1<<17);
		delay(500);
		IOCLR0=(1<<17);
		delay(500);
		if(IOPIN1&(1<<25)){
			WDFEED=0XAA;
	WDFEED=0X55;
			while(1){
		
	IOSET1=(0XFF<<17);
	delay(500);
	IOCLR1=(0xff<<17);
	delay(500);
		}
		}

	}

	return 0;
}

void wdconfig(void){

	WDMOD=(1<<0)|(1<<1);
	WDTC=0X1FFFFFF;
	
}
void beep(void){
IOSET0=(1<<11);
delay(500);
IOCLR0=(1<<11)	  ;
delay(500);
}