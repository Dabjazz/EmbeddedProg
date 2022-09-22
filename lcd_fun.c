#include"lcd_header.c"
void lcd_config(void)
{
//config LCD prt pins as output port
IODIR0|=RS|RW|EN|DATA;
//command tx
lcd_cmd(0x38);
lcd_cmd(0x0E);
lcd_cmd(0x01);
lcd_cmd(0x80);


}

void lcd_cmd(unsigned char c)
{
IOCLR0=DATA;  //clear data lines
IOSET0=(c<<15);//load cmd/data on data lines
IOCLR0=RS;    //RS=0 for cmd
IOCLR0=RW;   //RW=0
IOSET0=EN;    //En=1
delay(10);
IOCLR0=EN;    //En=0

}

void lcd_data( unsigned char d)
{

  IOCLR0=DATA;  //clear data lines
  
IOSET0=(d<<15);//load cmd/data on data lines
IOSET0=RS;    //RS=1 for data
IOCLR0=RW;   //RW=0
IOSET0=EN;    //En=1
delay(10);
IOCLR0=EN;
}
void delay(unsigned int a)
{
unsigned int i,j;
for(i=0;i<a;i++)
for(j=0;j<6000;j++)
{
  
}
}

void lcd_str(unsigned char *ptr)
{
while(*ptr!='\0')
{
lcd_data(*ptr);
ptr++;
}
}

void lcd_num(unsigned int num)
{
if(num)
{
lcd_num(num/10);
lcd_data(num%10+0x30);	//ASCII of 0 is 30
}
}

void counter(unsigned int x)
{
    //unsigned int m;
	while(1)
	{
	lcd_num(x);
	delay(500);
	
	
	
	}
	 

}
void lcd_hex_num(unsigned int num)
{
	unsigned int rem;
    if(num)
    {
    lcd_hex_num(num/16);
       rem=(num%16);
           if(rem>9)
        {
        lcd_data(rem+0x37);
        }
              else
        {
        lcd_data(rem+0x30);
        }
    }
}