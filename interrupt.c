/* Generate an int from timer 0 for every 5sec
Toggle LED p1.24 in the ISR program
toggle LED p1.17 in the main program
*/
#include <lpc21xx.h>
#include "lcd_fun.c"
void timer_config(void);
void time_int_config(void);
void Timer_IRQ_Handler(void)__irq;
int main()
{
	/* code */
	IODIR1|=(0xff<<17);
	lcd_config();
	timer_config();
	time_int_config();

	while(1){
	IOSET1=(1<<17);
	delay(500);
	IOCLR1=(1<<17);
	delay(500);	
	}
	return 0;
}

void timer_config(void)
{
   T0PR=14;
   T0MR0=5000000;
   T0MCR=(1<<1)|(1<<0);//Or we can directly give 3      MR0 in rep and Int mode
   T0TCR=(1<<1); //clear counter
   T0TCR=(1<<0);//enable timer

}
/*use SLOT0 for Timer0 Int*/
void time_int_config(void){				//Timer0 IRQ SRC NO-->4
	VICIntSelect&=~(1<<4);	//Config timer0 Int as IRQ
	VICVectCntl0=(1<<5)|(4<<0);	//GIE=1, Source No
	VICVectAddr0=(long)Timer_IRQ_Handler;	//Load ISR address
	VICIntEnable=(1<<4);	//ENABLE Timer0 Int
}

void Timer_IRQ_Handler(void)__irq{
	IOSET1=(1<<24);
	delay(500);
	IOCLR1=(1<<24);
	delay(500);
	lcd_str("Yash");
	delay(1000);
	lcd_cmd(0x01);
	T0IR=(1<<0);	//clear int flag
	VICVectAddr=0;	//Std return address
}