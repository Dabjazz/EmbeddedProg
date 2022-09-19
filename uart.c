/*Tx--p0.0 Rx--p0.1*/
#include <lpc21xx.h>
#include "lcd_fun.c"
void uart_str(unsigned char *ptr);
int main()
{	   	char *ptr="VGHS";
	unsigned char val;
	PINSEL0|=(1<<0)|(1<<2);
	PINSEL0&=~((1<<1|(1<<3)));
	lcd_config();
	/*eNABLE DIVISOR LATCH REGS*/
	IODIR1|=(1<<17);
	U0LCR=(1U<<7);
	U0DLL=97;
	U0DLM=0;
	U0LCR=~(1U<<7);
	U0IER=(1<<0)|(1<<1);

	/*CONFIG UART in 8bit,1 stop bit,No parity, Full Duplex Mode*/
	U0LCR=(1<<0)|(1<<1);

	while(1){
		while(!(U0LSR&(1<<0)|(1<<5)));
		val=U0RBR;
		lcd_data(val);
		U0THR=val;
		
		//uart_str(ptr);
		delay(100);
	}
	return 0;
}
void uart_str(unsigned char *ptr)
{
while(*ptr!='\0')
{
U0THR=(*ptr);
ptr++;
}
}
void uart_int_config(void){

	VICIntSelect&=!~(1<<6);
	VICVectCntl0=(1<<5)|(6<<0);
	VICVectAddr0=(long)UART_IRQ_Handler;
	VICIntEnable=(1<<6);
}
void UART_IRQ_Handler(void)__irq{
	unsigned char read;
	IOSET0=(1<<11);
	delay(100);
	IOCLR0=(1<<11);
	delay(100);

	read=U0IIR;
	VICVectAddr=0;
}