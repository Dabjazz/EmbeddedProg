/*
SCK-->P0.4
MISO-->P0.5
MOSI-->P0.6
SS-->P0.7
*/
#include <lpc21xx.h>

#include "lcd_fun.c"

void spi_data(unsigned int d);
int main(int argc, char const *argv[])
{
	/* code */
	//mASTER CONFIG
	PINSEL0|=(1<<8)|(1<<10)|(1<<12);
PINSEL0&=~((1<<9)|(1<<11)|(1<<13));
IODIR0|=(1<<7);  //CONFIG (SS)-->P0.7 as OP port
// 16 bit, CPOL=1, CPHASE =1, Master Mode,MSB side, no Int
S0SPCR=(1<<2)|(1<<3)|(1<<4)|(1<<5);
// SCK=1.875 Mhz
S0SPCCR=8;
// Slave config

spi_data(0x090f);
spi_data(0x0a0f);
spi_data(0x0b03);
spi_data(0x0c01);

spi_data(0x0f01);//disp test mode
delay(2000);
spi_data(0x0f00);//normal mode


//ACtual data transmission 4 5 6 7
spi_data(0x0104);
spi_data(0x0205);
spi_data(0x0306);
spi_data(0x0407);

		return 0;
}

void spi_data(unsigned int d){
	//load data to spi data reg
	//pull ss[p0.7] line to low to select the slave
//check the data transmitted or not
	//make SS line high--> Disconnects the slave

	S0SPDR=d;

	IOCLR0|=(0<<7);
	while(!(S0SPSR&(1<<7))){
		IOSET0|=(1<<7);
	}
}