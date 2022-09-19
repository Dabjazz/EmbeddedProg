
#include<lpc21xx.h>
#include<ctype.h>
#define RS  (1<<10)
#define RW   (1<<12)
#define EN	  (1<<13)
#define DATA  (0xFF<<15)  //Mask P0.15 to P0.22
void lcd_config(void);
void lcd_cmd(unsigned char c);
void lcd_data( unsigned char d);
void delay(unsigned int a);
void lcd_str(unsigned char *ptr);
void lcd_num(unsigned int num);
void counter(unsigned int x);