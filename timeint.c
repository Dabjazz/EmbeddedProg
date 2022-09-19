/*
   Generate an interrupt from timer0 for every 5 sec
   toggle LED P1.24 in the ISR Program
   Toggle LED P1.17 in main program
*/
#include<lpc21xx.h>
#include "lcd_fun.c"
void timer_config(void);
void Timer_Int_Config(void);
void toggle(unsigned int t);
void Timer_Int_Config(void);
void Timer_IRQ_Handler(void)__irq;
void Timer_Int_Config1(void);
void Timer_IRQ_Handler1(void)__irq;
void Timer_ExtInt_Config(void);
void Timer_ExtIRQ_Handler(void)__irq;
int main()
{
   IODIR1 |=(0xFF<<17);
   IODIR0 |= (0x1<<11);
   lcd_config();
   timer_config();
   Timer_Int_Config();
   Timer_Int_Config1();
   Timer_ExtInt_Config();
   while(1)
   {  
      IOSET1=(1<<17);
      delay(500);
      IOCLR1=(1<<17);
      delay(500); 
   }
}
void timer_config(void)
{
   T0PR=14;
   T1PR=14;
   T0MR0=5000000;
   T1MR0=17000000;
   T0MCR=(1<<1)|(1<<0);//Or we can directly give 3      MR0 in rep and Int mode
   T1MCR=(1<<1)|(1<<0);
   T0TCR=(1<<1); //clear counter
   T1TCR=(1<<1);
   T0TCR=(1<<0);//enable timer
   T1TCR=(1<<0);
}
void toggle(unsigned int t)
{
   IOSET1=(1<<t);
   delay(500);
   IOCLR1=(1<<t);
   delay(500);
}
void Timer_Int_Config(void)      //Timer0 IRQ Src num -->4
{
   VICIntSelect &=~(1<<4);//Config timer0 as irq
   VICVectCntl0=(1<<5)|(4<<0);//GIE=1, Source No
   VICVectAddr0=(long)Timer_IRQ_Handler;//Load ISR Address
   VICIntEnable=(1<<4); // Enable timer0 Int
}
void Timer_IRQ_Handler(void)__irq
{
   IOSET0=1<<11;
   delay(100);
      //clear port pin
   IOCLR0=1<<11;
   delay(100); 
   T0IR=(1<<0);//clear int flag
   VICVectAddr=0;//std return address 
   
}
void Timer_Int_Config1(void)     //Timer0 IRQ Src num -->4
{
   VICIntSelect &=~(1<<5);//Config timer0 as irq
   VICVectCntl1=(1<<5)|(5<<0);//GIE=1, Source No
   VICVectAddr1=(long)Timer_IRQ_Handler1;//Load ISR Address
   VICIntEnable=(1<<5); // Enable timer0 Int
}
void Timer_IRQ_Handler1(void)__irq
{
   IOSET1=(0x0F<<21);
   delay(500);
   IOCLR1=(0xF<<21);
   delay(500); 
   T1IR=(1<<0);//clear int flag
   VICVectAddr=0;//std return address 
   
}
void Timer_ExtInt_Config(void)      //Timer0 IRQ Src num -->4
{
   PINSEL0 |=(1<<29);
   PINSEL0 &=~(1<<28);
   VICIntSelect &=~(1<<15);//Config timer0 as irq
   VICVectCntl2=(1<<5)|(15<<0);//GIE=1, Source No
   VICVectAddr2=(long)Timer_ExtIRQ_Handler;//Load ISR Address
   VICIntEnable=(1<<15); // Enable timer0 Int
   EXTMODE =(1<<1);
   EXTPOLAR=(1<<1);

}
void Timer_ExtIRQ_Handler(void)__irq
{
    unsigned char a[]="Intr frm Timer";
   lcd_cmd(0x80);
   lcd_str(a);
   delay(1000);
   lcd_cmd(0x01);
      EXTINT=(1<<1);//clear int flag
   VICVectAddr=0;//std return address 
}

