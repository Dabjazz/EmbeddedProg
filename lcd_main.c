


#include<lpc21xx.h>
#include"lcd_fun.c"
int main()
{
lcd_config();
lcd_str("BOSCH");
lcd_cmd(0XC0);
lcd_str("Invented for life");
while(1)
{
lcd_cmd(0x18);
 delay(200);
 //lcd_cmd(0x1C);
 //delay(600);
 }
}