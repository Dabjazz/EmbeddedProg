/*Toggle LED P1.17 for every 5  seconds using timer0,MR0 MR1*/
#include<lpc21xx.h>
#include "lcd_fun.c"
void timer_config(void);
void toggle(unsigned int t);
int main()
{
   unsigned int i=1,m=0;
   IODIR1 |= (0xFF<<17);
   IODIR0=(0x1<<11);
   lcd_config();
   timer_config();
   while(1)
   {
         if(T0IR &(1<<0))
         {
            //toggle(17);
            lcd_cmd(0x01);
            lcd_cmd(0x83);
            lcd_num(i);
            i++;
            if(i==60)
            {
               i=1;
               m++;
            }
            lcd_cmd(0x82);
            lcd_data(':');
            lcd_cmd(0x80);
            lcd_num(m);
            T0IR=(1<<0);
            //clear int MR0 Flag
         }
   }
}
void timer_config(void)
{
   T0PR=14;
   T0MR0=1000000;
   T0MCR=(1<<1)|(1<<0);//Or we can directly give 3      MR0 in rep and Int mode
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