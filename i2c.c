/* SCL-P0.2     SDA-P0.3*/
#include<lpc21xx.h>
#include"lcd_fun.c"
void i2c_config(void);
void i2c_start(void);
void i2c_data(unsigned char d);
void i2c_stop(void);
int main()
{
lcd_config();
i2c_config();
i2c_start();
i2c_data(0xA0); // SLA=1010 000 0
i2c_data(0x00);	 //start with memory location 0x00

// MAster write operation
i2c_data('B');
i2c_data('O');
i2c_data('S');
i2c_data('C');
i2c_data('H');

i2c_stop();
return 0;
}

void i2c_config(void)
{

/*SCL-P0.2   SDA-P0.3*/
PINSEL0|=(1<<4)|(1<<6);
PINSEL0&=~(1<<5)|(1<<7);
/*config SCL=100Khz*/

I2SCLL=75;  //clk
I2SCLH=75;
I2CONSET=(1<<6);  //enable i2c peripheral
}

void i2c_start(void)
{
 I2CONCLR=(1<<3);  
 I2CONSET=(1<<5);   //start bit gen
 while(!(I2CONSET&(1<<3)));     //Monitor bit3 of CONSET, using polling method
 I2CONCLR=(1<<3);       //clear int flag
 I2CONCLR=(1<<5);      //clear start bit

}
void i2c_data(unsigned char d)
{
I2DAT=d;                    //Load the data on i2c data reg
while(!(I2CONSET&(1<<3)));  //check i2c int flag
I2CONCLR=(1<<3);                            //clear i2c int flag

}
void i2c_stop(void)
{
I2CONSET=(1<<4);
}