/* Rows- p1.21 to p1.24
cols- p1.17 to p1.20*/

#include <lpc21xx.h>
#include "lcd_fun.c"

#define ROWS (0X0F<<21)
#define COLS (0x0f<<17)

int main(){
return 0;

}

void row_scan(void){
IODIR1|=COLS;		//cols as OP port
IODIR&=~(ROWS);//Rows as Input Port

val=(IOPIN1&ROWS);//Read the status of row and store
val=val>>21;// to get as LSB 
/*Check the pattern*/
switch(val){
case 0x0E:lcd_str("R1");
delay(1000);
break;
case 0x0D:lcd_str("R2");
delay(1000);
break;
case 0x0B:lcd_str("R3");
delay(1000);
break;
case 0x07:lcd_str("R4");
delay(1000);
break;
default: lcd_cmd(0x01);
}
}