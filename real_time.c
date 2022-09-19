#include<lpc21xx.h>
#include "lcd_fun.c"
void rtc(void);
int main()
{
  IODIR1 |=(0xFF<<17);
  lcd_config();
  rtc();
  while(1)
  {
    lcd_cmd(0x80);
    lcd_num(DOY);
    lcd_data('-');
    lcd_num(MONTH);
    lcd_data('-');
    lcd_num(YEAR);
    lcd_cmd(0xC0);
    lcd_num(HOUR);
    lcd_data(':');
    lcd_num(MIN);
    lcd_data(':');
    lcd_num(SEC);
  }
}
void rtc(void)
{
  CCR=(1<<0);
  DOY=16;
  MONTH=9;
  YEAR=2022;
  SEC=20;
  MIN=15;
  HOUR=4;
  PREINT=456;
  PREFRAC=25024;
    
}
