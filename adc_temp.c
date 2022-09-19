/*
Temp sensor - P0.28
Pot			-P0.21
*/
#include <lpc21xx.h>
#include "lcd_fun.c"

unsigned int val;
void adc_config(void);
void adc_data(void);
int main(){
		  lcd_config();
		  adc_config();

		  while(1){
		  
		  }
return 0;
}


void adc_config(void){
/*Config P0.28 AS AIN1 using PINSEL*/
PINSEL1|=(1<<24);
PINSEL1&=~(1<<25);
/* Sel Ch=1,Clk Div=4, Burst Mode=1,PDN=1*/

ADCR=(1<<1)|(4<<8)|(1<<16)|(1<<21);
}


void adc_data(void){
while(!(ADDR&(1<<31)));//Check Done bit set or not using polling method
val=(ADDR&(0x3FF<<6));//extract 10 bit data to a variable
val=val>>








6;//To get as LSB					
val=val/3.3;  // Convert temp into degree
lcd_num(val);
delay(1000);
lcd_cmd(0x01);					
					}