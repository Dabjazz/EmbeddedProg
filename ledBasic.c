/*

*/

#include<lpc21xx.h>
#define	RS (1<<10)
#define RW (1<<12)
#define EN (1<<13)
#define DATA (0xff<<15) //Mask p.015 to p0.22
  void lcd_config(void);
			   void lcd_cmd(unsigned char c);
			   void lcd_data(unsigned char d);
void delay(unsigned int a);
int main(){
 

lcd_config();
lcd_data('A');

return 0;
}


void lcd_config(void){
 IODIR0|=RS|RW|EN|DATA;
 /*Command Tx*/
 lcd_cmd(0x38);
 lcd_cmd(0x0E);
 lcd_cmd(0x01);
 lcd_cmd(0x80);
}

void lcd_cmd(unsigned char c){
IOCLR0=DATA;	//Clear Data Lines
IOSET0=(c<<15);//Load cmd/ data on Data Lines
IOCLR0=RS;//RS=0 for cmd
IOCLR0=RW;//RW=0
IOSET0=EN;//EN=1
delay(10);
IOCLR0=EN;//EN=0

}

void lcd_data(unsigned char d){
IOCLR0=DATA;	//Clear Data Lines
IOSET0=(d<<15);//Load cmd/ data on Data Lines
IOSET0=RS;//RS=0 for cmd
IOCLR0=RW;//RW=0
IOSET0=EN;//EN=1
delay(10);
IOCLR0=EN;
}

void delay(unsigned int a){
unsigned int i,j;
	for(i=0;i<a;i++){
	for(j=0;j<6000;j++){
	
	}
	}
}