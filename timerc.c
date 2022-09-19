// Design time in capture mode, Capture the timer value if events occurs on CAP0.0-- P0.30



/*Toggle LED P1.17 for every 5  seconds using timer0,MR0 MR1*/
#include<lpc21xx.h>
#include "lcd_fun.c"
void timer_config(void);
void toggle(unsigned int t);
void timer_cap_config(void);
unsigned int val;
int main()
{
   unsigned int i=1,m=0;
   IODIR1 |= (0xFF<<17);
   IODIR0=(0x1<<11);
   lcd_config();
   timer_cap_config();
   while(1)
   {
         if(T0IR &(1<<0))
         {
         	toggle(17);
         	T0IR=1;
            //toggle(17);
         //    lcd_cmd(0x01);
         //    lcd_cmd(0x83);
         //    lcd_num(i);
         //    i++;
         //    if(i==60)
         //    {
         //       i=1;
         //       m++;
         //    }
         //    lcd_cmd(0x82);
         //    lcd_data(':');
         //    lcd_cmd(0x80);
         //    lcd_num(m);
         //    T0IR=(1<<0);
         //    //clear int MR0 Flag
         // }
   }         	val=T0CR0;
         	lcd_num(val);
         	delay(1000);
         	lcd_cmd(0x01);

}	 }
void timer_cap_config(void)
{
	/*Config P0.30 AS CAP0.0*/
	PINSEL1|=(1<<29)|(1<<28);
   T0PR=14;
   T0MR0=1000000;
   T0MCR=(1<<1)|(1<<0);//Or we can directly give 3      MR0 in rep and Int mode
   T0CCR=(1<<0);
   T0TCR=(1<<1); //clear counter
   T0TCR=(1<<0);//enable timer

}
void toggle(unsigned int t)
{
   IOSET1=(1<<t);
   delay(500);
   IOCLR1=(1<<t);
   delay(500);
}